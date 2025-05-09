#include <iostream>
#include <vector>
using namespace std;

/*
    Algorithm: Merge Sort
    -----------------------
    What we are doing:
    - Divide the array into two halves.
    - Recursively sort each half.
    - Merge the sorted halves back together.

    Time Complexity: O(n log n) (Divide and Conquer)
*/

// Merge two sorted halves of the array
void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> temp;       // Temporary array to store merged result
    int i = l, j = mid + 1; // Pointers for left and right halves

    // Compare and merge the elements
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    // Add remaining elements from left half (if any)
    while (i <= mid) temp.push_back(arr[i++]);

    // Add remaining elements from right half (if any)
    while (j <= r) temp.push_back(arr[j++]);

    // Copy merged result back to original array
    for (int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }
}

// Recursive function to divide and sort the array
void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return; // Base case: one element

    int mid = l + (r - l) / 2; // Find the middle index

    mergeSort(arr, l, mid);       // Sort left half
    mergeSort(arr, mid + 1, r);   // Sort right half
    merge(arr, l, mid, r);        // Merge the two halves
}

int main() {
    vector<int> arr = {6, 3, 9, 5, 2, 8};

    mergeSort(arr, 0, arr.size() - 1); // Sort the array

    // Print sorted array
    for (int num : arr) cout << num << " ";

    return 0;
}
