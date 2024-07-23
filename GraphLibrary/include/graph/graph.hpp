// include/graph/graph.h
#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>

#define DEFAULT_WEIGHT 1

// Debug macro
#ifdef _DEBUG
#define DEBUG_LOG(msg) std::cout << "DEBUG: " << msg << std::endl;
#else
#define DEBUG_LOG(msg)
#endif

namespace GraphLibrary{
    class Graph {
        public: 
            virtual ~Graph() {}

            virtual void addEdge(int node1, int node2, int weight = DEFAULT_WEIGHT) = 0;
            virtual void removeEdge(int node1, int node2) = 0;

            virtual std::vector<std::pair<int, int>> getEdges() = 0;
            
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
