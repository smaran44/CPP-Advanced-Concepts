/*
    Program: Maximum Sum of Subarray of Size K
    ----------------------------------------------------
    What it does:
    - Finds the maximum sum of any subarray of a given size `k` within a list of integers.
    - Uses the sliding window technique to optimize the calculation.

    Logic used:
    - We calculate the sum of the first `k` elements (first window).
    - Then, slide the window one element at a time, adjusting the sum by subtracting the element that leaves the window and adding the element that enters.
    - This allows us to calculate the sum of each subarray of size `k` in O(n) time, avoiding recalculating the sum from scratch each time.
*/

#include <iostream>     // For input/output
#include <vector>       // For using vector container

using namespace std;

// Function to find the maximum sum of any subarray of size 'k'
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;  // Return -1 if the array size is less than 'k' (invalid case)

    int windowSum = 0, maxSum = 0;

    // Calculate the sum of the first 'k' elements (initial window)
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    maxSum = windowSum;  // Set maxSum to the sum of the first window

    // Slide the window over the rest of the array
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];  // Add new element, remove old element from the window
        maxSum = max(maxSum, windowSum);   // Update maxSum if we find a larger sum
    }

    return maxSum;  // Return the maximum sum found
}

int main() {
    // Example input: array and window size
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    // Output the result
    cout << "Maximum sum of subarray of size " << k << " is: " 
         << maxSumSubarray(arr, k) << endl;

    return 0;  // End of program
}
