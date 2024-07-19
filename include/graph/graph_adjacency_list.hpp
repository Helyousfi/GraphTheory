#ifndef GRAPH_DEFENITION_ADJACENCY_LIST
#define GRAPH_DEFENITION_ADJACENCY_LIST

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

#endif // GRAPH_DEFENITION_ADJACENCY_LIST
