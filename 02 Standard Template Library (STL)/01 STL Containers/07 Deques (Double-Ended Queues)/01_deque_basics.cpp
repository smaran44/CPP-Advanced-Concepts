#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Definition: A deque (double-ended queue) allows efficient insertions and deletions
    // at both the front and back in O(1) time.

    deque<int> dq; // Declaring a deque

    // Pushing elements at the back
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Pushing elements at the front
    dq.push_front(5);
    dq.push_front(1);

    // Displaying the deque elements
    cout << "Deque elements: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    // Accessing front and back elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    return 0;
}
