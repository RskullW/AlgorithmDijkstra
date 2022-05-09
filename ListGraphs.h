#pragma once

#include "Container.h"

class ListGraphs final:
        public Container {
public:
    ListGraphs();
    ~ListGraphs();

    bool ReadFile(std::string filename);
    bool AlgorithmGraphs();

private:
    unsigned int** graph;
};