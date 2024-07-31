/*
Breadth-First Search (BFS) is a graph traversal algorithm that explores all the nodes at the present depth level 
before moving on to nodes at the next depth level. It is particularly useful for finding the shortest path in an unweighted graph.

Start at the Root Node: Begin from the root node or any arbitrary node.
Explore Neighbors: Visit all the neighbors of the current node.
Use a Queue: Maintain a queue to keep track of nodes to be explored next.
Mark Nodes as Visited: Ensure that each node is visited only once.
Characteristics
Data Structure Used: Queue
Traversal Order: Level-by-level
Example
Let's use a simple graph to demonstrate BFS:

   1
  / \
 0   2
  \
   3
Adjacency List Representation

0: [1, 3]
1: [0, 2]
2: [1]
3: [0]

BFS Algorithm Steps
Start at node 0.
Visit node 0 and add its neighbors (1 and 3) to the queue.
Visit node 1 (next in the queue) and add its unvisited neighbor (2) to the queue.
Visit node 3 (next in the queue). It has no new neighbors.
Visit node 2 (next in the queue). It has no new neighbors.

bfs Function:
Uses a queue to manage the nodes to be explored.
Marks nodes as visited when they are dequeued and prints them.
Adds unvisited adjacent nodes to the queue.

main Function:
Creates the graph using an adjacency list.
Initializes a visited vector to track which nodes have been visited.
Calls bfs to start BFS from node 0.
*/

#include <iostream>
#include <vector>
#include <queue>

void bfs(int start, const std::vector<std::vector<int>>& adjList) {
    // Vector to keep track of visited nodes
    std::vector<bool> visited(adjList.size(), false);
    
    // Create a queue for BFS
    std::queue<int> queue;
    
    // Start from the starting node
    queue.push(start);
    visited[start] = true;
    
    while (!queue.empty()) {
        // Dequeue a node from the queue and print it
        int node = queue.front();
        queue.pop();
        
        std::cout << node << " ";
        
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    // Number of nodes
    int n = 4;

    // Create an adjacency list
    std::vector<std::vector<int>> adjList(n);

    // Define edges
    adjList[0].push_back(1);
    adjList[0].push_back(3);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[3].push_back(0);

    // Perform BFS starting from node 0
    std::cout << "BFS starting from node 0:" << std::endl;
    bfs(0, adjList);

    return 0;
}
