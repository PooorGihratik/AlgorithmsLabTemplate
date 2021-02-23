//
// Created by Кир on 16.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_VECTOR2F_H
#define ALGORITHMSLABTEMPLATE_VECTOR2F_H
#include "../Generator.h"
#include <cmath>

class Vector2f {
private:
    float x = 0;
    float y = 0;
public:
    Vector2f() = default;
    Vector2f(float x, float y) : x(x), y(y) {};
    float getLength() const { return std::sqrt(x*x + y*y); }
    bool operator>(Vector2f vector) const;
    bool operator<(Vector2f vector2) const;
    bool operator>=(Vector2f vector) const;
    bool operator<=(Vector2f vector) const;
    bool operator==(Vector2f vector) const;
    friend std::ostream& operator<<(std::ostream& stream, Vector2f vector);
};


#endif //ALGORITHMSLABTEMPLATE_VECTOR2F_H
