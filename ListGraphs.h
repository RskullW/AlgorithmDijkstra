#pragma once

#include "Container.h"

class ListGraphs final:
        public Container {
// Structure of the adjacency list
private:
    struct Node {
        int vertex;
        int price;
        Node* next;
    };

    struct Graph {
        int numVert;
        Node** adjList;
    };
private:
    struct MinHeapNode
    {
        int v;
        int dist;
    };

    struct MinHeap
    {
        int size;
        int capacity;
        int *pos;
        MinHeapNode **array;
    };

public:
    explicit ListGraphs();
    ~ListGraphs();

    void PrintGraph();
    uint32_t Dijkstra(int src);
    uint32_t PriceDijkstra();

    void ReadFile(std::string filename);
    bool AlgorithmGraphs(const unsigned short startPosition);
private:
    Node* CreateNode(int v, int p);
    void AddEdge(int src, int dest, int price);

    void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
    void minHeapify(MinHeap* minHeap, int idx);
    void decreaseKey(MinHeap* minHeap, int v, int dist);
    bool isInMinHeap(MinHeap *minHeap, int v);
    int isEmpty(MinHeap* minHeap);
    MinHeapNode* newMinHeapNode(int v, int dist);
    MinHeap* createMinHeap(int capacity);
    MinHeapNode* extractMin(MinHeap* minHeap);


private:
    Graph* adjLists;
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