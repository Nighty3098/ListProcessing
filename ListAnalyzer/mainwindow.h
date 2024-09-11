#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMap>
#include "object.h"
#include "dataprocessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openFileBtn_clicked();
    void on_saveDataBtn_clicked();
    void on_startProcessBtn_clicked();
    void updateOutput(const QString &output);

private:
    Ui::MainWindow *ui;
    QString filePath;
    DataProcessor *dataProcessor;
};

#endif // MAINWINDOW_H
