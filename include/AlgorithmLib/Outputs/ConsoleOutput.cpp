//
// Created by Кир on 15.02.2021.
//

#include "ConsoleOutput.h"
#include <iostream>

using namespace std;

void ConsoleOutput::setName(std::string name) {
    this->name = name;
}

void ConsoleOutput::printValues(std::map<int, float> values) {
    cout << "\n";
    cout << name << ": \n";
    cout << "Count - time(in milliseconds)" << ": \n";
    for (auto val : values) {
        cout << val.first << " - " << val.second << " msec\n";
    }
    cout << "\n";
}
