#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include "../../../include/graph/adjacency_matrix_graph.hpp"
#include "../../../include/algorithms/shortest_path/shortest_path_algorithms.hpp"
/**
 * Implements the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices 
 * in a given weighted graph.
 * The graph is represented using an adjacency matrix.
 *
 * @param graph The graph represented as an AdjacencyMatrixGraph object.
 * @param source The starting vertex for the shortest path calculation.
 * @return A vector containing the shortest distance from the source to each vertex.
 */
std::vector<int> ShortestPathAlgorithms::bellmanFord(const AdjacencyMatrixGraph& graph, int source) {
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
                return std::vector<int>();
            }
        }
    }

    return distance;
}


/**
 * Implements Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices in a given weighted graph.
 * The graph is represented using an adjacency matrix.
 *
 * @param graph The graph represented as an AdjacencyMatrixGraph object.
 * @param source The starting vertex for the shortest path calculation.
 */
std::vector<int> ShortestPathAlgorithms::dijkstra(const AdjacencyMatrixGraph& graph, int source) {
    // Number of vertices in the graph
    int V = graph.getNumVertices();
    
    // Get the adjacency matrix of the graph
    int** adjMatrix = graph.getMatrix();
    
    // Initialize the distance vector with the maximum possible value (infinity) for all vertices
    // and set the distance to the source vertex to 0
    std::vector<int> distance(V, INT_MAX);
    distance[source] = 0;
    
    // Priority queue (implemented as a set of pairs) to store vertices and their distances
    // The pair contains the distance and the vertex
    std::set<std::pair<int, int>> pq;
    pq.insert({0, source});
    
    // Process the priority queue until it's empty
    while (!pq.empty()) {
        // Extract the vertex with the minimum distance from the source
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        
        // Traverse all adjacent vertices of the extracted vertex u
        for (int v = 0; v < V; ++v) {
            // If there is an edge from u to v
            if (adjMatrix[u][v] != INT_MAX) {
                // Perform the relaxation step
                if (distance[u] + adjMatrix[u][v] < distance[v]) {
                    // Update the distance of vertex v
                    pq.erase({distance[v], v}); // Remove the old distance if it exists
                    distance[v] = distance[u] + adjMatrix[u][v];
                    pq.insert({distance[v], v}); // Insert the new distance
                }
            }
        }
    }
    
    // Print the shortest distances from the source to all other vertices
    std::cout << "Vertex\tDistance from Source" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : std::to_string(distance[i])) << std::endl;
    }
    return distance;
}
