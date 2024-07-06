#include <iostream>
#include "graph.hpp"


int main()
{
    AdjacencyMatrixGraph* graph = new AdjacencyMatrixGraph(4);
    graph->printMatrix();
    return 0;
}