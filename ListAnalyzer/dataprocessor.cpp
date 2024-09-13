#include "dataprocessor.h"
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QRegularExpression>
#include <QTextStream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <algorithm>

DataProcessor::DataProcessor(QObject *parent) : QObject(parent) {}

bool DataProcessor::createConnection(const QString &path) {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "qt_sql_default_connection");
    db.setDatabaseName(path);

    if (!db.open()) {
        qWarning() << "Cannot open database:" << db.lastError().text();
        return false;
    }

    QSqlQuery createTableQuery(db);
    if (!createTableQuery.exec(
            "CREATE TABLE IF NOT EXISTS objects ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "coordinate_x REAL NOT NULL, "
            "coordinate_y REAL NOT NULL, "
            "object_type TEXT NOT NULL, "
            "creation_time REAL NOT NULL"
            ")")) {
        qWarning() << "Failed to create table:" << createTableQuery.lastError().text();
        return false;
    }

    return true;
}

void DataProcessor::processFile(const QString &filePath, int mode) {
    if (!createConnection(filePath)) {
        return;
    }

    QVector<Object> objects = readObjectsFromDatabase();
    QMap<QString, QVector<Object>> groupedObjects;

    double referenceX = 0;
    double referenceY = 0;

    switch (mode) {
    case 0:
        groupedObjects = groupByDistance(objects, referenceX, referenceY);
        break;
    case 1:
        groupedObjects = groupByName(objects);
        break;
    case 2:
        groupedObjects = groupByType(objects, 1);
        break;
    case 3:
        groupedObjects = groupByCreationTime(objects);
        break;
    default:
        return;
    }

    QString output = formatOutput(groupedObjects);
    emit dataProcessed(output);
}

QVector<Object> DataProcessor::readObjectsFromDatabase() {
    QVector<Object> objects;
    QSqlQuery query(QSqlDatabase::database("qt_sql_default_connection"));

    if (!query.exec("SELECT * FROM objects")) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
        return objects;
    }

    while (query.next()) {
        objects.append(Object(query.value(1).toString(), query.value(2).toDouble(),
                              query.value(3).toDouble(), query.value(4).toString(),
                              query.value(5).toDouble()));
    }

    return objects;
}

QMap<QString, QVector<Object>> DataProcessor::groupByDistance(const QVector<Object> &objects, double referenceX, double referenceY) {
    QMap<QString, QVector<Object>> distanceGroups;

    for (const Object &obj : objects) {
        double distance = obj.distanceFrom(referenceX, referenceY);
        QString group;
        if (distance < 100) {
            group = "До 100 ед";
        } else if (distance < 1000) {
            group = "До 1000 ед";
        } else if (distance < 10000) {
            group = "До 10000 ед";
        } else {
            group = "Слишком далеко";
        }
        distanceGroups[group].append(obj);
    }

    for (auto &group : distanceGroups) {
        std::sort(group.begin(), group.end(),
                  [&](const Object &a, const Object &b) {
                      return a.distanceFrom(referenceX, referenceY) <
                             b.distanceFrom(referenceX, referenceY);
                  });
    }

    return distanceGroups;
}

QMap<QString, QVector<Object>> DataProcessor::groupByName(const QVector<Object> &objects) {
    QMap<QString, QVector<Object>> nameGroups;
    QRegularExpression russianLetterRegex("[А-Яа-я]");

    for (const Object &obj : objects) {
        QString firstChar = obj.name.left(1).toUpper();
        if (!russianLetterRegex.match(firstChar).hasMatch()) {
            firstChar = "#";
        }
        nameGroups[firstChar].append(obj);
    }

    for (auto &group : nameGroups) {
        std::sort(group.begin(), group.end(),
                  [](const Object &a, const Object &b) { return a.name < b.name; });
    }

    return nameGroups;
}

QMap<QString, QVector<Object>> DataProcessor::groupByType(const QVector<Object> &objects, int minObjectsPerGroup) {
    QMap<QString, QVector<Object>> typeGroups;

    for (const Object &obj : objects) {
        typeGroups[obj.type].append(obj);
    }

    QMap<QString, QVector<Object>> resultGroups;

    for (auto it = typeGroups.begin(); it != typeGroups.end(); ++it) {
        if (it.value().size() >= minObjectsPerGroup) {
            resultGroups[it.key()] = it.value();
        } else {
            resultGroups["Разное"].append(it.value());
        }
    }

    for (auto &group : resultGroups) {
        std::sort(group.begin(), group.end(),
                  [](const Object &a, const Object &b) { return a.name < b.name; });
    }

    return resultGroups;
}

QMap<QString, QVector<Object>> DataProcessor::groupByCreationTime(const QVector<Object> &objects) {
    QMap<QString, QVector<Object>> timeGroups;
    QDateTime now = QDateTime::currentDateTime();

    for (const Object &obj : objects) {
        QDateTime creationTime = QDateTime::fromMSecsSinceEpoch(static_cast<qint64>(obj.creationTime * 1000));
        int daysDiff = creationTime.date().daysTo(now.date());

        QString group;
        if (daysDiff == 0) {
            group = "Сегодня";
        } else if (daysDiff == 1) {
            group = "Завтра";
        } else if (daysDiff <= 6) {
            group = "На этой неделе";
        } else if (creationTime.date().month() == now.date().month() && creationTime.date().year() == now.date().year()) {
            group = "В этом месяце";
        } else if (creationTime.date().year() == now.date().year()) {
            group = "В этом году";
        } else {
            group = "Ранее";
        }
        timeGroups[group].append(obj);
    }

    for (auto &group : timeGroups) {
        std::sort(group.begin(), group.end(), [](const Object &a, const Object &b) {
            return a.creationTime < b.creationTime;
        });
    }

    return timeGroups;
}

QString DataProcessor::formatOutput(const QMap<QString, QVector<Object>> &groupedObjects) const {
    QString output;
    for (const auto &group : groupedObjects.keys()) {
        output += group + ":\n";
        for (const auto &obj : groupedObjects[group]) {
            output += "  " + obj.name + "\n";
        }
        output += "\n";
    }
    return output;
}

void DataProcessor::saveOutputData(const QString &filePath) {
    QVector<Object> objects = readObjectsFromDatabase();

    QMap<QString, QVector<Object>> groupedObjects = groupByName(objects);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file for writing:" << filePath;
        return;
    }

    QTextStream out(&file);
    out << formatOutput(groupedObjects);
    file.close();
}

void DataProcessor::addNewData(const QString &name, const QString &cords, const QString &obj_type, const QString &create_time, const QString &DBpath) {
    if (!createConnection(DBpath)) {
        qWarning() << "Cannot create database connection.";
        return;
    }

    QStringList parts = cords.split(" ");
    if (parts.size() < 2) {
        qWarning() << "Invalid coordinates format.";
        return;
    }

    QSqlQuery query(QSqlDatabase::database("qt_sql_default_connection"));
    query.prepare("INSERT INTO objects (name, coordinate_x, coordinate_y, object_type, creation_time) "
                  "VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(parts[0].toDouble());
    query.addBindValue(parts[1].toDouble());
    query.addBindValue(obj_type);
    query.addBindValue(create_time.toDouble());

    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
    }
}
