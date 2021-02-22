//
// Created by Кир on 22.02.2021.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H
#include <exception>
#include <iostream>

template<typename T>
class Stack {
private:
    struct TNode {
        T value;
        TNode* previous = nullptr;
    };
private:
    TNode* startPoint = nullptr;
    TNode* endPoint = nullptr;
    int size = 0;
public:
    Stack() = default;
    Stack(T* array, int N) : size(N) {
        for (int i = 0; i < N; ++i) {

        }
    }
    void pop() {
        if (startPoint == nullptr) return;
        auto* node = endPoint->previous;
        delete endPoint;
        endPoint = node;
        if (endPoint == nullptr) startPoint = nullptr;
        size--;
    }
    void push(T value) {
        auto* node = new TNode;
        node->value = value;
        if (startPoint == nullptr) {
            startPoint = node;
        }
        node->previous = endPoint;
        endPoint = node;
        size++;
    }
    T top() {
        if (endPoint != nullptr) return endPoint->value;
        else throw std::exception();
    }
    void print() {
        auto* pointer = endPoint;
        if (startPoint == nullptr) std::cout << "Structure is empty" << std::endl;
        else std::cout << "Current state of structure: \n(Mem address\tValue)\n";
        while (pointer != nullptr) {
            std::cout << pointer << "\t" << pointer->value << "\n";
            pointer = pointer->previous;
        }
    }
    void clear() {
        if (startPoint == nullptr) return;
        auto* pointer = endPoint;
        while (pointer != nullptr) {
            pointer = pointer->previous;
            pop();
        }
        size = 0;
    }
    int getSize() { return size; }
};

#endif //ALGORITHMS_STACK_H
