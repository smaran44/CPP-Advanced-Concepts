#include <iostream>
#include <algorithm>
using namespace std;

// Binary Tree Node Definition
struct Node {
    int data;        // Data of the node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child

    Node(int val) {
        data = val;  // Initialize node with the given value
        left = right = nullptr;  // Set both left and right child pointers to nullptr
    }
};

// Function to calculate the height of the tree
int height(Node* root) {
    if (root == nullptr) return 0;  // If the node is null, return height as 0
    return 1 + max(height(root->left), height(root->right));  // Height is 1 + maximum of left and right subtree heights
}

// Function to calculate the diameter of the tree
int diameter(Node* root) {
    if (root == nullptr) return 0;  // If the node is null, return diameter as 0

    // Calculate height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Calculate the diameter through the current node
    int currentDiameter = leftHeight + rightHeight;

    // Recursively calculate the diameter of left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // Return the maximum diameter found
    return max(currentDiameter, max(leftDiameter, rightDiameter));  // Maximum of current, left, and right diameters
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

    Node* root = new Node(1);  // Create the root node
    root->left = new Node(2);  // Create left child of root
    root->right = new Node(3);  // Create right child of root
    root->left->left = new Node(4);  // Create left child of node 2
    root->left->right = new Node(5);  // Create right child of node 2

    cout << "Height of the tree: " << height(root) << endl;   // Expected Output: 3
    cout << "Diameter of the tree: " << diameter(root) << endl; // Expected Output: 4

    return 0;
}
