// include/graph/graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>

namespace GraphLibrary{
    class Graph {
    public: 
        virtual ~Graph() {}

        virtual void addEdge(int node1, int node2, int weight = 1) = 0;
        virtual void removeEdge(int node1, int node2) = 0;

        virtual bool hasEdge(int node1, int node2) const = 0;

        virtual int* getNeighbors(int node) const = 0;
        virtual int getEdgeWeight(int node1, int node2) const = 0;
        virtual int** getMatrix() const = 0;
        virtual int getNumVertices() const = 0;
        virtual void printMatrix() const = 0;
        virtual void multiplyByMinusOne() = 0;
        // virtual int getNodeCount() const = 0;
        // virtual int getEdgeCount() const = 0;
    };
}
#endif // GRAPH_H
