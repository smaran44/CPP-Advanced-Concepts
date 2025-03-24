#include <iostream>
#include <set>

using namespace std;

int main() {
    // Definition: A set is a collection of unique elements, stored in sorted order.
    // it provides O(log N) time complexity for insert, delete, and search operations.
    // The set is implemented as a balanced binary search tree (usually a Red-Black tree).

    set<int> numbers;

    // Inserting elements (only unique values are stored)
    numbers.insert(5);
    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(5); // Duplicate, will not be added

    //size does not count duplicate elements
    cout << "Size of set: " << numbers.size() << endl; // Output: 3

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

    // lower_bound and upper_bound
    auto lb = numbers.lower_bound(3); // First element >= 3
    auto ub = numbers.upper_bound(3); // First element > 3
    cout << "Lower bound of 3: " << (lb != numbers.end() ? to_string(*lb) : "not found") << endl;
    cout << "Upper bound of 3: " << (ub != numbers.end() ? to_string(*ub) : "not found") << endl;

    return 0;
}
