//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_CONSTANTGENERATOR_H
#define ALGORITHMSLABTEMPLATE_CONSTANTGENERATOR_H
#include "IGenerator.h"

template <typename T>
class ConstantGenerator : public IGenerator<T> {
public:
    T* getValues(int N) override {
        T* array = new T[N];
        int con = 1;
        for (int i=0; i<N; i++) {
            array[i] = con;
        }
        return array;
    }
};

#endif //ALGORITHMSLABTEMPLATE_CONSTANTGENERATOR_H
