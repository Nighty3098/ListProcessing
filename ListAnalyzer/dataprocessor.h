#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QString>
#include "object.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class DataProcessor : public QObject {
    Q_OBJECT

public:
    explicit DataProcessor(QObject *parent = nullptr);
    void processFile(const QString &filePath, int mode);
    void saveOutputData(const QString &filePath);

signals:
    void dataProcessed(const QString &output);

private:
    QVector<Object> readObjectsFromFile(const QString &filePath);
    QString formatOutput(const QMap<QString, QVector<Object>> &groupedObjects) const;

    QMap<QString, QVector<Object>> groupByDistance(const QVector<Object> &objects, double referenceX = 0, double referenceY = 0);
    QMap<QString, QVector<Object>> groupByName(const QVector<Object> &objects);
    QMap<QString, QVector<Object>> groupByType(const QVector<Object> &objects, int minObjectsPerGroup = 2);
    QMap<QString, QVector<Object>> groupByCreationTime(const QVector<Object> &objects);
};

#endif // DATAPROCESSOR_H
