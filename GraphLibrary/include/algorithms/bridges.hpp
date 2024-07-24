#pragma once
#ifndef BRIDGES_FINDER_ALGORITHM_
#define BRIDGES_FINDER_ALGORITHM_

#include <vector>
#include <algorithm>
#include "../graph/graph.hpp"

namespace GraphLibrary {
    class BridgesFinder {
    public:
        BridgesFinder(const Graph& graph);
        // Static method to find edges on the given graph
        std::vector<int> findBridges();

    private:
        int numVertices;
        std::vector<int> ids; 
        std::vector<int> lows; 
        std::vector<bool> visited; 

        std::vector<int> bridges;

        // Utility function for DFS traversal
        void DFSUtil(int node,
            int parent,
            std::vector<int> bridges);
    };
};
#endif // BRIDGES_FINDER_ALGORITHM_
