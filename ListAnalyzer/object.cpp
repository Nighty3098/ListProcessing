#include "object.h"
#include <cmath>

Object::Object(const QString &name, double x, double y, const QString &type, double creationTime)
    : name(name), x(x), y(y), type(type), creationTime(creationTime), valid(true) {}

double Object::distanceFrom(double x, double y) const {
    return std::sqrt(std::pow(this->x - x, 2) + std::pow(this->y - y, 2));
}

bool Object::isValid() const {
    return valid;
}
