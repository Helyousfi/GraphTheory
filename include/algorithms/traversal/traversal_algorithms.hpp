#ifndef TRAVERSAL_ALGORITHMS_H
#define TRAVERSAL_ALGORITHMS_H

#include "../../graph/adjacency_matrix_graph.hpp"
#include <vector>
using namespace GraphLibrary;

class TraversalAlgorithms {
public:
    // Perform Breadth-First Search (BFS) starting from the given vertex
    static void BFS(const AdjacencyMatrixGraph& graph, int startVertex);

    // Perform Depth-First Search (DFS) starting from the given vertex
    static void DFS(const AdjacencyMatrixGraph& graph, int startVertex);

private:
    // Helper function for DFS traversal
    static void DFSUtil(const AdjacencyMatrixGraph& graph, int vertex, std::vector<bool>& visited);
};

#endif // TRAVERSAL_ALGORITHMS_H
