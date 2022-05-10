//
// Created by rskullw on 09.05.22.
//

#include "MatrixGraphs.h"
#include "fstream"
#include "string"
#include "climits"

int MatrixGraphs::MinDist(unsigned int* dist, bool*ok)
{
    int min=INT_MAX;
    int index;

    for(int i=0;i<numVer;i++) {
        if (ok[i] == false && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

MatrixGraphs::MatrixGraphs() {
    numVer = finalPath = expenses = 0;
}

MatrixGraphs::~MatrixGraphs() {
    if (adjMatrix != nullptr) {
        for (int i = 0; i < numVer; ++i) {
            delete [] adjMatrix[i];
        }

        delete [] adjMatrix;
    }

}

void MatrixGraphs::ReadFile(std::string filename) {

    int temp = 0, tempVert = 0, tempPrice = 0;
    std::ifstream file;

    file.open(filename.c_str());

    if (file.peek() == EOF) {
        file.close();
        throw std::string("File is empty");
    }

    file >> numVer;
    file >> finalPath;

    adjMatrix = new unsigned int*[numVer];

    for (int i = 0; i < numVer; ++i) {
        adjMatrix[i] = new unsigned int[numVer];
        for (int j = 0; j < numVer; ++j) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < numVer; ++i) {
        file >> temp;
        for (int j = 0; j < temp; ++j) {
            file >> tempVert;
            file >> tempPrice;

            adjMatrix[i][tempVert-1] = tempPrice;
        }
    }
}

uint32_t MatrixGraphs::Dijkstra(int src) {

    auto* dist = new unsigned[numVer];
    auto* okVert = new bool[numVer];

    int j = 0;

    for (int i = 0; i<numVer; ++i) {
        dist[i] = INT_MAX;
        okVert[i] = false;
    }

    dist[src-1] = 0;

    for(int i = 0; i<numVer; i++) {
        j = MinDist(dist, okVert); // vertex not yet included.

        okVert[j]=true;// m with minimum distance included in Tset.

        for(int k = 0; k<numVer; k++)
        {
            // Updating the minimum distance for the particular node.
            if(!okVert[k] && adjMatrix[j][k] && dist[j]!=INT_MAX && dist[j]+ adjMatrix[j][k]<dist[k])
                dist[k]=dist[j]+adjMatrix[j][k];

        }
    }

    delete [] okVert;
    delete [] dist;

    return dist[numVer-1];
}

void MatrixGraphs::PrintGraph() {
    for (int i = 0; i < numVer; ++i) {
        std::cout << '\n';
        std::cout << i+1 << "| ";
        for (int j = 0; j < numVer; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
    }

    std::cout << '\n';}

bool MatrixGraphs::AlgorithmGraphs(const unsigned short startPosition) {
    std::cout << "sd";
    return true;
}

uint32_t MatrixGraphs::PriceDijkstra() {
    uint32_t summa = 0;

    for (int i = 1; i <= numVer; ++i) {
        summa += Dijkstra(i);
    }

    return summa;
}