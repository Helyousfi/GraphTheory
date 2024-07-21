#ifndef EXCLUDE_THIS_FILE
#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/algorithms/topological_sort.hpp"
#include "../include/graph/adjacency_matrix_graph.hpp"

namespace GraphLibrary
{
    /**
     * Performs topological sorting on the given graph and returns the sorted order of vertices.
     * The graph is represented using an adjacency matrix.
     *
     * @param graph The graph represented as an AdjacencyMatrixGraph object.
     * @return A vector of integers representing the topological order of the vertices.
     */
    std::vector<int> TopologicalSort::topologicalSort(const AdjacencyMatrixGraph& graph)
    {
        int N = graph.getNumVertices(); // Number of nodes
        std::vector<bool> visited(N, false);    // Initialize visited with false
        std::vector<int> ordering;   // Vector to store the topological order

        for (int node = 0; node < N; node++)
        {
            if (!visited[node])
            {
                std::vector<int> visitedNodes;  // Store nodes visited in this DFS traversal
                DFSUtil(node, graph, visited, visitedNodes);
                if (!visitedNodes.empty())
                {
                    ordering.insert(ordering.end(), visitedNodes.begin(), visitedNodes.end());
                }
            }
        }
        std::reverse(ordering.begin(), ordering.end());
        return ordering;
    }

    // Utility function for DFS
    void TopologicalSort::DFSUtil(int node,
        const AdjacencyMatrixGraph& graph,
        std::vector<bool>& visited,
        std::vector<int>& visitedNodes)
    {
        visited[node] = true;
        visitedNodes.push_back(node);

        int** matrix = graph.getMatrix();
        int numVertices = graph.getNumVertices();

        for (int i = 0; i < numVertices; ++i) {
            if (matrix[node][i] != 0 && !visited[i]) {
                DFSUtil(i, graph, visited, visitedNodes);
            }
        }
    }
}

#else
#endif