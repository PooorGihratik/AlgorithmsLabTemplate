//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_TIMER_H
#define ALGORITHMSLABTEMPLATE_TIMER_H
#include "Abstractions.h"
#include <iostream>
#include <vector>
#include <ctime>

template<class T>
class Timer {
private:
    IGenerator<T>* generator;
    IAlgorithm<T>* algorithm;
    std::vector<IOutputListener*> outputs;
    std::map<int,float> points;
    std::vector<int> basicVal;
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
        basicVal.push_back(1000);
        basicVal.push_back(2000);
        basicVal.push_back(5000);
        basicVal.push_back(10000);
        basicVal.push_back(20000);
        basicVal.push_back(50000);
        basicVal.push_back(100000);
        basicVal.push_back(200000);
        basicVal.push_back(500000);
    }

    void setGenerator(IGenerator<T>* generator) { this->generator = generator; }
    void setAlgorithm(IAlgorithm<T>* algorithm) { this->algorithm = algorithm; }

    void addOutputListener(IOutputListener* listener) {
        outputs.push_back(listener);
    }

    float measure(int N) {
        T* values = generator->getValues(N);
        float initialTime = clock();
        algorithm->execute(values,N);
        float workTime = clock() - initialTime;
        return workTime;
    }

    void measureAndPrint() {
        points.clear();
        for (auto value : basicVal) {
            float time = measure(value);
            points.emplace(value,time);
        }
        printOutput();
    }
};

#endif //ALGORITHMSLABTEMPLATE_TIMER_H
