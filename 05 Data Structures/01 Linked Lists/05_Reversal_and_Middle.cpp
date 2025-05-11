#include <iostream>  // For standard input/output
using namespace std;

// ===================================================
// Definition of a node in a singly linked list
// ===================================================
struct Node {
    int data;       // Value stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        next = nullptr;  // Next is initially null
    }
};

// ===================================================
// Insert a new node with value 'val' at the end of the list
// ===================================================
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);  // Create a new node
    if (!head) {                    // If the list is empty
        head = newNode;
        return;
    }

    // Traverse to the end of the list
    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;  // Link last node to new node
}

// ===================================================
// Print all elements of the linked list
// ===================================================
void printList(Node* head) {
    while (head) {                    // Loop until we reach end (NULL)
        cout << head->data << " -> "; // Print current node's data
        head = head->next;            // Move to next node
    }
    cout << "NULL\n";                 // End of list
}

// ===================================================
// Reverse the entire linked list
// ===================================================
Node* reverseList(Node* head) {
    Node* prev = nullptr;   // Will eventually become the new head
    Node* curr = head;      // Start from the current head

    while (curr) {
        Node* nextNode = curr->next;  // Save the next node
        curr->next = prev;            // Reverse current node's pointer
        prev = curr;                  // Move prev forward
        curr = nextNode;              // Move curr forward
    }

    return prev;  // Return new head of reversed list
}

// ===================================================
// Find the middle node using slow and fast pointer approach
// ===================================================
Node* findMiddle(Node* head) {
    if (!head) return nullptr;  // Empty list check

    Node* slow = head;  // Moves one step at a time
    Node* fast = head;  // Moves two steps at a time

    while (fast && fast->next) {
        slow = slow->next;           // Move slow by 1
        fast = fast->next->next;     // Move fast by 2
    }

    return slow;  // When fast reaches the end, slow is at middle
}

// ===================================================
// Main function: Entry point of the program
// ===================================================
int main() {
    Node* head = nullptr;

    // Inserting numbers 1 to 7 into the linked list
    for (int i = 1; i <= 7; i++)
        insert(head, i);  // List becomes: 1 -> 2 -> 3 -> ... -> 7

    cout << "Original List:\n";
    printList(head);  // Print the list

    // Find and print the middle element
    Node* mid = findMiddle(head);
    cout << "Middle Element: " << (mid ? mid->data : -1) << endl;

    // Reverse the list and print again
    head = reverseList(head);
    cout << "Reversed List:\n";
    printList(head);

    return 0;
}
