//
// Created by Кир on 21.02.2021.
//

#ifndef ALGORITHMS_LINEARSEARCH_H
#define ALGORITHMS_LINEARSEARCH_H
#include "IAlgorithm.h"

template<typename T>
class LinearSearch : public IAlgorithm<T> {
private:
    T searchItem;
public:
    void execute(T* arr, int N) override {
        findItem(arr,N,searchItem);
    }

    void setSearchItem(T item) {
        searchItem = item;
    }

    int findItem(T* arr, int N, T item) {
        for (int i = 0; i < N; i++) {
            if (arr[i] == item) return i;
        }
        return -1;
    }
};

#endif //ALGORITHMS_LINEARSEARCH_H
