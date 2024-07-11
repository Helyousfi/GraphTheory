#ifndef GRAPH_ALGORITHM_HPP
#define GRAPH_ALGORITHM_HPP

#include "graph.hpp"  // Include your graph definition header

// Function prototypes for graph algorithms

// Function to perform DFS starting from vertex v
void DFS(const AdjacencyMatrixGraph& graph, int startVertex);

// Function to perform DFSUtil
void DFSUtil(int v,
             const AdjacencyMatrixGraph& graph,
             std::vector<bool>& visited,
             std::vector<int>* visitedNodes = nullptr);

// Function to perform BFS starting from vertex v
void BFS(const AdjacencyMatrixGraph& graph, int startVertex);

// Function to perform Topological Sort on a Directed Acyclic Graph (DAG)
std::vector<int> TopologicalSort(const AdjacencyMatrixGraph& graph);

#endif // GRAPH_ALGORITHM_HPP
