#pragma once

#include "Container.h"

class MatrixGraphs final:
        public Container{

public:
    MatrixGraphs();
    ~MatrixGraphs();

    void PrintGraph();

    bool ReadFile(std::string filename);
    bool AlgorithmGraphs();

private:
    unsigned int** graph;
};