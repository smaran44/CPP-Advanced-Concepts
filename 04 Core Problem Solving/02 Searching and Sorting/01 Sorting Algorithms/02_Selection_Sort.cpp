#include <iostream>
#include <vector>
using namespace std;

/*
    Algorithm: Selection Sort
    --------------------------
    What we are doing:
    - Divide the array into a sorted and unsorted part.
    - Repeatedly find the minimum element from the unsorted part
      and put it at the beginning of the sorted part.

    Time Complexity: O(n^2)
*/

// Selection Sort implementation
void selectionSort(vector<int> &arr) {
    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n; i++) {
        int minIdx = i; // Assume the current index is the minimum

        // Find the actual minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Swap the found minimum element with the current index
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 13};

    selectionSort(arr); // Sort the array

    // Print the sorted array
    for (int num : arr) cout << num << " ";

    return 0;
}
