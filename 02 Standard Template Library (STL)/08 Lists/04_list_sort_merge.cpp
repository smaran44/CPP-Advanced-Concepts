#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> myList = {40, 10, 50, 20, 30};

    // Sorting the list
    myList.sort();

    cout << "Sorted list: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // Merging another sorted list
    list<int> anotherList = {15, 25, 35};
    myList.merge(anotherList);

    cout << "Merged sorted list: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // Merging another unsorted list
    list<int> unsortedList = {5, 65, 35, 25};
    myList.merge(unsortedList);

    cout << "Merged  list: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    // this will not work

    return 0;
}
