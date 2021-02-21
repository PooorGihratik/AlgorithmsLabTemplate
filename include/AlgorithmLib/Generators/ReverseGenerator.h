//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_REVERSEGENERATOR_H
#define ALGORITHMSLABTEMPLATE_REVERSEGENERATOR_H
#include "IGenerator.h"

template<typename T>
class ReverseGenerator : public IGenerator<T> {
public:
    T* getValues(int N) override {
        T* array = new T[N];
        for (int i=0; i<N; i++) {
            array[i] = N - i;
        }
        return array;
    }
};

#endif //ALGORITHMSLABTEMPLATE_REVERSEGENERATOR_H
