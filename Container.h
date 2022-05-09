#pragma once

#include <iostream>
#include <string>

class Container {

public:
    explicit Container() = default;
    virtual ~Container() = 0;

    virtual bool ReadFile(std::string filename) = 0;
    virtual bool AlgorithmGraphs() = 0;

protected:
    short startingPath, finalPath;
    int expenses, allCosts;
};