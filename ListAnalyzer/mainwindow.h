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
#include <algorithm>

#include <QMainWindow>

struct Object {
    QString name;
    double x;
    double y;
    QString type;
    double creationTime;

    // Constructor for easy initialization
    Object(const QString& n = "", double xCoord = 0.0, double yCoord = 0.0, const QString& t = "", double time = 0.0)
        : name(n), x(xCoord), y(yCoord), type(t), creationTime(time) {}

    double distanceFrom(double referenceX, double referenceY) const {
        return std::sqrt(std::pow(x - referenceX, 2) + std::pow(y - referenceY, 2));
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
