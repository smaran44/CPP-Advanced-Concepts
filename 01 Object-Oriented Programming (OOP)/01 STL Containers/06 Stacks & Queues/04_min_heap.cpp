#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Definition: A min heap is a priority queue where the smallest element is given priority.

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Pushing elements
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    // Displaying the top element (smallest element in a min heap)
    cout << "Top element (min heap): " << minHeap.top() << endl;

    // Popping an element
    minHeap.pop();

    cout << "Top element after pop: " << minHeap.top() << endl;

    return 0;
}
