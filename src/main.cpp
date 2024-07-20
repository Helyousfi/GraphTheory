#include <iostream>
#include "../include/graph/adjacency_matrix_graph.hpp"

int main()
{
    AdjacencyMatrixGraph* graph = new AdjacencyMatrixGraph(6);
    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(2, 4);
    graph->addEdge(1, 4);
    graph->addEdge(3, 5);
    graph->addEdge(3, 4);

    return 0;
}