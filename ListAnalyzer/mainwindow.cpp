#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dataProcessor(new DataProcessor(this)) {
    ui->setupUi(this);
    connect(dataProcessor, &DataProcessor::dataProcessed, this, &MainWindow::updateOutput);
}

MainWindow::~MainWindow() {
    delete ui;
    delete dataProcessor;
}

void MainWindow::on_openFileBtn_clicked() {
    filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        ui->filePathLbl->setText(filePath);
    }
}

void MainWindow::on_saveDataBtn_clicked() {
    QString savingFilePath = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
    if (!savingFilePath.isEmpty()) {
        dataProcessor->saveOutputData(savingFilePath);
    }
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
            qWarning() << "Cannot open file for writing:" << dataPath;
            return;
        }

        QTextStream out(&file);
        out << ui->objNameData->text() << " "
            << ui->objPosData->text() << " "
            << ui->objTypeData->text() << " "
            << ui->objCTData->text() << "\n";
        file.close();

        QMessageBox::information(this, "!!!", "Данные записаны");
    }
    else {
        QMessageBox::information(this, "!!!", "Сначала откройте файл");
    }
}
