#include <iostream>
#include "graph.hpp"


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

    graph->printMatrix();

    // std::cout << "BFS Algorithms" << std::endl;
    // BFS(*graph, 0);
    return 0;
}