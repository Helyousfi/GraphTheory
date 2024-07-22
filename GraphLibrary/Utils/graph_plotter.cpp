#include "pch.h"  // Include the precompiled header file
#include <Python.h>
#include <iostream>
#include <vector>
#include <string>
#include "graph_plotter.hpp"

/// <summary>
/// Visualize Graph With Python
/// </summary>
/// <param name="edges"></param>
void GraphPlotter::visualizeGraph(const std::vector<std::pair<int, int>>& edges) {
    Py_Initialize();

    std::string command = "python "
        "C:/Users/hamza/Documents/GraphTheory/GraphLibrary/Utils/visualize_graph.py";

    for (const auto& edge : edges) {
        command += " " + std::to_string(edge.first) + " " + std::to_string(edge.second);
    }

    // Execute the command
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error: Failed to execute Python script." << std::endl;
    }

    Py_Finalize();
}
