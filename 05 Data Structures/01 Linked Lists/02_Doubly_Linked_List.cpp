#include <iostream> // For input/output operations
using namespace std; // So we don't need to prefix std:: everywhere

// =======================================================
// Definition of a Node for a Doubly Linked List
// =======================================================

struct Node {
    int data;       // Stores the value of the node
    Node* prev;     // Points to the previous node in the list
    Node* next;     // Points to the next node in the list

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        prev = nullptr; // Initially there’s no previous node
        next = nullptr; // Initially there’s no next node
    }
};

// =======================================================
// Function to insert a node at the end of the list
// =======================================================

void insertAtTail(Node*& head, int val) {
    // Step 1: Create a new node dynamically with the given value
    Node* newNode = new Node(val);

    // Step 2: If list is empty, the new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Step 3: Traverse to the end of the list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // Move to next node
    }

    // Step 4: Connect the new node at the end
    temp->next = newNode;     // Current last node's next points to new node
    newNode->prev = temp;     // New node's prev points back to last node
}

// =======================================================
// Function to print the list from head to tail (forward)
// =======================================================

void printForward(Node* head) {
    cout << "Forward: ";
    Node* temp = head;

    // Traverse from head to tail
    while (temp) {
        cout << temp->data << " <-> "; // Print data and show bidirectional link
        temp = temp->next;
    }

    cout << "NULL\n"; // End of list
}

// =======================================================
// Function to print the list from tail to head (backward)
// =======================================================

void printBackward(Node* head) {
    cout << "Backward: ";

    // If list is empty, do nothing
    if (!head) return;

    Node* temp = head;

    // Step 1: Move to the tail (last node)
    while (temp->next) {
        temp = temp->next;
    }

    // Step 2: Traverse backward using prev pointers
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n"; // Start of list
}

// =======================================================
// Function to delete a node by its value
// =======================================================

void deleteNode(Node*& head, int val) {
    Node* temp = head;

    // Step 1: Search for the node with the given value
    while (temp && temp->data != val) {
        temp = temp->next;
    }

    // Step 2: If the value was not found, do nothing
    if (!temp) return;

    // Step 3: Adjust the pointers to remove the node from the list

    // If temp has a previous node, link its next to temp's next
    if (temp->prev) {
        temp->prev->next = temp->next;
    }

    // If temp has a next node, link its prev to temp's prev
    if (temp->next) {
        temp->next->prev = temp->prev;
    }

    // If temp is the head node, update the head to the next node
    if (temp == head) {
        head = temp->next;
    }

    // Step 4: Free memory of the deleted node
    delete temp;
}

// =======================================================
// Main function - where execution starts
// =======================================================

int main() {
    Node* head = nullptr; // Initially the list is empty

    // Insert some nodes at the tail (end)
    insertAtTail(head, 1); // List: 1
    insertAtTail(head, 2); // List: 1 <-> 2
    insertAtTail(head, 3); // List: 1 <-> 2 <-> 3

    // Print list in forward and backward direction
    printForward(head);   // Output: Forward: 1 <-> 2 <-> 3 <-> NULL
    printBackward(head);  // Output: Backward: 3 <-> 2 <-> 1 <-> NULL

    // Delete a node with value 2
    cout << "Deleting 2...\n";
    deleteNode(head, 2);  // List becomes: 1 <-> 3

    // Print again to confirm changes
    printForward(head);   // Output: Forward: 1 <-> 3 <-> NULL
    printBackward(head);  // Output: Backward: 3 <-> 1 <-> NULL

    return 0; // End of program
}
