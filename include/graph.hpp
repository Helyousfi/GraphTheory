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
};

// Function to perform DFS starting from vertex v
void DFS(const AdjacencyMatrixGraph& graph, int startVertex);
void DFSUtil(int v, 
        const AdjacencyMatrixGraph& graph, 
        std::vector<bool>& visited,
        std::vector<int>* visitedNodes = nullptr);
// Function to perform BFS starting from vertex v
void BFS(const AdjacencyMatrixGraph& graph, int startVertex);
int* TopologicalSort(const AdjacencyMatrixGraph& graph);

/*
// Adjacency List representation of a graph
class AdjacencyListGraph {
private:
    // Structure to represent a node in the adjacency list
    struct Node {
        int dest;      // Destination vertex of the edge
        int weight;    // Weight of the edge (if weighted)
        Node* next;    // Pointer to the next node in the list
    };

    // Array of pointers to Nodes, one pointer for each vertex
    Node** adjList;
    int numVertices;    // Number of vertices in the graph

public:
    // Constructor to initialize the graph with n vertices
    AdjacencyListGraph(int n);

    // Destructor to free dynamically allocated memory
    ~AdjacencyListGraph();

    // Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
    void addEdge(int u, int v, int w);

    // Function to add an edge from vertex u to vertex v (for unweighted graphs)
    void addEdge(int u, int v);

    // Function to remove an edge from vertex u to vertex v
    void removeEdge(int u, int v);

    // Function to check if there is an edge from vertex u to vertex v
    bool hasEdge(int u, int v);
};



// Edge List representation of a graph
class EdgeListGraph {
private:
    // Structure to represent an edge in the edge list
    struct Edge {
        int u;       // Source vertex of the edge
        int v;       // Destination vertex of the edge
        int weight;  // Weight of the edge (if weighted)
    };

    std::vector<Edge> edges;   // Vector to store all edges in the graph
    int numVertices;           // Number of vertices in the graph

public:
    // Constructor to initialize the graph with n vertices
    EdgeListGraph(int n);

    // Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
    void addEdge(int u, int v, int w);

    // Function to add an edge from vertex u to vertex v (for unweighted graphs)
    void addEdge(int u, int v);

    // Function to remove an edge from vertex u to vertex v
    void removeEdge(int u, int v);

    // Function to check if there is an edge from vertex u to vertex v
    bool hasEdge(int u, int v);
};

*/