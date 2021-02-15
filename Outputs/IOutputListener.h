//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_IOUTPUTLISTENER_H
#define ALGORITHMSLABTEMPLATE_IOUTPUTLISTENER_H
#include <map>

class IOutputListener {
public:
    virtual void setName(std::string name) = 0;
    virtual void printValues(std::map<int, float> values) = 0;
};

#endif //ALGORITHMSLABTEMPLATE_IOUTPUTLISTENER_H
