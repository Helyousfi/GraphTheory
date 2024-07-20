#ifdef EXCLUDE_THIS_FILE
#include<iostream>
#include<vector>
#include <algorithm>
#include "graph.hpp"
#include "graphAlgorithms.hpp"

std::vector<int> TopologicalSort(const AdjacencyMatrixGraph& graph)
{
    int N = graph.getNumVertices(); // Number of nodes
    std::vector<bool> visited(N, false);    // Initialized with zeros
    std::vector<int> ordering(N, 0);   // Initialized with zeros

    for(int node=0; node < N; node++)
    {
        if(!visited[node])
        {
            std::vector<int> visitedNodes;
            DFSUtil(node, graph, visited, &visitedNodes);
            if(!visitedNodes.empty())
            {
                for(int nodeId : visitedNodes)
                {
                    ordering.push_back(nodeId);
                }
            }
        }
    }
    std::reverse(ordering.begin(), ordering.end());
    return ordering;
}
#else
#endif