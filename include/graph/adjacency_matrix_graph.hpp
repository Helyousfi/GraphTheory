// adjacency_matrix_graph.cpp
// 
// Implementation of the AdjacencyMatrixGraph class, which represents a graph using an adjacency matrix.
// This class provides methods to add, remove, and check edges, as well as to manipulate and query the graph.
// 
// The AdjacencyMatrixGraph class includes:
// - A constructor to initialize the graph with a given number of vertices.
// - A destructor to properly release dynamically allocated memory.
// - Methods to add and remove edges, check for edge existence, and print the adjacency matrix.
// - Additional utility functions such as multiplying the matrix by -1 for specific algorithms.
//
// This implementation is part of a graph library designed to offer efficient graph operations and algorithms.
// Given the performance requirements, this library is implemented in C++ for better speed and efficiency compared to higher-level languages like Python.

#ifndef ADJACENCY_MATRIX_GRAPH_DEFENITION_H
#define ADJACENCY_MATRIX_GRAPH_DEFENITION_H

#include "vector"
#include "graph.hpp"
// Adjacency Matrix representation of a graph
class AdjacencyMatrixGraph : public Graph {
private: 
    int **matrix;  // 2D array to store the adjacency matrix
    int numVertices;  // Number of vertices in the graph

public:
    // Constructor to initialize the graph with n vertices
    AdjacencyMatrixGraph(int n);

    // Destructor to free dynamically allocated memory
    ~AdjacencyMatrixGraph();

    // Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
    void addEdge(int u, int v, int w);

    // Function to add an edge from vertex u to vertex v (for unweighted graphs)
    void addEdge(int u, int v);

    // Function to remove an edge from vertex u to vertex v
    void removeEdge(int u, int v);

    // Function to check if there is an edge from vertex u to vertex v
    bool hasEdge(int u, int v) const;

    // Function to print the graph
    void printMatrix() const;

    // Getter for the number of vertices
    int getNumVertices() const;

    int getEdgeWeight(int node1, int node2) const;

    // Getter for the adjacency matrix
    int** getMatrix() const;

    // Getter for the neighbor
    int* getNeighbors(int vertex) const;

    // Function to multiply the matrix by -1 : useful for SSSP_DAG longest path
    void multiplyByMinusOne();
};
#endif // ADJACENCY_MATRIX_GRAPH_DEFENITION_H