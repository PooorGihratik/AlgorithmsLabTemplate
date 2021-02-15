//
// Created by Кир on 15.02.2021.
//

#ifndef ALGORITHMSLABTEMPLATE_IGENERATOR_H
#define ALGORITHMSLABTEMPLATE_IGENERATOR_H

template <typename T>
class IGenerator {
public:
    virtual T* getValues(int N) = 0;
};

#endif //ALGORITHMSLABTEMPLATE_IGENERATOR_H
