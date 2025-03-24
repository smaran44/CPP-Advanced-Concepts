#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element() and std::max_element()

using namespace std;

/*
 * Find Maximum and Minimum Elements in an Array using STL
 * -------------------------------------------------------
 * - Uses std::min_element() and std::max_element() from <algorithm>.
 * - Finds the smallest and largest elements in a vector.
 * - Works in O(N) time complexity.
 */

int main() {
    vector<int> v = {10, 20, 5, 30, 25}; // Example array

    if (v.empty()) {
        cout << "Vector is empty. Cannot find min and max." << endl;
        return 1;
    }

    cout << "Array elements: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // Using STL functions to find min and max
    auto minIt = min_element(v.begin(), v.end()); // Iterator to min element
    auto maxIt = max_element(v.begin(), v.end()); // Iterator to max element

    cout << "Minimum element: " << *minIt << endl;
    cout << "Maximum element: " << *maxIt << endl;

    return 0;
}
