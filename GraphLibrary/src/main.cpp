#include <iostream>

#include "../include/graph/graph.hpp"
#include "../include/graph/adjacency_matrix_graph.hpp"
#include "../include/algorithms/traversal/traversal_algorithms.hpp"
#include "../include/algorithms/shortest_path/shortest_path_algorithms.hpp"
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
    // GraphPlotter::visualizeGraph(graph->getEdges());
#endif
    TraversalAlgorithms::BFS(*graph, 0);
    auto topSort = TopologicalSort::topologicalSort(*graph);

    std::vector<int> belmanFord = ShortestPathAlgorithms::bellmanFord(*graph, 0);
#ifdef DEBUG
    debugContainer("belmanFord : ", belmanFord);
#endif // DEBUG


    return 0;
}