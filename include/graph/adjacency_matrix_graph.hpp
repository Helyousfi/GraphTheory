#ifndef ADJACENCY_MATRIX_GRAPH_DEFENITION_H
#define ADJACENCY_MATRIX_GRAPH_DEFENITION_H

#include "vector"
#include "graph.hpp"
// Adjacency Matrix representation of a graph
class AdjacencyMatrixGraph : Graph {
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
    void printMatrix();

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