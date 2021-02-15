//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_RANDOMREALGENERATOR_H
#define ALGORITHMSLABTEMPLATE_RANDOMREALGENERATOR_H
#include "IGenerator.h"
#include <random>

template <typename T>
class RandomRealGenerator : public IGenerator<T> {
public:
    T* getValues(int N) override {
        T* array = new T[N];
        std::random_device random_device;
        std::mt19937 generator(random_device());

        std::uniform_real_distribution<T> distribution(1,30);

        for (int i=0; i<N; i++) {
            array[i] = distribution(generator);
        }
        return array;
    }
};

#endif //ALGORITHMSLABTEMPLATE_RANDOMREALGENERATOR_H
