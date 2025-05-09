#include <iostream>
#include <vector>
using namespace std;

/*
    What we are doing:
    --------------------
    This program finds the **last occurrence** of a target element in a **sorted array**.

    Concept:
    - This is similar to the first occurrence search, but here, after finding the target,
      we continue searching to the right to ensure we find the last occurrence.
    - This approach is helpful when duplicates exist in the sorted array.

    Time Complexity: O(log n)
*/

// Function to find the last occurrence of a target in a sorted array
int lastOccurrence(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = -1; // Stores the index of the last occurrence

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid to prevent overflow

        if (arr[mid] == target) {
            result = mid;           // Found target, update result
            low = mid + 1;          // Continue searching in the right half
        }
        else if (arr[mid] < target) low = mid + 1;  // Search right half
        else high = mid - 1;                        // Search left half
    }

    return result;  // Return the index of the last occurrence or -1 if not found
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};  // Sorted array with duplicates
    int target = 2;

    // Output the result
    cout << "Last Occurrence Index: " << lastOccurrence(arr, target);

    return 0;
}
