#include <iostream>
using namespace std;

// Define node structure
struct Node {
    int data;        // Node's value
    Node* left;      // Pointer to left child node
    Node* right;     // Pointer to right child node

    Node(int val) {
        data = val;  // Initialize node with the given value
        left = right = nullptr;  // Set both left and right pointers to nullptr
    }
};

// Insert a node into BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);  // If root is null, create a new node and return it
    }

    // Traverse the tree to find the correct position for the new node
    if (key < root->data)
        root->left = insert(root->left, key);  // Insert in the left subtree
    else if (key > root->data)
        root->right = insert(root->right, key);  // Insert in the right subtree

    return root;  // Return the root node (unchanged)
}

// Search in BST
bool search(Node* root, int key) {
    if (root == nullptr) return false;  // Base case: If node is null, return false

    if (root->data == key) return true;  // If key matches the root, return true
    else if (key < root->data) return search(root->left, key);  // Search in left subtree
    else return search(root->right, key);  // Search in right subtree
}

// Find the minimum node in a subtree (leftmost node)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;  // Keep traversing left
    return root;  // Return the leftmost node
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;  // If root is null, return null

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // Traverse left
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);  // Traverse right
    }
    else {  // Node found to be deleted
        // Case 1: Node has no child or one child
        if (root->left == nullptr) {
            Node* temp = root->right;  // Store right child
            delete root;  // Delete the current node
            return temp;  // Return right child (may be null)
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;  // Store left child
            delete root;  // Delete the current node
            return temp;  // Return left child (may be null)
        }

        // Case 2: Node has two children
        Node* temp = findMin(root->right);  // Inorder successor (leftmost node of right subtree)
        root->data = temp->data;  // Replace current node's data with inorder successor's data
        root->right = deleteNode(root->right, temp->data);  // Delete inorder successor
    }

    return root;  // Return the (possibly modified) root
}

// Inorder traversal to print BST
void inorder(Node* root) {
    if (root == nullptr) return;  // Base case: if node is null, return
    inorder(root->left);  // Recursively traverse the left subtree
    cout << root->data << " ";  // Print the current node's data
    inorder(root->right);  // Recursively traverse the right subtree
}

// Driver Code
int main() {
    Node* root = nullptr;  // Initially, the BST is empty
    int keys[] = { 10, 5, 15, 3, 7, 12, 18 };  // Keys to be inserted into the BST

    // Insert nodes into the BST
    for (int key : keys)
        root = insert(root, key);  // Insert each key

    cout << "Inorder Traversal: ";  // Print inorder traversal
    inorder(root);  // Output: 3 5 7 10 12 15 18
    cout << endl;

    // Search for a value in the BST
    cout << "Search 7: " << (search(root, 7) ? "Found" : "Not Found") << endl;  // Search for 7
    cout << "Search 9: " << (search(root, 9) ? "Found" : "Not Found") << endl;  // Search for 9

    // Delete a node (value 15) from the BST
    root = deleteNode(root, 15);  // Delete node with value 15
    cout << "Inorder After Deleting 15: ";  // Print inorder traversal after deletion
    inorder(root);  // Output: 3 5 7 10 12 18
    cout << endl;

    return 0;
}
