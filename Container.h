#pragma once

#include <iostream>
#include <string>

class Container {

public:
    explicit Container() = default;
    ~Container() {
        if (expenses!= nullptr) {
            delete[]expenses;
        }
    }

    virtual void PrintGraph() = 0;

    virtual bool ReadFile(std::string filename) = 0;
    virtual bool AlgorithmGraphs() = 0;

public:
    template<typename T> void Log(T userText) {
        std::cout << "LOG: " << userText << '\n';
    }

protected:
    unsigned short finalPath, numVer;
    unsigned int* expenses;
};