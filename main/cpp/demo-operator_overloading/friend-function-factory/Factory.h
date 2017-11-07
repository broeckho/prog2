#pragma once
#include <vector>

class Object;

class Factory
{
public:
        Object operator()(); // Maakt een Object aan.
private:
        std::vector<int> createdObjectIds; // Houdt ID's van gegenereerde objecten bij.
};
