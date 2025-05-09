#include <iostream>
#include <vector>
using namespace std;

/*
    What we are doing:
    --------------------
    This program finds the **first occurrence** of a target element in a **sorted array**.

    Concept:
    - Standard binary search is modified to continue searching to the left even after finding the target,
      ensuring that we find the first occurrence.
    - This is helpful in cases where duplicate values exist in the sorted array.

    Time Complexity: O(log n)
*/

// Function to find the first occurrence of a target in a sorted array
int firstOccurrence(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1; // Stores the index of the first occurrence

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid to prevent overflow

        if (arr[mid] == target) {
            result = mid;           // Found target, update result
            high = mid - 1;         // Continue searching in the left half
        }
        else if (arr[mid] < target) low = mid + 1;  // Search right half
        else high = mid - 1;                        // Search left half
    }

    return result;  // Return the index of the first occurrence or -1 if not found
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};  // Sorted array with duplicates
    int target = 2;

    // Output the result
    cout << "First Occurrence Index: " << firstOccurrence(arr, target);

    return 0;
}
