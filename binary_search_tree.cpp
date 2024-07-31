/*
A Binary Search Tree (BST) is a type of binary tree where each node has at most two children, 
often referred to as the left and right child. In a BST, the following properties hold:

Left Subtree Property: The left subtree of a node contains only nodes with keys less than the node's key.
Right Subtree Property: The right subtree of a node contains only nodes with keys greater than the node's key.
No Duplicates: Duplicate keys are generally not allowed.

Insertion: Add a new node to the tree while maintaining the BST properties.
Search: Find a node with a specific key.
Deletion: Remove a node from the tree while maintaining the BST properties.

Example
Consider a BST with the following nodes inserted in this order: 15, 10, 20, 8, 12, 17, 25.

The BST will look like this:

      15
     /  \
   10    20
   / \   / \
  8  12 17 25


Node Structure: Defines the structure of each node in the BST, containing data, and pointers to left and right children.
Insert Function: Recursively inserts a new node in the correct position to maintain the BST property.
Search Function: Recursively searches for a key in the BST.
In-order Traversal: Prints the BST in sorted order.
Main Function: Demonstrates inserting nodes into the BST, printing the in-order traversal, and searching for a specific key.

*/
#include <iostream>

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Insert function
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search function
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// In-order traversal (for printing the BST)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    
    // Insert nodes into the BST
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);
    
    // Print in-order traversal (sorted order)
    std::cout << "In-order traversal: ";
    inorder(root);
    std::cout << std::endl;
    
    // Search for a key in the BST
    int key = 10;
    if (search(root, key)) {
        std::cout << "Key " << key << " found in the BST." << std::endl;
    } else {
        std::cout << "Key " << key << " not found in the BST." << std::endl;
    }

    return 0;
}
