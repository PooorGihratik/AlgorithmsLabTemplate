//
// Created by Кир on 16.02.2021.
//

#ifndef ALGORITHM_QUICKLIBSORT_H
#define ALGORITHM_QUICKLIBSORT_H
#include "IAlgorithm.h"
#include <algorithm>
#include <array>

template<typename T>
class QuickLibSort : public ISortAlgorithm<T> {
private:
    T* array;
    int count = 0;
private:
    static int compare(const void* a, const void* b) {
        if (*(T*)a < *(T*)b) return -1;
        if (*(T*)a == *(T*)b) return 0;
        if (*(T*)a > *(T*)b) return 1;
    }
public:
    void execute(T* arr, int N) override {
        array = arr;
        count = N;
        std::sort(arr,arr+N-1);
    }

    void sort(T* arr, int N) override {
        execute(arr,N);
    }

    bool isSorted() {
        for (int i =0;i<count-1;i++) {
            if (array[i] > array[i+1]) return false;
        }
        return true;
    }
};

#endif //ALGORITHM_QUICKLIBSORT_H
