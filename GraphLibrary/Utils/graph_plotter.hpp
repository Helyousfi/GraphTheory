#ifndef GRAPH_PLOTTER_HPP
#define GRAPH_PLOTTER_HPP

#include "../../include/graph/adjacency_matrix_graph.hpp"
#include "Matplotlib/matplotlib-cpp/matplotlibcpp.h"


namespace plt = matplotlibcpp;
using namespace GraphLibrary;

class GraphPlotter {
public:
    // Function to plot an adjacency matrix graph
    static void plot(AdjacencyMatrixGraph* graph);
};

#endif // GRAPH_PLOTTER_HPP
