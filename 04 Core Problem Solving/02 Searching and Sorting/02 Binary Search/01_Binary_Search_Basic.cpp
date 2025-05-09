#include <iostream>
#include <vector>
using namespace std;

/*
    What we are doing:
    --------------------
    Performing **Binary Search** to find the target in a **sorted array**.

    Concept:
    - Binary Search divides the search space in half each time.
    - Only works on sorted arrays.

    Time Complexity: O(log n)
*/

// Function to perform binary search
int binarySearch(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1; // Set initial bounds

    while (low <= high) {
        // Calculate middle index (to avoid overflow)
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;        // Target found
        else if (arr[mid] < target) low = mid + 1; // Search in right half
        else high = mid - 1;                       // Search in left half
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Must be sorted
    int target = 7;

    // Call binary search and store the result index
    int index = binarySearch(arr, target);

    // Output the result
    if (index != -1) 
        cout << "Found at index: " << index << endl;
    else 
        cout << "Not found" << endl;

    return 0;
}
