#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq = {10, 20, 30, 40, 50}; // Initializing deque with values

    // Removing elements from front and back
    dq.pop_front(); // Removes 10
    dq.pop_back();  // Removes 50

    // Displaying updated deque
    cout << "Deque after pop operations: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    // Checking if deque is empty
    if (dq.empty()) {
        cout << "Deque is empty." << endl;
    } else {
        cout << "Deque is not empty." << endl;
    }

    return 0;
}
