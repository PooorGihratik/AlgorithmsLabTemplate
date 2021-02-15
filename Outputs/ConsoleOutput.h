//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_CONSOLEOUTPUT_H
#define ALGORITHMSLABTEMPLATE_CONSOLEOUTPUT_H
#include "IOutputListener.h"

class ConsoleOutput : public IOutputListener {
private:
    std::string name;
public:
    void setName(std::string name) override;
    void printValues(std::map<int, float> values) override;
};

#endif //ALGORITHMSLABTEMPLATE_CONSOLEOUTPUT_H
