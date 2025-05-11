#include <iostream>
using namespace std;

// ===================================================
// STACK USING ARRAY
// ===================================================
class StackArray {
    int top;          // Index of the top element
    int arr[100];     // Array to hold stack elements (size fixed to 100)

public:
    StackArray() {
        top = -1;     // Stack is initially empty
    }

    // Push a value onto the stack
    void push(int val) {
        if (top >= 99) {   // Check for stack overflow (stack is full)
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;  // Increment top and insert value
    }

    // Pop the top value from the stack
    void pop() {
        if (top < 0) {     // Check for stack underflow (stack is empty)
            cout << "Stack Underflow\n";
            return;
        }
        top--;             // Just reduce the top index (data gets overwritten later)
    }

    // Get the top value of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];   // Return value at the top index
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;   // Stack is empty if top is -1
    }

    // Print all elements of the stack (from top to bottom)
    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";  // Print from top to bottom
        }
        cout << endl;
    }
};

// ===================================================
// STACK USING LINKED LIST
// ===================================================
struct Node {
    int data;      // Value of the node
    Node* next;    // Pointer to the next node
};

// Stack class using linked list
class StackLL {
    Node* top;     // Points to the top of the stack

public:
    StackLL() {
        top = nullptr;   // Stack is empty initially
    }

    // Push value onto stack (insert at the top)
    void push(int val) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = val;
        newNode->next = top;        // Link it to the current top node
        top = newNode;              // Update top to the new node
    }

    // Pop value from the top (remove the top node)
    void pop() {
        if (!top) {                 // If stack is empty (top is null)
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;           // Store the top node in temp
        top = top->next;            // Move top to the next node
        delete temp;                // Delete the old top node
    }

    // Get the top value (without removing it)
    int peek() {
        if (!top) {                 // If stack is empty
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;           // Return the data at the top node
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;      // Stack is empty if top is nullptr
    }

    // Print all elements of the stack (from top to bottom)
    void display() {
        Node* temp = top;
        while (temp) {  // Traverse the linked list from top to bottom
            cout << temp->data << " ";
            temp = temp->next;  // Move to the next node
        }
        cout << endl;
    }
};

// ===================================================
// MAIN FUNCTION TO DEMO BOTH STACK TYPES
// ===================================================
int main() {
    // Demonstrate stack using array
    cout << "--- Stack using Array ---\n";
    StackArray s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();  // Output: 30 20 10
    s1.pop();      // Pops 30
    s1.display();  // Output: 20 10

    // Demonstrate stack using linked list
    cout << "\n--- Stack using Linked List ---\n";
    StackLL s2;
    s2.push(40);
    s2.push(50);
    s2.push(60);
    s2.display();  // Output: 60 50 40
    s2.pop();      // Pops 60
    s2.display();  // Output: 50 40

    return 0;
}
