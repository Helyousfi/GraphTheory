#include "adjacency_matrix_graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

void BFS(const AdjacencyMatrixGraph& graph, int startVertex) {
    int numVertices = graph.getNumVertices();
    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        int vertex = queue.front();
        std::cout << vertex << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        int** matrix = graph.getMatrix();
        for (int i = 0; i < numVertices; ++i) {
            if (matrix[vertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    std::cout << std::endl;
}
