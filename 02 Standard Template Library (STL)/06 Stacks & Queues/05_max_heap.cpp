#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Definition: A max heap is a priority queue where the largest element is given priority.

    priority_queue<int> maxHeap;

    // Pushing elements
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    // Displaying the top element (largest element in a max heap)
    cout << "Top element (max heap): " << maxHeap.top() << endl;

    // Popping an element
    maxHeap.pop();

    cout << "Top element after pop: " << maxHeap.top() << endl;

    return 0;
}
