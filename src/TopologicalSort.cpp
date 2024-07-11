#include<iostream>
#include<vector>
#include<graph.hpp>

int* TopologicalSort(const AdjacencyMatrixGraph& graph)
{
    int N = graph.getNumVertices(); // Number of nodes
    std::vector<bool> visited(N, false);    // Initialized with zeros
    int ordering[N] = {};   // Initialized with zeros
    int i = N - 1;

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
                    ordering[i] = nodeId;
                    i--;
                }
            }
        }
    }

    return ordering;
}
