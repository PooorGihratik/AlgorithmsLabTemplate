//
// Created by Кир on 16.02.2021.
//

#include "Vector2f.h"
#include <iostream>

bool Vector2f::operator>(Vector2f vector) const {
    return getLength() > vector.getLength();
}

bool Vector2f::operator<(Vector2f vector) const {
    return getLength() < vector.getLength();
}

bool Vector2f::operator>=(Vector2f vector) const {
    return getLength() >= vector.getLength();
}

bool Vector2f::operator<=(Vector2f vector) const {
    return getLength() <= vector.getLength();
}

bool Vector2f::operator==(Vector2f vector) const {
    return getLength() == vector.getLength();
}

std::ostream &operator<<(std::ostream& stream, Vector2f vector) {
    stream << "X: " << vector.x << ", Y: " << vector.y << ";";
}
