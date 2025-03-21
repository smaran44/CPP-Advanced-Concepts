#include <iostream>
#include <set>

using namespace std;

int main() {
    // Definition: A multiset allows duplicate elements and stores them in sorted order.

    multiset<int> numbers;

    // Inserting elements (duplicates are allowed)
    numbers.insert(5);
    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(5); // Duplicate is allowed

    // Displaying elements (duplicates are stored)
    cout << "Multiset elements (sorted with duplicates): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Erasing only one occurrence of an element
    numbers.erase(numbers.find(5)); // Removes only one instance of 5

    cout << "After erasing one occurrence of 5: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
