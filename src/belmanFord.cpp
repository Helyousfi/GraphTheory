
#include <iostream>
#include <vector>
#include <climits>
#include "graph.h"

void bellmanFord(const AdjacencyMatrixGraph& graph, int source) {
    int V = graph.getNumVertices();
    int** adjMatrix = graph.getMatrix();
    std::vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] != INT_MAX && distance[u] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + adjMatrix[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (adjMatrix[u][v] != INT_MAX && distance[u] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v]) {
                std::cout << "Graph contains a negative-weight cycle" << std::endl;
                return;
            }
        }
    }

    // Print distances
    std::cout << "Vertex\tDistance from Source" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : std::to_string(distance[i])) << std::endl;
    }
}