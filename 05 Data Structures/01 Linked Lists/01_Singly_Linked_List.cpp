#include <iostream> // For input and output
using namespace std; // To avoid writing std:: before every standard function

// ===========================
// Definition of a Node
// ===========================

// A "Node" is the basic building block of a linked list.
// Each node contains some data and a pointer to the next node in the list.
struct Node {
    int data;      // This holds the actual value (integer in this case)
    Node* next;    // Pointer to the next node in the linked list

    // Constructor that initializes the node with a given value
    // It sets 'data' to val and 'next' to nullptr (i.e., no next node yet)
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// =======================================
// Function to insert a new node at the end of the linked list
// =======================================

void insertAtTail(Node*& head, int val) {
    // Step 1: Create a new node with the given value
    Node* newNode = new Node(val); // 'new' dynamically allocates memory on the heap

    // Step 2: If the list is empty, make the new node the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Step 3: Otherwise, traverse to the end of the list
    Node* temp = head; // Start from the head
    while (temp->next != nullptr) {
        temp = temp->next; // Move to the next node
    }

    // Step 4: Make the last node's next point to the new node
    temp->next = newNode;
}

// =======================================
// Function to delete a node by its value
// =======================================

void deleteNode(Node*& head, int val) {
    // Step 1: If the list is empty, there is nothing to delete
    if (head == nullptr) return;

    // Step 2: Check if the node to delete is the head node
    if (head->data == val) {
        Node* toDelete = head;     // Temporarily store the current head
        head = head->next;         // Move head to the next node
        delete toDelete;           // Free memory of the old head node
        return;
    }

    // Step 3: Traverse the list to find the node just before the node to delete
    Node* temp = head;
    // Keep going until you find a node whose next has the value to delete
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    // Step 4: If such a node was found (i.e., temp->next is not null)
    if (temp->next) {
        Node* toDelete = temp->next;             // Node to be deleted
        temp->next = temp->next->next;           // Skip the node to be deleted
        delete toDelete;                         // Free memory of the deleted node
    }
}

// =======================================
// Function to print all the values in the linked list
// =======================================

void printList(Node* head) {
    Node* temp = head; // Start from the head

    // Traverse the list and print each node's data
    while (temp) {
        cout << temp->data << " -> "; // Print value followed by arrow
        temp = temp->next;            // Move to next node
    }

    cout << "NULL\n"; // End of the list
}

// =======================================
// Function to search for a value in the list
// Returns true if found, false otherwise
// =======================================

bool search(Node* head, int key) {
    Node* temp = head; // Start from the head

    // Traverse through the list
    while (temp) {
        if (temp->data == key) return true; // Value found
        temp = temp->next;                  // Move to next node
    }

    return false; // Value not found
}

// =======================================
// Main function - Entry point of the program
// =======================================

int main() {
    Node* head = nullptr; // Initially, the list is empty

    // Insert elements at the tail of the list
    insertAtTail(head, 10);  // List becomes: 10
    insertAtTail(head, 20);  // List becomes: 10 -> 20
    insertAtTail(head, 30);  // List becomes: 10 -> 20 -> 30

    // Print the current list
    cout << "Linked List: ";
    printList(head); // Output: 10 -> 20 -> 30 -> NULL

    // Delete the node with value 20
    cout << "Deleting 20...\n";
    deleteNode(head, 20);    // List becomes: 10 -> 30
    printList(head);         // Output: 10 -> 30 -> NULL

    // Search for value 30 in the list
    cout << "Searching for 30: ";
    cout << (search(head, 30) ? "Found\n" : "Not Found\n"); // Output: Found

    return 0; // End of the program
}
