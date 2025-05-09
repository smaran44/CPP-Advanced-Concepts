#include <iostream>
#include <vector>
#include <algorithm> // Required for upper_bound
using namespace std;

/*
    Purpose:
    --------
    This program demonstrates how to use the `upper_bound` function from the STL.

    What `upper_bound` does:
    ------------------------
    - It returns an iterator pointing to the **first element that is GREATER THAN ( > )** the target.
    - The vector must be **sorted** for correct results.
*/

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7, 9}; // Sorted vector

    int target = 4;

    // Apply upper_bound to find the first element > target
    auto it = upper_bound(arr.begin(), arr.end(), target);

    // Check if such an element exists in the array
    if (it != arr.end()) {
        // Print the index (distance from arr.begin()) where upper_bound is found
        cout << "Upper bound of " << target << " is at index: " << it - arr.begin() << endl;
    } else {
        // If all elements are <= target
        cout << "No element > " << target << " found." << endl;
    }

    return 0;
}
