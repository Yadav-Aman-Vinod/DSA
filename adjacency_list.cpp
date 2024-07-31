/*
An adjacency list is another way to represent a graph. Instead of using a 2D matrix, 
it uses a list of lists (or an array of lists) where each node has a list of nodes it's connected to.

Structure: Each node in the graph has a list (or vector) of nodes that it is directly connected to.
Advantages: More space-efficient for sparse graphs compared to an adjacency matrix.

Let's use the same undirected graph with 3 nodes:

Copy code
   1
  / \
 0 - 2
Adjacency List Representation:

Node 0: [1, 2]
Node 1: [0, 2]
Node 2: [0, 1]

Adjacency List is a list where each entry corresponds to a node and contains a list of adjacent nodes.
Advantages: Space-efficient for sparse graphs, easy to traverse adjacent nodes.
Disadvantages: Less efficient for operations that require quick access to whether there is an edge between two nodes.
*/

#include <iostream>
#include <vector>

int main() {
    // Number of nodes
    int n = 3;

    // Create an adjacency list (vector of vectors)
    std::vector<std::vector<int>> adjList(n);

    // Define edges
    // Edge between node 0 and 1
    adjList[0].push_back(1);
    adjList[1].push_back(0); // For undirected graph, add edge in both directions

    // Edge between node 0 and 2
    adjList[0].push_back(2);
    adjList[2].push_back(0); // For undirected graph, add edge in both directions

    // Edge between node 1 and 2
    adjList[1].push_back(2);
    adjList[2].push_back(1); // For undirected graph, add edge in both directions

    // Print the adjacency list
    std::cout << "Adjacency List:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
