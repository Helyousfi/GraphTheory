#include <iostream>
#include "../GraphFramework/graph.hpp"
#include "../GraphFramework/adjacency_matrix_graph.hpp"

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

#ifndef DEBUG
    debugGraph(graph);
    // GraphPlotter::visualizeGraph(graph->getEdges());

    TraversalAlgorithms::BFS(*graph, 0);
    auto topSort = TopologicalSort::topologicalSort(*graph);

    std::vector<int> belmanFord = ShortestPathAlgorithms::bellmanFord(*graph, 0);

    debugContainer("belmanFord : ", belmanFord);
#endif // DEBUG


    return 0;
}