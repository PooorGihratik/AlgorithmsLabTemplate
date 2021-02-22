//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_BUBBLESORT_H
#define ALGORITHMSLABTEMPLATE_BUBBLESORT_H
#include "IAlgorithm.h"
#include <iostream>

template<typename T>
class BubbleSort : public ISortAlgorithm<T> {
private:
    bool showProcess = false;
    bool hasIndex = false;
    T* array;
    int* indexArray = nullptr;
    int count=0;
private:
    void generateIndexes() {
        delete[] indexArray;
        indexArray = new int[count];
        for (int i = 0; i < count; i++) {
            indexArray[i] = i;
        }
    }
    void printArray() {
        if (hasIndex) {
            std::cout << "Current indexes: ";
            for (int i=0; i < count; i++) {
                std::cout << indexArray[i] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "Current array: ";
        for (int i=0; i < count; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n" << std::endl;
    };
    void swap(int pt1, int pt2) {
        T temp = array[pt1];
        array[pt1] = array[pt2];
        array[pt2] = temp;
        if (hasIndex) {
            int tempIn = indexArray[pt1];
            indexArray[pt1] = indexArray[pt2];
            indexArray[pt2] = tempIn;
        }
    }
public:
    void setShowState(bool state) { showProcess = state; }
    void setShowIndex(bool state) { hasIndex = state; }
public:
    void execute(T* arr, int N) override {
        array = arr;
        count = N;
        if (hasIndex) generateIndexes();
        int m = 0;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N - m - 1; k++ ) {
                if (arr[k] > arr[k+1]) swap(k, k+1);
            }
            if (showProcess) {
                printArray();
            }
        }
        delete[] indexArray;
    }

    bool isSorted() {
        for (int i =0;i<count-1;i++) {
            if (array[i] > array[i+1]) return false;
        }
        return true;
    }

    void sort(T* arr, int N) override {
        execute(arr,N);
    }
};

#endif //ALGORITHMSLABTEMPLATE_BUBBLESORT_H
