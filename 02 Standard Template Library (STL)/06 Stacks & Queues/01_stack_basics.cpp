#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Definition: A stack is a LIFO (Last In, First Out) data structure.

    stack<int> s;

    // Pushing elements onto the stack
    s.push(10);
    s.push(20);
    s.push(15);

    // Displaying the top element
    cout << "Top element: " << s.top() << endl;

    // Popping an element from the stack
    s.pop();

    cout << "Top element after pop: " << s.top() << endl;

    // Checking if the stack is empty
    if (s.empty()) {
        cout << "Stack s is empty.\n";
    } else {
        cout << "Stack s is not empty.\n";
    }

    stack <int> s2;
    swap(s, s2); // Swapping two stacks
    // s will become empty

    if (s.empty()) {
        cout << "Stack s2 is empty.\n";
    } else {
        cout << "Stack s2 is not empty.\n";
    }

    if (s2.empty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack is not empty.\n";
    }

    return 0;
}
