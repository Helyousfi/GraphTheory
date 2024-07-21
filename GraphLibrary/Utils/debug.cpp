#include "pch.h"  // Include the precompiled header file
#include "debug.hpp"
#include <iostream>
#include "../../include/graph/adjacency_matrix_graph.hpp"
using namespace GraphLibrary;

void debugGraph(const AdjacencyMatrixGraph* graph) {
    if (!graph) {
        std::cout << "Graph is null!" << std::endl;
        return;
    }

    std::cout << "Debugging Graph:" << std::endl;

    // Print the number of vertices
    std::cout << "Number of vertices: " << graph->getNumVertices() << std::endl;

    // Print the adjacency matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    graph->printMatrix();

    // Print edge weights and additional details if needed
    std::cout << "Edge weights:" << std::endl;
    for (int i = 0; i < graph->getNumVertices(); ++i) {
        for (int j = 0; j < graph->getNumVertices(); ++j) {
            int weight = graph->getEdgeWeight(i, j);
            if (weight != 0) {  // Assuming 0 means no edge
                std::cout << "Edge from " << i << " to " << j << " with weight " << weight << std::endl;
            }
        }
    }
}
