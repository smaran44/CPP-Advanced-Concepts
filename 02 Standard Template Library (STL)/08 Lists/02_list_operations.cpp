#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> myList = {10, 20, 30, 40, 50};

    // Removing elements
    myList.pop_front(); // Removes first element
    myList.pop_back();  // Removes last element

    // Removing a specific value
    myList.remove(30); // Removes all occurrences of 30

    // Displaying the modified list
    cout << "List after removals: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
