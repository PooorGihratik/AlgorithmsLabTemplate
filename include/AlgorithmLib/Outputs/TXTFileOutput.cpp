//
// Created by Кир on 17.02.2021.
//

#include "TXTFileOutput.h"
#include <fstream>

#define SavePath R"(D:\CLionProjects\Data\)"
#define Extension ".txt"

void TXTFileOutput::setName(std::string name) {
    this->name = name;
}

void TXTFileOutput::printValues(std::map<int, float> values) {
    std::ofstream file;
    file.open(SavePath + name + Extension);
    for (auto val : values) {
        file << val.first << " " << val.second << std::endl;
    }
}