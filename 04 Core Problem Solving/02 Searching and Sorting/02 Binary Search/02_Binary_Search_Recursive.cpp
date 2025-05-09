#include <iostream>
#include <vector>
using namespace std;

/*
    What we are doing:
    --------------------
    Performing **Binary Search using Recursion** to find a target in a **sorted array**.

    Concept:
    - Divide the array into halves recursively and search in the appropriate half.
    - Only works if the array is **sorted**.

    Time Complexity: O(log n)
*/

// Recursive binary search function
int binarySearchRec(const vector<int> &arr, int low, int high, int target) {
    // Base case: if the range is invalid
    if (low > high) return -1;

    // Calculate mid to avoid overflow
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;              // Target found
    else if (arr[mid] > target)                      // Search in left half
        return binarySearchRec(arr, low, mid - 1, target);
    else                                             // Search in right half
        return binarySearchRec(arr, mid + 1, high, target);
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12}; // Must be sorted
    int target = 6;

    // Call recursive binary search
    int index = binarySearchRec(arr, 0, arr.size() - 1, target);

    // Output result
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
