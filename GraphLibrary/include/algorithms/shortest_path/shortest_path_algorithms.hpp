#ifndef SHORTEST_PATH_ALGORITHMS_H
#define SHORTEST_PATH_ALGORITHMS_H

#include "../../graph/graph.hpp"
#include <vector>
namespace GraphLibrary
{
    class ShortestPathAlgorithms {
    public:
        static std::vector<int> bellmanFord(const Graph& graph, int source);
        static std::vector<int> dijkstra(const Graph& graph, int source);
        static std::vector<std::vector<int>> floydWarshal(const Graph& graph, int source);
    };
}


#endif // SHORTEST_PATH_ALGORITHMS_H
