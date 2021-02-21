//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_SUMALGORITHM_H
#define ALGORITHMSLABTEMPLATE_SUMALGORITHM_H
#include "IAlgorithm.h"

template<typename T>
class SumAlgorithm : public IAlgorithm<T> {
public:
    void execute(T* arr, int N) override {
        T sum = 0;
        for (int i = 0; i<N;i++) {
            sum += arr[i];
        }
    }
};

#endif //ALGORITHMSLABTEMPLATE_SUMALGORITHM_H
