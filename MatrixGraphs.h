#pragma once

#include "Container.h"

class MatrixGraphs final:
        public Container{

public:
    MatrixGraphs();
    ~MatrixGraphs();

    bool ReadFile(std::string filename);
    bool AlgorithmGraphs();

private:
    unsigned int** graph;
};