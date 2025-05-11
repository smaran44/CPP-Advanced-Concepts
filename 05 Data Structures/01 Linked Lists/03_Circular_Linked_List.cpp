#include <iostream> // For input and output operations
using namespace std;

// =======================================================
// Definition of a Node in a Circular Singly Linked List
// =======================================================
struct Node {
    int data;       // Value stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with a given value
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// =======================================================
// Function to insert a new node at the end of the circular list
// =======================================================
void insert(Node*& head, int val) {
    // Step 1: Create a new node
    Node* newNode = new Node(val);

    // Step 2: If list is empty, point newNode to itself and set it as head
    if (head == nullptr) {
        newNode->next = newNode; // Points to itself — circular
        head = newNode;
        return;
    }

    // Step 3: Traverse to the last node (whose next points to head)
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Step 4: Insert newNode at the end and update the last node's next
    temp->next = newNode;
    newNode->next = head; // new node points back to head to maintain circularity
}

// =======================================================
// Function to display the entire circular list
// =======================================================
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    // Loop through the list until we come back to the head
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n"; // Shows that it's a circular list
}

// =======================================================
// Function to delete a node by value from the circular list
// =======================================================
void deleteNode(Node*& head, int val) {
    if (head == nullptr) return; // Empty list, nothing to delete

    Node* curr = head;
    Node* prev = nullptr;

    do {
        // Step 1: Check if current node has the value to delete
        if (curr->data == val) {

            if (prev != nullptr) {
                // Case 1: Deleting a middle or last node
                prev->next = curr->next;
            } else {
                // Case 2: Deleting the head node
                Node* tail = head;

                // Find the last node (tail) to reconnect the circle
                while (tail->next != head)
                    tail = tail->next;

                head = head->next;      // Move head forward
                tail->next = head;      // Update last node's next to new head
            }

            // Special case: Only one node present
            if (curr == head && curr->next == head) {
                head = nullptr; // Now the list is empty
            }

            delete curr; // Free memory
            return;
        }

        // Move to next node
        prev = curr;
        curr = curr->next;

    } while (curr != head); // Stop when we circle back to the start
}

// =======================================================
// Main function - where program execution begins
// =======================================================
int main() {
    Node* head = nullptr; // Initialize an empty list

    // Insert nodes into the circular linked list
    insert(head, 10); // List: 10 -> back to head
    insert(head, 20); // List: 10 -> 20 -> back to head
    insert(head, 30); // List: 10 -> 20 -> 30 -> back to head

    // Display current list
    cout << "Circular Linked List:\n";
    display(head); // Output: 10 -> 20 -> 30 -> (back to head)

    // Delete node with value 20
    cout << "Deleting 20...\n";
    deleteNode(head, 20);

    // Display updated list
    display(head); // Output: 10 -> 30 -> (back to head)

    return 0; // End of program
}
