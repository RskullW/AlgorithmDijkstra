#pragma once

#include "Container.h"

class ListGraphs final:
        public Container {
public:
    explicit ListGraphs();
    ~ListGraphs();

    void PrintGraph();

    bool ReadFile(std::string filename);
    bool AlgorithmGraphs();

// Structure of the adjacency list
private:
    struct Node {
        int price;
        int vertex;

        int numPathFromVer;
        Node* next;
    };
// List Graphs
private:
    Node* adjLists;
};
/*
 * 6 1 6
 * 2 2 5 3 8
 * 2 3 2 4 3
 * 2 4 4 5 4
 * 1 6 12
 * 1 6 13
 * 0
 */