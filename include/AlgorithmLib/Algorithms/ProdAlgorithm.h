//
// Created by Кир on 10.02.2021.
//

#ifndef LAB2_PRODALGORITHM_H
#define LAB2_PRODALGORITHM_H
#include "IAlgorithm.h"

template<typename T>
class ProdAlgorithm : public IAlgorithm<T> {
public:
    void execute(T* arr, int N) override {
        T prod = 1;
        for (int i = 0; i<N;i++) {
            prod *= arr[i];
        }
    }
};

#endif //LAB2_PRODALGORITHM_H