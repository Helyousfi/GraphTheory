#include <iostream>
#include "graph.hpp"
#include "vector"

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

    // graph->printMatrix();

    auto ordering = TopologicalSort(*graph);
    int i{};
    while(ordering[i])
    {
        std::cout << ordering[i] << std::endl;
        i++;
    }
    // std::cout << "BFS Algorithms" << std::endl;
    // BFS(*graph, 0);
    return 0;
}