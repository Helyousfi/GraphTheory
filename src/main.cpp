#include <iostream>
#include "graph.hpp"


int main()
{
    AdjacencyMatrixGraph* graph = new AdjacencyMatrixGraph(4);
    graph->addEdge(1, 0);
    graph->addEdge(1, 2);
    graph->addEdge(2, 2);
    graph->addEdge(1, 3);
    graph->addEdge(3, 2);

    graph->printMatrix();

    std::cout << "BFS Algorithms" << std::endl;
    BFS(*graph, 0);
    return 0;
}