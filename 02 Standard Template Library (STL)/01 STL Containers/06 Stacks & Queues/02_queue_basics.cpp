#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Definition: A queue is a FIFO (First In, First Out) data structure.

    queue<int> q;

    // Enqueuing (pushing) elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Displaying the front element
    cout << "Front element: " << q.front() << endl;

    // Dequeuing (popping) an element
    q.pop();

    cout << "Front element after pop: " << q.front() << endl;

    return 0;
}
