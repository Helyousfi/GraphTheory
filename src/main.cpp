#include <iostream>
#include "../include/graph/graph.hpp"
#include "../include/graph/adjacency_matrix_graph.hpp"
#include "../GraphLibrary/Utils/debug.hpp"

int main()
{
    GraphLibrary::AdjacencyMatrixGraph* graph 
        = new GraphLibrary::AdjacencyMatrixGraph(6);
    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(2, 4);
    graph->addEdge(1, 4);
    graph->addEdge(3, 5);
    graph->addEdge(3, 4);

#ifdef DEBUG
    debugGraph(graph);
#endif

    return 0;
}