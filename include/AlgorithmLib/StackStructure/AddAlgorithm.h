//
// Created by Кир on 22.02.2021.
//

#ifndef ALGORITHMS_ADDALGORITHM_H
#define ALGORITHMS_ADDALGORITHM_H
#include "../Abstractions.h"
#include "Stack.h"

template<typename T>
class AddAlgorithm : public IAlgorithm<T> {
private:
    Stack<T>* workingStack;
public:
    AddAlgorithm(Stack<T>* stack) : workingStack(stack) {}
    void execute(T* arr, int N) override {
        for (int i = 0; i < N; i++) {
            workingStack->push(arr[i]);
        }
    }

    void end() override {
        workingStack->clear();
    }
};


#endif //ALGORITHMS_ADDALGORITHM_H
