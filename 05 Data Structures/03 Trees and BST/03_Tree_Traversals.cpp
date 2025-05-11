#include <iostream>
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

// Inorder Traversal (LNR)
void inorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return

    inorder(root->left);  // Recursively traverse the left subtree
    cout << root->data << " ";  // Print the current node's data
    inorder(root->right);  // Recursively traverse the right subtree
}

// Preorder Traversal (NLR)
void preorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return

    cout << root->data << " ";  // Print the current node's data
    preorder(root->left);  // Recursively traverse the left subtree
    preorder(root->right);  // Recursively traverse the right subtree
}

// Postorder Traversal (LRN)
void postorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return

    postorder(root->left);  // Recursively traverse the left subtree
    postorder(root->right);  // Recursively traverse the right subtree
    cout << root->data << " ";  // Print the current node's data
}

// Driver code
int main() {
    /*
        Sample Tree:
               1
              / \
             2   3
            / \   \
           4   5   6
    */

    Node* root = new Node(1);  // Create the root node
    root->left = new Node(2);  // Create left child of root
    root->right = new Node(3);  // Create right child of root
    root->left->left = new Node(4);  // Create left child of node 2
    root->left->right = new Node(5);  // Create right child of node 2
    root->right->right = new Node(6);  // Create right child of node 3

    cout << "Inorder Traversal: ";
    inorder(root);        // Expected Output: 4 2 5 1 3 6
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorder(root);       // Expected Output: 1 2 4 5 3 6
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);      // Expected Output: 4 5 2 6 3 1
    cout << "\n";

    return 0;
}
