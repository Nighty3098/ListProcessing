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

void MainWindow::on_addDataBtn_clicked() {
  QString db_path = ui->filePathLbl->text();

  QString objName = ui->objNameData->text();
  QString objPos = ui->objPosData->text();
  QString objType = ui->objTypeData->text();
  QString objCT = ui->objCTData->text();

  dataProcessor->addNewData(objName, objPos, objType, objCT, db_path);

  int mode = ui->actionBox->currentIndex();
  dataProcessor->processFile(filePath, mode);
}
