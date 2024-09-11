#include "dataprocessor.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QRegularExpression>
#include <QDebug>
#include <algorithm>

DataProcessor::DataProcessor(QObject *parent) : QObject(parent) {}

void DataProcessor::processFile(const QString &filePath, int mode) {
    QVector<Object> objects = readObjectsFromFile(filePath);
    QMap<QString, QVector<Object>> groupedObjects;

    switch (mode) {
    case 0:
        groupedObjects = groupByDistance(objects);
        break;
    case 1:
        groupedObjects = groupByName(objects);
        break;
    case 2:
        groupedObjects = groupByType(objects);
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

QVector<Object> DataProcessor::readObjectsFromFile(const QString &filePath) {
    QVector<Object> objects;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << filePath;
        return objects;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');

        if (parts.size() < 5)
            continue;

        objects.append(Object(parts[0], parts[1].toDouble(), parts[2].toDouble(), parts[3], parts[4].toDouble()));
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
                      return a.distanceFrom(referenceX, referenceY) < b.distanceFrom(referenceX, referenceY);
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
            resultGroups["#"].append(it.value());
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
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file for writing:" << filePath;
        return;
    }

    QTextStream out(&file);
    out << "Output data goes here...\n";
    file.close();
}
