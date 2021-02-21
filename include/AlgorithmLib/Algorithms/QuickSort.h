//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H
#include "IAlgorithm.h"
#include <iostream>

template<typename T>
class QuickSort : public ISortAlgorithm<T> {
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
    void quickSort(int first, int last) {
        if (first >= last) return;
        int point = partition(first,last);
        quickSort(first,point);
        quickSort(point + 1,last);
        if (showProcess) printArray();
    }
    int partition(int first, int last) {
        int index = (first+last)/2;
        T pivot = array[index];
        int pt1 = first;
        int pt2 = last;
        while(true) {
            while(array[pt1] < pivot)
                pt1++;
            while(array[pt2] > pivot)
                pt2--;
            if (pt1 >= pt2) return pt2;
            swap(pt1++, pt2--);
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
    }
public:
    void setShowState(bool state) { showProcess = state; }
    void setShowIndex(bool state) { hasIndex = state; }
public:
    void execute(T* arr, int N) override {
        array = arr;
        count = N;
        if (hasIndex)  {
            delete[] indexArray;
            generateIndexes();
        }
        quickSort(0,N-1);
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

#endif //ALGORITHM_QUICKSORT_H
