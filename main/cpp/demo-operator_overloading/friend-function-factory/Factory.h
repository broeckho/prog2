//
// Created by thomas on 13/11/2016.
//

#ifndef PROJECT_FACTORY_H
#define PROJECT_FACTORY_H

#include <vector>

class Object;

class Factory
{
public:
        Object operator()(); // Maakt een Object aan.
private:
        std::vector<int> createdObjectIds; // Houdt ID's van gegenereerde objecten bij.
};

#endif // PROJECT_FACTORY_H
