#include "ListGraphs.h"
#include "fstream"
#include "climits"

ListGraphs::Node* ListGraphs::CreateNode(int v, int p) {
        Node* newNode = new Node;
        newNode->vertex = v;
        newNode->price = p;
        newNode->next = NULL;
        return newNode;
}

void ListGraphs::AddEdge(int src, int dest, int price) {
    Node* newNode = CreateNode(dest, price);

    newNode->next = adjLists->adjList[src];
    adjLists->adjList[src] = newNode;

    newNode = CreateNode(src, price);

    newNode->next = adjLists->adjList[dest];
    adjLists->adjList[dest] = newNode;
}

ListGraphs::ListGraphs() {
    finalPath = numVer = expenses = 0;
}

ListGraphs::~ListGraphs() {

    if (adjLists!=NULL) {

        for (int i = 0; i<numVer; ++i) {
            if (adjLists->adjList[i]!=NULL) {
                delete[] adjLists->adjList[i];
            }
        }

        delete[] adjLists;
    }
}

void ListGraphs::PrintGraph() {

    for (int v = 0; v < numVer; v++)
    {
        Node* temp = adjLists->adjList[v];
        std::cout << "Vertix: " << v+1 << '\n';

        while (temp)
        {
            std::cout << temp->vertex << " " << temp->price << " ";
            temp = temp->next;
        }

        std::cout << '\n';
    }

}

void ListGraphs::ReadFile(std::string filename) {

    std::ifstream file;

    file.open(filename.c_str());

    if (file.peek() == EOF) {
        file.close();
        throw std::string("File is empty");
    }

    file >> numVer;
    file >> finalPath;

    adjLists = new Graph;

    adjLists->numVert = numVer;
    adjLists->adjList = new Node*[numVer];

    for (int i = 0; i < numVer; ++i) {
        adjLists->adjList[i] = NULL;
    }

    for (int i = 0; i < numVer; ++i) {
        int tempVertexFrom;
        file >> tempVertexFrom;

        for (int j = 0; j < tempVertexFrom; ++j) {
            int tempVertexSrc, tempPrice;
            file >> tempVertexSrc;
            file >> tempPrice;
            AddEdge(i, tempVertexSrc, tempPrice);
        }
    }


    file.close();
}

bool ListGraphs::AlgorithmGraphs(const unsigned short startPosition) {
    if (adjLists == NULL) {
        Log(123);
        return false;
    }

    return true;
}

ListGraphs::MinHeapNode* ListGraphs::newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = new MinHeapNode;
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

ListGraphs::MinHeap* ListGraphs::createMinHeap(int capacity) {
    MinHeap* minHeap = new MinHeap;
    minHeap->pos = new int[capacity];

    minHeap->size = 0;
    minHeap->capacity = capacity;

    minHeap->array = new MinHeapNode*[capacity];
    return minHeap;
}

void ListGraphs::swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void ListGraphs::minHeapify(MinHeap* minHeap, int idx) {
    int smallest, left, right;

    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist ) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist ) {
        smallest = right;
    }

    if (smallest != idx)
    {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int ListGraphs::isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

ListGraphs::MinHeapNode* ListGraphs::extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) {
        return NULL;
    }

    MinHeapNode* root = minHeap->array[0];

    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = (minHeap->size--)-1;
    minHeap->pos[lastNode->v] = 0;

    minHeapify(minHeap, 0);
    return root;
}

void ListGraphs::decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];

    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

bool ListGraphs::isInMinHeap(MinHeap *minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size) {
        return true;
    }

    return false;
}

uint32_t ListGraphs::Dijkstra(int src) {
    int V = adjLists->numVert;
    int dist[V];

    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v,dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = V;
    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        Node* pCrawl = adjLists->adjList[u]->next;
        while (pCrawl != NULL) {
            int v = pCrawl->vertex;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->price + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->price;
                decreaseKey(minHeap, v, dist[v]);
            }

            pCrawl = pCrawl->next;
        }
    }

    return dist[numVer-2];
}

uint32_t ListGraphs::PriceDijkstra() {
    uint32_t summa = 0;

    for (int i = 1; i <= numVer; ++i) {
        summa += Dijkstra(i);
    }

    return summa*2;
}