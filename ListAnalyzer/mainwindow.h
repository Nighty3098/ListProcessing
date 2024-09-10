#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QDebug>
#include <cmath>

#include <QMainWindow>

struct Object {
    QString name;
    double x;
    double y;
    QString type;
    double creationTime;

    double distanceFrom(double x0, double y0) const {
        return std::sqrt(std::pow(x - x0, 2) + std::pow(y - y0, 2));
    }
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString filePath;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QVector<Object> readObjectsFromFile(const QString& filePath);

    void groupAndSortObjects(const QVector<Object>& objects, int mode);
    void on_openFileBtn_clicked();
    void on_saveDataBtn_clicked();
    void saveOutputData(QString savingFilePath);
    void on_startProcessBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
