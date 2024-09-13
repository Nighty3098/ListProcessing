#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      dataProcessor(new DataProcessor(this)) {
  ui->setupUi(this);

    dataProcessor->createConnection(ui->filePathLbl->text());
  connect(dataProcessor, &DataProcessor::dataProcessed, this,
          &MainWindow::updateOutput);
}

MainWindow::~MainWindow() {
  delete ui;
  delete dataProcessor;
}

void MainWindow::saveDataToFile(QTextBrowser *textEdit, QWidget *parent) {
  QString data = textEdit->toPlainText();
  if (data.isEmpty()) {
    QMessageBox::warning(parent, "Ошибка", "Поле для ввода данных пустое.");
    return;
  }

  QString directory = QFileDialog::getSaveFileName(
      parent, "Выберите папку для сохранения файла");
  if (directory.isEmpty()) {
    return;
  }

  QFile file(directory);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QMessageBox::warning(parent, "Ошибка",
                         "Не удалось открыть файл для записи.");
    return;
  }

  QTextStream out(&file);
  out << data;
  file.close();

  QMessageBox::information(parent, "Успех", "Данные успешно сохранены в файл.");
}

void MainWindow::on_openFileBtn_clicked() {
  filePath =
      QFileDialog::getOpenFileName(this, "Open File", "", "Files (*.db)");
  if (!filePath.isEmpty()) {
    ui->filePathLbl->setText(filePath);
  }
}

void MainWindow::on_saveDataBtn_clicked() {
  saveDataToFile(ui->outputText, this);
}

void MainWindow::on_startProcessBtn_clicked() {
    QThread *dbThread = new QThread;
    QObject::connect(dbThread, &QThread::started, this, [this]() {
        QString dataPath = ui->filePathLbl->text();
        if (!dataPath.isEmpty()) {
            int mode = ui->actionBox->currentIndex();
            dataProcessor->processFile(filePath, mode);
            ui->tabWidget->setCurrentIndex(2);
        } else {
            QMessageBox::information(this, "!!!", "Сначала откройте файл");
        }
    });
    QObject::connect(dbThread, &QThread::finished, dbThread, &QObject::deleteLater);

    dbThread->start();
}

void MainWindow::updateOutput(const QString &output) {
  ui->outputText->setText(output);
}

bool MainWindow::validateCoordinates(const QString &objPos, double &x, double &y) {
    QStringList posParts = objPos.split(" ");
    if (posParts.size() != 2) {
        showWarning("Координаты должны содержать два значения.");
        return false;
    }

    bool xOk, yOk;
    x = posParts[0].toDouble(&xOk);
    y = posParts[1].toDouble(&yOk);
    if (!xOk || !yOk) {
        showWarning("Координаты должны быть числами.");
        return false;
    }
    return true;
}

void MainWindow::showWarning(const QString &message) {
    QMessageBox::warning(this, "Ошибка", message);
}

void MainWindow::on_addDataBtn_clicked() {
    QString db_path = ui->filePathLbl->text();
    QString objName = ui->objNameData->text();
    QString objPos = ui->objPosData->text();
    QString objType = ui->objTypeData->text();
    QString objCT = ui->objCTData->text();

    if (objName.isEmpty()) {
        showWarning("Имя объекта не может быть пустым.");
        return;
    }

    double x, y;
    if (!validateCoordinates(objPos, x, y)) {
        return;
    }

    if (objType.isEmpty()) {
        showWarning("Тип объекта не может быть пустым.");
        return;
    }

    bool timeOk;
    double creationTime = objCT.toDouble(&timeOk);
    if (!timeOk) {
        showWarning("Время создания должно быть числом.");
        return;
    }

    dataProcessor->addNewData(objName, objPos, objType, objCT, db_path);

    int mode = ui->actionBox->currentIndex();
    dataProcessor->processFile(db_path, mode);
}
