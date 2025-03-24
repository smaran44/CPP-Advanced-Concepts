#include <iostream>
#include <list>

using namespace std;

int main() {
    // Definition: The `list` container in STL is a doubly linked list
    // It allows O(1) insertion and deletion at any position but has O(n) traversal time.

    // the difference between deque and list is that deque is implemented as a dynamic array, 
    // while list is implemented as a doubly linked list.
    // that means random access is not possible in list, but it is possible in deque.

    list<int> myList = {10, 20, 30, 40, 50}; // Initializing a list

    // Inserting elements
    myList.push_front(5);  // Insert at the front
    myList.push_back(60);   // Insert at the back

    // Displaying the list
    cout << "List elements: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // cout <<"second element: " << myList[1] << endl; we cant access random elements in list

    return 0;
}
