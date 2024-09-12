#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dataProcessor(new DataProcessor(this)) {
    ui->setupUi(this);
    connect(dataProcessor, &DataProcessor::dataProcessed, this, &MainWindow::updateOutput);
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

    QString directory = QFileDialog::getSaveFileName(parent, "Выберите папку для сохранения файла");
    if (directory.isEmpty()) {
        return;
    }

    QFile file(directory);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(parent, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }

    QTextStream out(&file);
    out << data;
    file.close();

    QMessageBox::information(parent, "Успех", "Данные успешно сохранены в файл.");
}

void MainWindow::on_openFileBtn_clicked() {
    filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Files (*.db)");
    if (!filePath.isEmpty()) {
        ui->filePathLbl->setText(filePath);
    }
}

void MainWindow::on_saveDataBtn_clicked() {
    saveDataToFile(ui->outputText, this);
}

void MainWindow::on_startProcessBtn_clicked() {
    QString dataPath = ui->filePathLbl->text();
    if (!dataPath.isEmpty()) {
        int mode = ui->actionBox->currentIndex();
        dataProcessor->processFile(filePath, mode);
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::information(this, "!!!", "Сначала откройте файл");
    }
}

void MainWindow::updateOutput(const QString &output) {
    ui->outputText->setText(output);
}

void MainWindow::on_addDataBtn_clicked() {
    QString dataPath = ui->filePathLbl->text();

    if (!dataPath.isEmpty()) {
        QFile file(dataPath);

        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::warning(this, "Ошибка", "Файл не доступен для записи");
            qDebug() << "Cannot open file for writing:" << dataPath;
            return;
        }

        QTextStream out(&file);
        out << ui->objNameData->text() << " "
            << ui->objPosData->text() << " "
            << ui->objTypeData->text() << " "
            << ui->objCTData->text() << "\n";
        file.close();

        QMessageBox::information(this, "Успех", "Данные записаны");
    } else {
        QMessageBox::information(this, "Ошибка", "Сначала откройте файл");
    }
}
