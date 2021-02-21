//
// Created by Кир on 18.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_WORSTCASEGENERATOR_H
#define ALGORITHMSLABTEMPLATE_WORSTCASEGENERATOR_H
#include "IGenerator.h"
#include <iostream>

template <typename T>
class WorstCaseGenerator : public IGenerator<T> {;
public:
    T* getValues(int N) override {
        T* array = new T[N];
        array[N-1] = 0;
        array[0] = 0;
        int q = (N-1)/2;
        for (int i = 1;i<N;i++) {
            int index = q + (i/2) * ((i % 2) == 0 ? 1 : -1);
            array[index] = i;
        }
        return array;
    }
};
#endif //ALGORITHMSLABTEMPLATE_WORSTCASEGENERATOR_H
