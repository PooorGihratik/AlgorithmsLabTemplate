//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_SQRALGORITHM_H
#define ALGORITHMSLABTEMPLATE_SQRALGORITHM_H
#include "IAlgorithm.h"

template<typename T>
class SqrAlgorithm : public IAlgorithm<T> {
public:
    void execute(T* arr, int N) override {
        T sqr = 1;
        for (int i = 0; i<N;i++) {
            sqr *= arr[i] * arr[i];
        }
    }
};

#endif //ALGORITHMSLABTEMPLATE_SQRALGORITHM_H
