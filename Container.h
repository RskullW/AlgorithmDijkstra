#pragma once

#include <iostream>
#include <string>

class Container {

public:
    explicit Container() = default;
    virtual ~Container() {};

    virtual void PrintGraph() = 0;
    virtual void ReadFile(std::string filename) = 0;
    virtual bool AlgorithmGraphs(const unsigned short startPosition) = 0;

    virtual uint32_t Dijkstra(int src) = 0;
    virtual uint32_t PriceDijkstra() = 0;
public:
    template<typename T> void Log(T userText) {
        std::cout << "LOG: " << userText << '\n';
    }

protected:
    unsigned short finalPath, numVer;

    unsigned int expenses;
};




















