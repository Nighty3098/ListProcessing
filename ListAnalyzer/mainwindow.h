#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMap>
#include "object.h"
#include "dataprocessor.h"
#include <QTextBrowser>

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

    void on_addDataBtn_clicked();
    void saveDataToFile(QTextBrowser *textEdit, QWidget *parent);
    void showWarning(const QString &message);
    bool validateCoordinates(const QString &objPos, double &x, double &y);

private:
    Ui::MainWindow *ui;
    QString filePath;
    DataProcessor *dataProcessor;
};

#endif // MAINWINDOW_H
