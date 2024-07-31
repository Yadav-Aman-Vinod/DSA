/*
An adjacency matrix is a way to represent a graph using a 2D array. Each element in the matrix 
indicates whether pairs of nodes are connected by an edge.

Adjacency Matrix Overview
Size: For a graph with n nodes, the adjacency matrix is an n x n matrix.
Matrix Entry: If there is an edge between node i and node j, the matrix entry matrix[i][j] 
is set to 1 (or the weight if it’s a weighted graph). Otherwise, it is set to 0.

Example
Let’s create a simple undirected graph with 3 nodes:

   1
  / \
 0 - 2
Nodes: 0, 1, 2
Edges: (0, 1), (0, 2), (1, 2)
Adjacency Matrix Representation
For the graph above, the adjacency matrix looks like this:

Copy code
    0 1 2
 0 [0 1 1]
 1 [1 0 1]
 2 [1 1 0]
Matrix Entry [i][j] is 1 if there is an edge between node i and node j, otherwise 0.

*/

#include <iostream>
#include <vector>

int main() {
    // Number of nodes
    int n = 3;

    // Create an adjacency matrix initialized with 0s
    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n, 0));

    // Define edges
    // Edge between node 0 and 1
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1; // For undirected graph, mirror the edge

    // Edge between node 0 and 2
    adjMatrix[0][2] = 1;
    adjMatrix[2][0] = 1; // For undirected graph, mirror the edge

    // Edge between node 1 and 2
    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1; // For undirected graph, mirror the edge

    // Print the adjacency matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
