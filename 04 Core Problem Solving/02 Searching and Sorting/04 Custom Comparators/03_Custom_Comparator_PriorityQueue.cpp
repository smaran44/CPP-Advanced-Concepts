/*
    Program: Min-Heap using Priority Queue with Custom Comparator
    -------------------------------------------------------------
    What it does:
    - Creates a min-heap (priority queue where the smallest element is on top).
    - Inserts elements into the min-heap.
    - Removes and prints elements in ascending order.

    Logic used:
    - By default, C++ priority_queue is a **max-heap**.
    - To create a **min-heap**, we use a **custom comparator** that reverses the comparison: `a > b`.
*/

#include <iostream>     // For input/output
#include <queue>        // For priority_queue
#include <vector>       // For vector container used by priority_queue

using namespace std;

// Custom comparator struct to create a min-heap
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Return true if a is greater → gives priority to smaller values (min-heap)
    }
};

int main() {
    // Declare a priority_queue (min-heap) using custom comparator
    priority_queue<int, vector<int>, Compare> pq;

    // Push elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Pop and print all elements (in ascending order)
    while (!pq.empty()) {
        cout << pq.top() << " ";  // Access the top (smallest) element
        pq.pop();                 // Remove the top element
    }

    return 0;  // End of program
}
