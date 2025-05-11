#include <iostream>  // For input/output operations
using namespace std;

// ===================================================
// Definition of a Node in a singly linked list
// ===================================================
struct Node {
    int data;       // Value stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ===================================================
// Function to insert a node at the end of the list
// ===================================================
void insert(Node*& head, int val) {
    Node* newNode = new Node(val); // Create a new node
    if (!head) {                   // If list is empty, make new node the head
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)             // Traverse to the last node
        temp = temp->next;

    temp->next = newNode;          // Link last node to the new node
}

// ===================================================
// Function to create a cycle in the list
// pos = index (0-based) of node to connect the last node to
// ===================================================
void createCycle(Node* head, int pos) {
    Node* temp = head;
    Node* startNode = nullptr;     // Will hold the address of the node at 'pos'
    int count = 0;

    while (temp->next) {           // Traverse to the end of the list
        if (count == pos)          // Mark the node at position 'pos'
            startNode = temp;

        temp = temp->next;
        count++;
    }

    temp->next = startNode;        // Create cycle: last node points to startNode
}

// ===================================================
// Function to detect if a cycle exists using Floyd’s Cycle Detection Algorithm
// Also called the Tortoise and Hare algorithm
// ===================================================
bool detectCycle(Node* head) {
    Node* slow = head;             // Moves 1 step at a time
    Node* fast = head;             // Moves 2 steps at a time

    while (fast && fast->next) {
        slow = slow->next;         // Move slow by 1
        fast = fast->next->next;   // Move fast by 2

        if (slow == fast)          // If they meet, a cycle exists
            return true;
    }

    return false;                  // If fast reaches NULL, no cycle
}

// ===================================================
// Main function to run the code
// ===================================================
int main() {
    Node* head = nullptr;          // Start with an empty list

    // Insert values into the list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    // List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL (initially)

    createCycle(head, 2);          // Creates a cycle: 5 -> 3
    // Now the list is: 1 -> 2 -> 3 -> 4 -> 5 -> back to 3 -> ...

    // Check for cycle
    if (detectCycle(head))
        cout << "Cycle detected in the linked list.\n";
    else
        cout << "No cycle found.\n";

    return 0;
}
