# Graph Algorithms
## Table of Contents
- Introduction
- Project Structure
- Graph Representations
- Algorithms Implemented
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
- Building the Project
- Usage

## Introduction
This project implements various graph algorithms using C++. The primary focus is on understanding different graph representations and fundamental traversal algorithms like Breadth-First Search (BFS) and Depth-First Search (DFS).

## Project Structure
The project is organized into the following directories:
```
graph-algorithms/
├── include/
│   └── graph.hpp       # Header files for graph representations
├── src/
│   ├── graph.cpp       # Implementation of graph representations
│   ├── BFS.cpp         # Implementation of BFS
│   └── DFS.cpp         # Implementation of DFS
├── bin/                # Directory where DLL will be generated
├── main.cpp            # Main file to test the graph algorithms
└── Makefile            # Makefile to build the project
```
## Graph Representations
The project supports the following graph representations:

1. Adjacency Matrix
2. Adjacency List (Planned)
3. Edge List (Planned)

## Algorithms Implemented
### Breadth-First Search (BFS)
BFS is an algorithm for traversing or searching tree or graph data structures. It starts at a selected node and explores all neighbor nodes at the present depth before moving on to nodes at the next depth level.

### Depth-First Search (DFS)
DFS is an algorithm for traversing or searching tree or graph data structures. It starts at a selected node and explores as far as possible along each branch before backtracking.

### Building the Project
To build the project and generate the DLL, follow these steps:

- Clone the repository:
```
git clone https://github.com/your-username/graph-algorithms.git
cd graph-algorithms
```

Use the provided Makefile to build the project:
```
make
```
To clean the build directory:
```
make clean
```

Usage
After building the project, you can use the generated executable to test the graph algorithms. Here is an example of how to use the main executable:

```
./graph_algorithms
```
You can modify main.cpp to test different graph algorithms and representations.