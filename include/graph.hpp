#ifndef GRAPH_DEFENITION
#define GRAPH_DEFENITION

#include "vector"

// Adjacency Matrix representation of a graph
class AdjacencyMatrixGraph {
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
    bool hasEdge(int u, int v);

    // Function to print the graph
    void printMatrix();

    // Getter for the number of vertices
    int getNumVertices() const;

    // Getter for the adjacency matrix
    int** getMatrix() const;

    // Getter for the neighbore
    int* getNeighbor(int vertex) const;
};
#endif 