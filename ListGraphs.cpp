#include "ListGraphs.h"
#include "fstream"

#define MAXIMUM 10000
ListGraphs::ListGraphs() {
    finalPath = numVer = 0;
}

ListGraphs::~ListGraphs() {

    if (adjLists!=NULL) {

        for (int i = 0; i<numVer; ++i) {
            if (adjLists[i].next!=NULL) {
                delete[] adjLists[i].next;
            }
        }

        delete[] adjLists;
    }
}

void ListGraphs::PrintGraph() {

    if (adjLists == NULL) {
        Log("Not initialization graph");
        return;
    }

    for (int i = 0; i < numVer; ++i) {
        std::cout << '\n' << adjLists[i].vertex+1 << ":";

        for (int j = 0; j < adjLists[i].numPathFromVer; ++j) {
            std:: cout << " " << adjLists[i].next[j].vertex << " " << adjLists[i].next[j].price;
        }
    }
}

bool ListGraphs::ReadFile(std::string filename) {
    uint32_t temp, tempVer, tempPrice;

    std::ifstream file;

    file.open(filename.c_str());

    if (file.peek() == EOF) {
        Log("File is empty");
        file.close();
        return false;
    }

    file >> numVer;
    file >> finalPath;

    expenses = new unsigned[numVer];

    adjLists = new Node[numVer];

    for (uint32_t i = 0; i < numVer; ++i) {
        adjLists[i].price = MAXIMUM;
        adjLists[i].vertex = (int)i;

        file >> adjLists[i].numPathFromVer;

        adjLists[i].next = new Node[adjLists[i].numPathFromVer];

        for (uint32_t j = 0; j < adjLists[i].numPathFromVer; ++j) {
            file >> tempVer;
            file >> tempPrice;

            adjLists[i].next[j].vertex = (int) tempVer;
            adjLists[i].next[j].price = (int) tempPrice;
        }
    }


    file.close();

    return true;
}

//bool ListGraphs::AlgorithmGraphs() {
//
//    if (adjLists == NULL) {
//        Log("Graph is empty");
//        return false;
//    }
//
//    for (int i = 0; )
//    return true;
//}