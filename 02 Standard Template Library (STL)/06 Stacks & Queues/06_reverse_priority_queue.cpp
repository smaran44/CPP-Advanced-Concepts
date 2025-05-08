#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Priority queue with greater<int> to reverse the order (min-heap behavior)
    priority_queue<int, vector<int>, greater<int>> reversePQ;

    // Insert elements into the priority queue
    reversePQ.push(10);
    reversePQ.push(5);
    reversePQ.push(20);
    reversePQ.push(15);

    // Display and remove elements from the priority queue
    cout << "Elements in reverse priority queue (ascending order):" << endl;
    while (!reversePQ.empty()) {
        cout << reversePQ.top() << " ";
        reversePQ.pop();
    }

    return 0;
}
