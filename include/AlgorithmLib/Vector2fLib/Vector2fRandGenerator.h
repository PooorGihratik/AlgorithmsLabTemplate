//
// Created by Кир on 16.02.2021.
//

#ifndef LAB3_VECTOR2FRANDGENERATOR_H
#define LAB3_VECTOR2FRANDGENERATOR_H
#include "../Generators/IGenerator.h"
#include "../Generators/RandomRealGenerator.h"
#include "Vector2f.h"

class Vector2fRandGenerator : public IGenerator<Vector2f> {
private:
    RandomRealGenerator<float> gen;
public:
    Vector2f * getValues(int N) override {
        Vector2f* array = new Vector2f[N];
        for (int i = 0; i < N; ++i) {
            float* a = gen.getValues(2);
            array[i] = Vector2f(a[0],a[1]);
            delete[] a;
        }
        return array;
    }
};

#endif //LAB3_VECTOR2FRANDGENERATOR_H
