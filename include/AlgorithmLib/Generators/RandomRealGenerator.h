//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_RANDOMREALGENERATOR_H
#define ALGORITHMSLABTEMPLATE_RANDOMREALGENERATOR_H
#include "IGenerator.h"
#include <random>

template <typename T>
class RandomRealGenerator : public IGenerator<T> {
private:
    std::random_device random_device;
    std::mt19937 generator;
public:
    RandomRealGenerator() {
        generator = std::mt19937(random_device());
    }
    T* getValues(int N) override {
        T* array = new T[N];

        std::uniform_real_distribution<T> distribution(1,100);

        for (int i=0; i<N; i++) {
            array[i] = distribution(generator);
        }
        return array;
    }
};

#endif //ALGORITHMSLABTEMPLATE_RANDOMREALGENERATOR_H
