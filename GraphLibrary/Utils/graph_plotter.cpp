#include "pch.h"  // Include the precompiled header file
#include "graph_plotter.hpp"
#include "../../include/graph/adjacency_matrix_graph.hpp"
using namespace GraphLibrary;

void GraphPlotter::plot(AdjacencyMatrixGraph* graph) {
    int numVertices = graph->getNumVertices();
    int** matrix = graph->getMatrix();

    // Prepare data for plotting
    std::vector<std::vector<int>> edges(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (matrix[i][j] != 0) {
                edges[i].push_back(j);
            }
        }
    }

    // Plot the graph
    for (int i = 0; i < numVertices; ++i) {
        for (int j : edges[i]) {
            plt::plot({ (double)i, (double)j }, { (double)i, (double)j }, "bo-");
        }
    }
    // plt::show();
}
