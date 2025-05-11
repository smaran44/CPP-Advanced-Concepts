#include <iostream>
using namespace std;

// ===================================================
// QUEUE USING ARRAY
// ===================================================
class QueueArray {
    int front, rear;   // Indices for front and rear of the queue
    int arr[100];      // Array to hold queue elements (fixed size)

public:
    QueueArray() {
        front = rear = -1;  // Initialize queue as empty
    }

    // Enqueue (add) an element to the queue
    void enqueue(int val) {
        if (rear == 99) { // Queue full
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;  // First element inserted at position 0
        arr[++rear] = val;          // Insert at the rear position and increment rear
    }

    // Dequeue (remove) an element from the front
    void dequeue() {
        if (front == -1 || front > rear) {  // Queue empty
            cout << "Queue Underflow\n";
            return;
        }
        front++;  // Simply move front forward, the element is discarded
    }

    // Peek the front element (without removing it)
    int peek() {
        if (front == -1 || front > rear) {  // Queue empty
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];  // Return the element at the front
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;  // Returns true if queue is empty
    }

    // Display all elements in the queue
    void display() {
        for (int i = front; i <= rear; i++)  // Loop through the array
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ===================================================
// QUEUE USING LINKED LIST
// ===================================================
struct Node {
    int data;      // Data of the node
    Node* next;    // Pointer to the next node
};

class QueueLL {
    Node* front;  // Points to the front of the queue
    Node* rear;   // Points to the rear of the queue

public:
    QueueLL() {
        front = rear = nullptr;  // Initially the queue is empty
    }

    // Enqueue (add) an element to the queue
    void enqueue(int val) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = val;         // Set the data of the new node
        newNode->next = nullptr;     // New node's next points to nullptr (end of list)

        if (!rear) {  // If queue is empty (no rear)
            front = rear = newNode;  // Both front and rear point to the new node
        } else {
            rear->next = newNode;  // Link the current rear node to the new node
            rear = newNode;         // Update rear to point to the new node
        }
    }

    // Dequeue (remove) an element from the front
    void dequeue() {
        if (!front) {  // Queue is empty
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;     // Temporarily store the front node
        front = front->next;    // Move the front pointer to the next node

        if (!front) rear = nullptr;  // If the queue becomes empty, set rear to nullptr
        delete temp;  // Free the memory of the old front node
    }

    // Peek the front element (without removing it)
    int peek() {
        if (!front) {  // Queue is empty
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;  // Return the data of the front node
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;  // Queue is empty if front is nullptr
    }

    // Display all elements in the queue
    void display() {
        Node* temp = front;
        while (temp) {  // Traverse the linked list
            cout << temp->data << " ";
            temp = temp->next;  // Move to the next node
        }
        cout << endl;
    }
};

// ===================================================
// MAIN FUNCTION TO DEMO BOTH QUEUES
// ===================================================
int main() {
    // Demonstrate Queue using Array
    cout << "--- Queue using Array ---\n";
    QueueArray q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();   // Output: 10 20 30
    q1.dequeue();   // Removes 10
    q1.display();   // Output: 20 30

    // Demonstrate Queue using Linked List
    cout << "\n--- Queue using Linked List ---\n";
    QueueLL q2;
    q2.enqueue(40);
    q2.enqueue(50);
    q2.enqueue(60);
    q2.display();   // Output: 40 50 60
    q2.dequeue();   // Removes 40
    q2.display();   // Output: 50 60

    return 0;
}
