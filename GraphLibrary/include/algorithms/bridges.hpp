#pragma once
#ifndef BRIDGES_FINDER_ALGORITHM_
#define BRIDGES_FINDER_ALGORITHM_

#include <vector>
#include <algorithm>
#include "../graph/graph.hpp"

namespace GraphLibrary {
    class BridgesFinder {
    public:
        BridgesFinder(Graph *graph);
        // Static method to find edges on the given graph
        std::vector<std::pair<int, int>> findBridges();

    private:
        Graph* graph;
        int numVertices;
        std::vector<int> ids; 
        std::vector<int> lows; 
        std::vector<bool> visited; 
        int idCounter; // Counter to track the discovery times

        // Utility function for DFS traversal
        void DFSUtil(int node,
            int parent,
            std::vector<std::pair<int, int>> bridges);
    };
};
#endif // BRIDGES_FINDER_ALGORITHM_
