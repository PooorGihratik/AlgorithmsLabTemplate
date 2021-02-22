//
// Created by Кир on 22.02.2021.
//

#ifndef ALGORITHMS_SEARCHLIB_H
#define ALGORITHMS_SEARCHLIB_H
#include "IAlgorithm.h"
#include <algorithm>

template<typename T>
class SearchLib : public IAlgorithm<T> {
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
        auto iter = std::find(arr, arr+N, searchItem);
        if (iter == arr+N+1) return -1;
        return std::distance(arr, iter);
    }
};

#endif //ALGORITHMS_SEARCHLIB_H
