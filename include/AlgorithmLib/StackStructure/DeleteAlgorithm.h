//
// Created by Кир on 22.02.2021.
//

#ifndef ALGORITHMS_DELETEALGORITHM_H
#define ALGORITHMS_DELETEALGORITHM_H
#include "../Abstractions.h"
#include "Stack.h"

template<typename T>
class DeleteAlgorithm : public IAlgorithm<T> {
private:
    Stack<T>* workingStack;
    IGenerator<T>* generator;
public:
    DeleteAlgorithm(Stack<T>* stack, IGenerator<T>* generator) : workingStack(stack), generator(generator) {
        workingStack->clear();
    }
    void execute(T* arr, int N) override {
        for (int i = 0; i < N; i++) {
            workingStack->pop();
        }
    }

    void prepare(int N) override {
        T* array =  generator->getValues(N);
        for(int i = 0; i < N; i++) {
            workingStack->push(array[i]);
        }
        delete[] array;
    }
};

#endif //ALGORITHMS_DELETEALGORITHM_H
