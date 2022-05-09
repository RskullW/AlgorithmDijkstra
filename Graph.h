#pragma once

#include "MatrixGraphs.h"
#include "ListGraphs.h"

template <class Container = MatrixGraphs> class Graph {

public:
    Graph() {
        container = new Container;
    };

    void PrintGraph() {
        container->PrintGraph();
    }
    bool ReadFile(std::string filename) {
        return container->ReadFile(filename);
    }

    bool AlgorithmGraphs() {
        return container->AlgorithmGraphs();
    }

    template<typename T> void Log(T userText) {
        container->Log(userText);
    }

    ~Graph() {
        delete container;
    }

private:
    Container* container;
};