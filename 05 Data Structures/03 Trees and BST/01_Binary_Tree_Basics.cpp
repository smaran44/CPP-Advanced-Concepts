#include <iostream>
using namespace std;

// Define structure for a tree node
struct Node {
    int data;          // Data of the node
    Node* left;        // Pointer to left child node
    Node* right;       // Pointer to right child node

    // Constructor to initialize node
    Node(int val) {
        data = val;    // Set node data
        left = right = nullptr; // Set both left and right children to nullptr initially
    }
};

// Preorder traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return
    cout << root->data << " ";    // Print the current node's data
    preorder(root->left);         // Recursively traverse the left subtree
    preorder(root->right);        // Recursively traverse the right subtree
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return
    inorder(root->left);          // Recursively traverse the left subtree
    cout << root->data << " ";    // Print the current node's data
    inorder(root->right);         // Recursively traverse the right subtree
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return
    postorder(root->left);        // Recursively traverse the left subtree
    postorder(root->right);       // Recursively traverse the right subtree
    cout << root->data << " ";    // Print the current node's data
}

// Driver Code
int main() {
    /*
        Constructed Binary Tree:
              1
             / \
            2   3
           / \
          4   5
    */
    Node* root = new Node(1);            // Root node with value 1
    root->left = new Node(2);            // Left child of root with value 2
    root->right = new Node(3);           // Right child of root with value 3
    root->left->left = new Node(4);      // Left child of node 2 with value 4
    root->left->right = new Node(5);     // Right child of node 2 with value 5

    // Perform and display the traversals
    cout << "Preorder Traversal: ";
    preorder(root);  // Output: 1 2 4 5 3
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);   // Output: 4 2 5 1 3
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root); // Output: 4 5 2 3 1
    cout << "\n";

    return 0;
}
