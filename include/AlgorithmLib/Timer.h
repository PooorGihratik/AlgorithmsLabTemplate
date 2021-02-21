//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_TIMER_H
#define ALGORITHMSLABTEMPLATE_TIMER_H
#include "Abstractions.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

template<class T>
class Timer {
private:
    IGenerator<T>* generator;
    IAlgorithm<T>* algorithm;
    std::vector<IOutputListener*> outputs;
    std::map<int,float> points;
    std::vector<int> measureSet;
    std::string name;
private:
    void printOutput() {
        for (auto output:outputs) {
            output->setName(name);
            output->printValues(points);
        }
    }

public:
    Timer(IGenerator<T>* generator, IAlgorithm<T>* algorithm, std::string name) : generator(generator), algorithm(algorithm), name(name) {
        measureSet = std::vector<int>{1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
    }

    void setGenerator(IGenerator<T>* generator) {
        if (generator != nullptr) this->generator = generator;
    }
    void setAlgorithm(IAlgorithm<T>* algorithm) {
        if (generator != nullptr) this->algorithm = algorithm;
    }
    void setName(std::string value) {
        if (!value.empty()) name = value;
    }
    void setMeasureSet(std::vector<int> set) {
        if (!set.empty()) measureSet = set;
    }

    void addOutputListener(IOutputListener* listener) {
        outputs.push_back(listener);
    }

    float measure(int N) {
        T* values = generator->getValues(N);
        using namespace std::chrono;
        steady_clock::time_point t1 = steady_clock::now();
        algorithm->execute(values,N);
        steady_clock::time_point t2 = steady_clock::now();
        microseconds workTime = duration_cast<microseconds>(t2 - t1);
        delete[] values;
        return (float)workTime.count()/1000;
    }

    void autoMeasureWithSet() {
        points.clear();
        for (auto value : measureSet) {
            float time = measure(value);
            points.emplace(value,time);
        }
        printOutput();
    }
};

#endif //ALGORITHMSLABTEMPLATE_TIMER_H
