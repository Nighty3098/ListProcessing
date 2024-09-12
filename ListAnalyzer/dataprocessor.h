#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QString>
#include "object.h"

class DataProcessor : public QObject {
    Q_OBJECT

public:
    explicit DataProcessor(QObject *parent = nullptr);
    bool createConnection(const QString &path);
    void processFile(const QString &filePath, int mode);
    QVector<Object> readObjectsFromDatabase();

    void addNewData(const QString &name, const QString &cords, const QString &obj_type, const QString &create_time, const QString &DBpath);

signals:
    void dataProcessed(const QString &output);

private:
    QVector<Object> readObjectsFromFile(const QString &filePath);
    QMap<QString, QVector<Object>> groupByDistance(const QVector<Object> &objects, double referenceX, double referenceY);
    QMap<QString, QVector<Object>> groupByName(const QVector<Object> &objects);
    QMap<QString, QVector<Object>> groupByType(const QVector<Object> &objects, int minObjectsPerGroup);
    QMap<QString, QVector<Object>> groupByCreationTime(const QVector<Object> &objects);
    QString formatOutput(const QMap<QString, QVector<Object>> &groupedObjects) const;
    void saveOutputData(const QString &filePath);
};

#endif // DATAPROCESSOR_H
