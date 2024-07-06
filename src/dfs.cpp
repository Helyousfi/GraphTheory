#include "graph.hpp"
#include <iostream>
#include <vector>

void DFSUtil(int v, const AdjacencyMatrixGraph& graph, std::vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    int** matrix = graph.getMatrix();
    int numVertices = graph.getNumVertices();
    for (int i = 0; i < numVertices; ++i) {
        if (matrix[v][i] != 0 && !visited[i]) {
            DFSUtil(i, graph, visited);
        }
    }
}

void DFS(const AdjacencyMatrixGraph& graph, int startVertex) {
    // Mark all the vertices as not visited
    std::vector<bool> visited(graph.getNumVertices(), false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(startVertex, graph, visited);
}
