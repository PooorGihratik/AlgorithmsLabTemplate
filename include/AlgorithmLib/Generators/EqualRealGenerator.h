//
// Created by Кир on 17.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_EQUALREALGENERATOR_H
#define ALGORITHMSLABTEMPLATE_EQUALREALGENERATOR_H
#include "RandomRealGenerator.h"
#include <map>

template <typename T>
class EqualRealGenerator : public IGenerator<T> {;
private:
    RandomRealGenerator<T> gen;
    std::map<int, T*> arrayMap;
private:
    T* copy(T* sub, int N) {
        T* result = new T[N];
        for (int i = 0; i < N; ++i) {
            result[i] = sub[i];
        }
        return result;
    }
public:
    T* getValues(int N) override {
        auto iter = arrayMap.find(N);
        if ( iter == arrayMap.end()) {
            T* array = gen.getValues(N);
            arrayMap.emplace(N,array);
            return copy(array,N);
        }
        else {
            return copy(iter->second,iter->first);
        }
    }
};

#endif //ALGORITHMSLABTEMPLATE_EQUALREALGENERATOR_H
