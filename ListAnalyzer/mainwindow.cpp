#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileBtn_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        ui->filePathLbl->setText(filePath);
    }
}


void MainWindow::on_saveDataBtn_clicked()
{
    QString savingFilePath = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
    if (!savingFilePath.isEmpty()) {
        saveOutputData(savingFilePath);
    }
}

QVector<Object> MainWindow::readObjectsFromFile(const QString& filePath) {
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

        if (parts.size() < 5) continue; // Skip lines with insufficient data

        // Use emplace_back for efficiency
        objects.emplace_back(parts[0], parts[1].toDouble(), parts[2].toDouble(), parts[3], parts[4].toDouble());
    }

    return objects;
}

QMap<QString, QVector<Object>> groupByDistance(const QVector<Object>& objects, double referenceX = 0, double referenceY = 0) {
    QMap<QString, QVector<Object>> distanceGroups;

    for (const Object& obj : objects) {
        double distance = obj.distanceFrom(referenceX, referenceY);
        if (distance < 100) {
            distanceGroups["До 100 ед"].append(obj);
        } else if (distance < 1000) {
            distanceGroups["До 1000 ед"].append(obj);
        } else if (distance < 10000) {
            distanceGroups["До 10000 ед"].append(obj);
        } else {
            distanceGroups["Слишком далеко"].append(obj);
        }
    }

    return distanceGroups;
}

QMap<QString, QVector<Object>> groupByName(const QVector<Object>& objects) {
    QMap<QString, QVector<Object>> nameGroups;

    for (const Object& obj : objects) {
        QString firstChar = obj.name.left(1).toUpper();
        if (!firstChar[0].isLetter()) {
            firstChar = "#";
        }
        nameGroups[firstChar].append(obj);
    }

    // Sort groups by name
    for (auto& group : nameGroups) {
        std::sort(group.begin(), group.end(), [](const Object& a, const Object& b) {
            return a.name < b.name;
        });
    }

    return nameGroups;
}

QMap<QString, QVector<Object>> groupByType(const QVector<Object>& objects) {
    QMap<QString, QVector<Object>> typeGroups;

    for (const Object& obj : objects) {
        typeGroups[obj.type].append(obj);
    }

    QMap<QString, QVector<Object>> resultGroups;
    for (auto it = typeGroups.begin(); it != typeGroups.end(); ++it) {
        if (it.value().size() > 1) {
            resultGroups[it.key()] = it.value();
        } else {
            resultGroups["Разное"].append(it.value().first());
        }
    }

    return resultGroups;
}

QMap<QString, QVector<Object>> groupByCreationTime(const QVector<Object>& objects) {
    QMap<QString, QVector<Object>> timeGroups;
    QDateTime now = QDateTime::currentDateTime();

    for (const Object& obj : objects) {
        QDateTime creationTime = QDateTime::fromMSecsSinceEpoch(static_cast<qint64>(obj.creationTime * 1000));
        int daysDiff = creationTime.date().daysTo(now.date());

        if (daysDiff == 0) {
            timeGroups["Сегодня"].append(obj);
        } else if (daysDiff == -1) {
            timeGroups["Завтра"].append(obj);
        } else if (daysDiff <= 6 && daysDiff > 0) {
            timeGroups["На этой неделе"].append(obj);
        } else if (creationTime.date().month() == now.date().month() && creationTime.date().year() == now.date().year()) {
            timeGroups["В этом месяце"].append(obj);
        } else if (creationTime.date().year() == now.date().year()) {
            timeGroups["В этом году"].append(obj);
        } else {
            timeGroups["Ранее"].append(obj);
        }
    }

    return timeGroups;
}

void MainWindow::groupAndSortObjects(const QVector<Object>& objects, int mode) {
    ui->outputText->clear();
    QString output;

    // Store the groups in a variable to avoid multiple calls
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
        return; // Exit if mode is invalid
    }

    // Construct the output string
    for (const auto& group : groupedObjects.keys()) {
        output += group + ":\n";
        for (const auto& obj : groupedObjects[group]) {
            output += "  " + obj.name + "\n";
        }
        output += "\n";
    }

    ui->outputText->setText(output); // Set the output in the QTextBrowser
}

void MainWindow::saveOutputData(QString savingFilePath) {

}

// 0 - Группировка по расстоянию.
// 1 - Группировка по имени.
// 2 - Группировка по типу.
// 3 - Группировка по времени создания.
void MainWindow::on_startProcessBtn_clicked()
{
    int mode = ui->actionBox->currentIndex();
    QVector<Object> objects = readObjectsFromFile(filePath);
    groupAndSortObjects(objects, mode);
}
