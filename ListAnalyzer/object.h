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
    double creationTime; // In seconds since epoch

private:
    bool valid; // Indicates whether the object is valid
};

#endif // OBJECT_H
