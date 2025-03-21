#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Definition: A priority queue is a heap-based structure that stores elements in sorted order.

    priority_queue<int> pq; // Max heap (default)

    // Pushing elements
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Displaying the top element (largest element in a max heap)
    cout << "Top element (max heap): " << pq.top() << endl;

    // Popping an element
    pq.pop();

    cout << "Top element after pop: " << pq.top() << endl;

    return 0;
}
