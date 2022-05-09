#pragma once

#include "MatrixGraphs.h"
#include "ListGraphs.h"

template <class Container = MatrixGraphs> class Graph {

public:
    explicit Graph() = default;
    virtual ~Graph() = 0;

    bool ReadFile(std::string filename) {
        return container.ReadFile(filename);
    }
    bool AlgorithmGraphs() {
        return container.AlgorithmGraphs();
    }

private:
    Container container;
};