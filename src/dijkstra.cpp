#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include "graph.h"

void dijkstra(const AdjacencyMatrixGraph& graph, int source) {
    int V = graph.getNumVertices();
    int** adjMatrix = graph.getMatrix();
    std::vector<int> distance(V, INT_MAX); // Distance array to hold shortest path distances
    std::set<std::pair<int, int>> pq; // Priority queue to store vertices and their distances

    // Initialize distance to source vertex as 0
    distance[source] = 0;
    pq.insert({0, source});

    while (!pq.empty()) {
        // Extract the vertex with the minimum distance
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        // Traverse neighbors of u
        for (int v = 0; v < V; ++v) {
            // If there is an edge from u to v and v is not processed yet
            if (adjMatrix[u][v] != INT_MAX) {
                // Relaxation step
                if (distance[u] + adjMatrix[u][v] < distance[v]) {
                    // Update distance of v
                    pq.erase({distance[v], v});
                    distance[v] = distance[u] + adjMatrix[u][v];
                    pq.insert({distance[v], v});
                }
            }
        }
    }

    // Print shortest distances from source
    std::cout << "Vertex\tDistance from Source" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : std::to_string(distance[i])) << std::endl;
    }
}
