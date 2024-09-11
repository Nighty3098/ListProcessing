#ifndef OBJECT_H
#define OBJECT_H

#include <QString>

class Object {
public:
    Object(const QString &name, double x, double y, const QString &type, double creationTime);
    double distanceFrom(double x, double y) const;
    bool isValid() const;

    QString name;
    double x;
    double y;
    QString type;
    double creationTime;

private:
    bool valid;
};

#endif // OBJECT_H
