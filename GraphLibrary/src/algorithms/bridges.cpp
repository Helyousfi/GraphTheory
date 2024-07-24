#include "../../include/graph/graph.hpp"
#include "../../include/algorithms/bridges.hpp"
#include <iostream>
#include <queue>
#include <stack>

namespace GraphLibrary
{
    BridgesFinder::BridgesFinder(Graph *graph)
    {
        graph = graph;
        numVertices = graph->getNumVertices();
        ids = std::vector<int> (numVertices, 0);
        lows = std::vector<int>(numVertices, 0);
        visited = std::vector<bool>(numVertices, false);
    }
    std::vector<int> BridgesFinder::findBridges()
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (!visited[i])
            {
                DFSUtil(i, -1, bridges);
            }
        }
        return bridges;
    }
    
    void BridgesFinder::DFSUtil(int node,
        int parent,
        std::vector<int> bridges)
    {
        visited[node] = true;
        ids[node] = ids[node] + 1;
        lows[node] = ids[node];

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (graph->getMatrix()[node][neighbor] != 0) { 
                if (neighbor == parent)
                    continue;
                if(!visited[neighbor])
                {
                    DFSUtil(neighbor, node, bridges);
                }
            }
        }


    }
}