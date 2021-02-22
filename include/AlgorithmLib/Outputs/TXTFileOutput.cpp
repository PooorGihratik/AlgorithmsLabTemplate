//
// Created by Кир on 17.02.2021.
//

#include "TXTFileOutput.h"
#include <dir.h>
#include <fstream>
#include <sstream>

#define Extension ".txt"

void TXTFileOutput::setName(std::string name) {
    this->name = name;
}

void TXTFileOutput::printValues(std::map<int, float> values) {
    std::ofstream file;
    std::stringstream stream;
    stream << directory << name << Extension;
    std::string fileName;
    stream >> fileName;
    file.open(fileName);
    for (auto val : values) {
        file << val.first << " " << val.second << std::endl;
    }
}

TXTFileOutput::TXTFileOutput() {
    char dir[PATH_MAX];
    if (getcwd(dir,PATH_MAX) != NULL) {
        std::string result;
        std::stringstream stream;
        stream << dir << "\\FileData\\";
        stream >> result;
        mkdir(result.c_str());
        directory = result;
    }
}
