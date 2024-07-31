/*
Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. 
It’s used to explore or search through nodes and edges of a graph or tree.

Start at the Root Node: Begin from the root node or any arbitrary node in the case of a graph.
Explore Each Branch: Visit an adjacent unvisited node and continue recursively.
Backtrack: Once a node has no more unvisited adjacent nodes, backtrack to explore other branches.
Characteristics
Data Structure Used: Typically uses a stack (either explicit or implicit via recursion).
Traversal Order: Can be used to find paths, detect cycles, and explore connected components.
Example
Let's use a simple graph to demonstrate DFS:

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

DFS Algorithm Steps
Start at node 0.
Visit node 0 and move to its first adjacent node, which is 1.
Visit node 1 and move to its first unvisited adjacent node, which is 2.
Visit node 2 and since it has no unvisited adjacent nodes, backtrack to node 1.
Backtrack to node 0 and visit its next unvisited adjacent node, which is 3.
Visit node 3 and since it has no unvisited adjacent nodes, backtrack to node 0.

dfsUtil Function:
Uses a stack to keep track of nodes to visit.
Marks nodes as visited when they are popped from the stack and prints them.
Adds unvisited adjacent nodes to the stack.

main Function:
Creates the graph using an adjacency list.
Initializes a visited vector to track which nodes have been visited.
Calls dfsUtil to start DFS from node 0.
*/

#include <iostream>
#include <vector>
#include <stack>

void dfsUtil(int v, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    // Create a stack for DFS
    std::stack<int> stack;
    
    // Push the starting node into the stack
    stack.push(v);
    
    while (!stack.empty()) {
        // Pop a vertex from stack and print it
        int node = stack.top();
        stack.pop();
        
        // If the node is not visited, mark it visited and print it
        if (!visited[node]) {
            std::cout << node << " ";
            visited[node] = true;
        }
        
        // Get all adjacent vertices of the popped vertex
        // If an adjacent vertex has not been visited, push it to the stack
        for (int i = adjList[node].size() - 1; i >= 0; --i) {
            int adj = adjList[node][i];
            if (!visited[adj]) {
                stack.push(adj);
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

    // Vector to keep track of visited nodes
    std::vector<bool> visited(n, false);

    // Perform DFS starting from node 0
    std::cout << "DFS starting from node 0:" << std::endl;
    dfsUtil(0, adjList, visited);

    return 0;
}
