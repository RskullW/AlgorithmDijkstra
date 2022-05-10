#pragma once

#include "Container.h"

class MatrixGraphs final:
        public Container{

public:
    MatrixGraphs();
    ~MatrixGraphs();

    uint32_t Dijkstra(int src);
    uint32_t PriceDijkstra();

    void PrintGraph();
    void ReadFile(std::string filename);
    bool AlgorithmGraphs(const unsigned short startPosition);

private:
    int MinDist(unsigned int* dist, bool*Tset);
private:
    unsigned int** adjMatrix;
};