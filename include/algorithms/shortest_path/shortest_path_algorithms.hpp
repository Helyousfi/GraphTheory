#ifndef SHORTEST_PATH_ALGORITHMS_H
#define SHORTEST_PATH_ALGORITHMS_H

#include "../../graph/adjacency_matrix_graph.hpp"
#include <vector>

class ShortestPathAlgorithms {
public:
    static std::vector<int> bellmanFord(const AdjacencyMatrixGraph& graph, int source);
    static std::vector<int> dijkstra(const AdjacencyMatrixGraph& graph, int source);
};

#endif // SHORTEST_PATH_ALGORITHMS_H
