#include <iostream>
using namespace std;

// Binary Tree Node Definition
struct Node {
    int data;        // The data stored in the node (in this case an integer)
    Node* left;      // Pointer to the left child of the node
    Node* right;     // Pointer to the right child of the node

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;  // Initialize the data of the node
        left = right = nullptr;  // Initially, both left and right pointers are null
    }
};

// Function to find the LCA (Lowest Common Ancestor) of two nodes in a Binary Tree
Node* LCA(Node* root, int n1, int n2) {
    // Base Case: If the root is null, return null (end of branch)
    if (root == nullptr) return nullptr;

    // If either n1 or n2 is the root, return the root (base case for one of the nodes)
    if (root->data == n1 || root->data == n2) return root;

    // Recursively search for LCA in the left and right subtrees
    Node* leftLCA = LCA(root->left, n1, n2);  // Search in the left subtree
    Node* rightLCA = LCA(root->right, n1, n2);  // Search in the right subtree

    // If one node is found in the left subtree and the other in the right subtree,
    // then the current root node is the LCA.
    if (leftLCA && rightLCA) return root;

    // If only one node is found, return the non-null child (either left or right)
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

// Driver Code
int main() {
    /*
        Sample Tree:
               1
              / \
             2   3
            / \
           4   5
    */

    // Create the root node with data 1
    Node* root = new Node(1);
    root->left = new Node(2);  // Create left child of root with data 2
    root->right = new Node(3);  // Create right child of root with data 3
    root->left->left = new Node(4);  // Create left child of node 2 with data 4
    root->left->right = new Node(5);  // Create right child of node 2 with data 5

    int n1 = 4, n2 = 5;  // Nodes whose LCA we want to find
    Node* ancestor = LCA(root, n1, n2);  // Call the LCA function to find the LCA of nodes 4 and 5
    
    // If LCA is found, print it
    if (ancestor != nullptr) {
        cout << "LCA of " << n1 << " and " << n2 << " is " << ancestor->data << endl; // Expected Output: 2
    } else {
        cout << "No common ancestor found!" << endl;  // In case no common ancestor is found
    }

    return 0;
}

