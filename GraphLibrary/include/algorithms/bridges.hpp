#pragma once
#ifndef BRIDGES_FINDER_ALGORITHM_
#define BRIDGES_FINDER_ALGORITHM_

#include <vector>
#include <algorithm>
#include "../graph/graph.hpp"

namespace GraphLibrary {
    class EdgesFinder {
    public:
        // Static method to find edges on the given graph
        static std::vector<int> findBridges(const Graph& graph);

    private:
        // Utility function for DFS traversal
        static void DFSUtil(int node,
            const Graph& graph,
            std::vector<bool>& visited,
            std::vector<int>& visitedNodes);
    };
};
#endif // BRIDGES_FINDER_ALGORITHM_
