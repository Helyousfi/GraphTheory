#include <iostream>

#include "../include/graph/graph.hpp"
#include "../include/graph/adjacency_matrix_graph.hpp"
#include "../include/algorithms/traversal/traversal_algorithms.hpp"
#include "../include/algorithms/topological_sort.hpp"
#include "../../GraphLibrary/Utils/debug.hpp"
#include "../../GraphLibrary/Utils/graph_plotter.hpp"

int main()
{
    GraphLibrary::AdjacencyMatrixGraph* graph
        = new GraphLibrary::AdjacencyMatrixGraph(6, true);
    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(2, 4);
    graph->addEdge(1, 4);
    graph->addEdge(3, 5);
    graph->addEdge(3, 4);

#ifdef DEBUG
    debugGraph(graph);
    std::vector<std::pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {2, 4}, {1, 4}, {3, 5}, {3, 4}
    };
    GraphPlotter::visualizeGraphWithPython(edges);
#endif

    

    TraversalAlgorithms::BFS(*graph, 0);
    auto topSort = TopologicalSort::topologicalSort(*graph);

    return 0;
}