#include <iostream>
#include <set>

using namespace std;

int main() {
    // Definition: A set is a collection of unique elements, stored in sorted order.

    set<int> numbers;

    // Inserting elements (only unique values are stored)
    numbers.insert(5);
    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(5); // Duplicate, will not be added

    // Displaying elements (automatically sorted)
    cout << "Set elements (sorted): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Checking if an element exists
    if (numbers.find(3) != numbers.end()) {
        cout << "3 is present in the set.\n";
    } else {
        cout << "3 is not present in the set.\n";
    }

    return 0;
}
