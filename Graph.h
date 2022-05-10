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

    void ReadFile(std::string filename) {
        container->ReadFile(filename);
    }

    uint32_t Dijkstra(int src) {
        return container->Dijkstra(src);
    }

    uint32_t PriceDijkstra() {
        return container->PriceDijkstra();
    }

    bool AlgorithmGraphs(const unsigned short startPosition) {
        return container->AlgorithmGraphs(startPosition);
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