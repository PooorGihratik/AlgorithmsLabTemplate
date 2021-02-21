//
// Created by Кир on 21.02.2021.
//

#ifndef ALGORITHMS_SEARCHGENERATOR_H
#define ALGORITHMS_SEARCHGENERATOR_H
#include "IGenerator.h"
#include "../Abstractions.h"
#include <algorithm>

template<typename T>
class SearchGenerator : public IGenerator<T> {
private:
    IGenerator<T>* generator;
    ISortAlgorithm<T>* sortingAlgorithm = nullptr;
    T searchItem;
public:
    SearchGenerator(IGenerator<T>* generator) : generator(generator) {}
    void setSearchItem(T item) { searchItem = item; }
    void setSortAlgorithm(ISortAlgorithm<T>* sort) { sortingAlgorithm = sort; }
    T* getValues(int N) override {
        T* array = new T[N];
        T* arrPart = generator->getValues(N-1);
        std::copy(arrPart,&arrPart[N-2],array);
        delete[] arrPart;
        array[N-1] = searchItem;
        if (sortingAlgorithm != nullptr) sortingAlgorithm->sort(array,N);
        return array;
    }
};

#endif //ALGORITHMS_SEARCHGENERATOR_H
