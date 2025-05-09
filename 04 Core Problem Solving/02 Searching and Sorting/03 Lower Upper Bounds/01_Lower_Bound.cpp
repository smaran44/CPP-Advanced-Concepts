#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

/*
    Purpose:
    --------
    This program demonstrates how to use the `lower_bound` function from the STL.

    What `lower_bound` does:
    ------------------------
    - It returns an iterator pointing to the **first element that is NOT LESS THAN (>=)** the target.
    - The array/vector must be **sorted** for this function to work correctly.
*/

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7, 9}; // Sorted vector
    int target = 4;

    // Apply lower_bound to find the first element >= target
    auto it = lower_bound(arr.begin(), arr.end(), target);

    // Check if the returned iterator is within the array bounds
    if (it != arr.end()) {
        // Print the index (distance from arr.begin()) where lower_bound is found
        cout << "Lower bound of " << target << " is at index: " << it - arr.begin() << endl;
    } else {
        // If no such element exists
        cout << "No element >= " << target << " found." << endl;
    }

    return 0;
}
