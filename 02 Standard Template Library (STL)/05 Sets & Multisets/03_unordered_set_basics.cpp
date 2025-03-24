#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Definition: An unordered_set stores unique elements using hashing.
    //it provides O(1) average time complexity for insert, delete, and search operations.

    unordered_set<int> numbers;

    // Inserting elements (only unique values are stored)
    numbers.insert(5);
    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(5); // Duplicate, will not be added

    // Displaying elements (order is not guaranteed)
    cout << "Unordered set elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // lower_bound and upper_bound are not available in unordered_set
    // Instead, we can use find() to check for existence

    return 0;
}
