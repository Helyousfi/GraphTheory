#include <iostream>
#include "graph.hpp"

// Constructor to initialize the graph with n vertices
AdjacencyMatrixGraph::AdjacencyMatrixGraph(int n) {
    numVertices = n;
    // Initialize the adjacency matrix with all zeros (no edges initially)
    matrix = new int*[n]; // Allocates an array of n pointers to int (rows of the matrix).
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        // Initialize all elements to zero
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    // Free memory for each row
    for (int i = 0; i < numVertices; ++i) {
        delete matrix[i];
    }
    // Free memory for the array of pointers
    delete[] matrix;
}

// Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
void AdjacencyMatrixGraph::addEdge(int u, int v, int w) {
    // Assuming vertices are 0-indexed
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        matrix[u][v] = w;
        // Uncomment the following line if the graph is undirected
        matrix[v][u] = w;
    } else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
    }
}

// Function to add an edge from vertex u to vertex v (for unweighted graphs)
void AdjacencyMatrixGraph::addEdge(int u, int v) {
    addEdge(u, v, 1); // Default weight is 1 for unweighted graphs
}

// Function to remove an edge from vertex u to vertex v
void AdjacencyMatrixGraph::removeEdge(int u, int v) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        matrix[u][v] = 0;
        // Uncomment the following line if the graph is undirected
        // matrix[v][u] = 0;
    } else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
    }
}

// Function to check if there is an edge from vertex u to vertex v
bool AdjacencyMatrixGraph::hasEdge(int u, int v) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        return matrix[u][v] != 0;
    } else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
        return false;
    }
}

// Function to print the adjacency matrix (for debugging purposes)
void AdjacencyMatrixGraph::printMatrix() {
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
