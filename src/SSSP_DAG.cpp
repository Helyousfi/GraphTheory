// Function to find shortest paths from the source to all vertices
#include<vector>
#include<map>
#include<iostream>
#include <limits>
#include "graph.hpp"
#include "graphAlgorithms.hpp"


std::vector<int> shortestPath(AdjacencyMatrixGraph& graph, int source) {
    std::vector<int> sorted = TopologicalSort(graph);
    
    // Number of vertices in the graph
    int V = graph.getNumVertices();

    // Initialize distances to all vertices as infinite except for the source
    std::vector<int> distance(V, std::numeric_limits<int>::max());
    distance[source] = 0;

    for(int u : sorted)
    {
        int* neighbors = graph.getMatrix()[u];
        // Update distances of all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (neighbors[v] && neighbors[v] + distance[u] < distance[v] ) {
                distance[v] = neighbors[v] + distance[u];
            }
        }
    }
    return distance;
}