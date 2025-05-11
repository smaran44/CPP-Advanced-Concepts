#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to return the maximum in each sliding window of size k
vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq; // deque stores indices of elements, maintaining the order of potential maximums
    vector<int> result; // Vector to store the result (maximums for each window)

    // Iterate through all elements of the array
    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements from front of deque if they are outside the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front(); // Remove the front element if it's outside the window
        }

        // Remove smaller elements from the back of the deque
        // These elements can no longer be the maximum if the current element is greater
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back(); // Remove elements smaller than the current one
        }

        // Add the current element index to the deque
        dq.push_back(i);

        // Start recording the maximum when the first window is complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]); // The front of deque is the maximum for the current window
        }
    }

    return result; // Return the result containing maximums for each window
}

// Function to print a vector (for debugging and displaying results)
void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " "; // Print each element in the vector
    cout << endl;
}

// Driver Code
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7}; // Example array
    int k = 3; // Window size
    cout << "Original Array:\n";
    printVector(nums); // Print the original array

    vector<int> maxInWindow = slidingWindowMaximum(nums, k); // Get the sliding window maximums
    cout << "Sliding Window Maximums (k = " << k << "):\n";
    printVector(maxInWindow); // Print the result (maximums for each window)

    return 0;
}
