//
// Created by Кир on 17.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_TXTFILEOUTPUT_H
#define ALGORITHMSLABTEMPLATE_TXTFILEOUTPUT_H
#include "IOutputListener.h"

class TXTFileOutput : public IOutputListener {
private:
    std::string name;
    std::string directory;
public:
    TXTFileOutput();
    void setName(std::string name) override;
    void printValues(std::map<int, float> values) override;
};

#endif //ALGORITHMSLABTEMPLATE_TXTFILEOUTPUT_H
