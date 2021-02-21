//
// Created by Кир on 21.02.2021.
//

#ifndef ALGORITHMS_BINARYSEARCH_H
#define ALGORITHMS_BINARYSEARCH_H
#include "IAlgorithm.h"

template<typename T>
class BinarySearch : public IAlgorithm<T> {
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
        int first = 0;
        int last = N - 1;
        while(first <= last) {
            int middle = (first + last)/2;
            if (arr[middle] > item) last = middle-1;
            else if (arr[middle] < item) first = middle+1;
            else return middle;
        }
        return -1;
    }
};

#endif //ALGORITHMS_BINARYSEARCH_H
