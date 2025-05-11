#include <iostream>   // For input-output operations
#include <vector>     // For using the vector data structure
#include <algorithm>  // For using standard algorithms like max_element
using namespace std;  // This allows us to use standard library names without prefixing them with 'std::'

// Function to find the length of the Longest Increasing Subsequence (LIS)
int longestIncreasingSubsequence(vector<int>& nums) {
    if (nums.empty()) return 0;  // If the input vector is empty, there is no subsequence, return 0

    vector<int> dp(nums.size(), 1);  // Initialize the DP array, where dp[i] will store the length of LIS ending at index i

    // Fill the DP array
    for (int i = 1; i < nums.size(); i++) {  // Start iterating from the second element
        for (int j = 0; j < i; j++) {  // Compare nums[i] with all previous elements nums[j] (where j < i)
            if (nums[i] > nums[j]) {  // If nums[i] is greater than nums[j], it can form a longer subsequence
                dp[i] = max(dp[i], dp[j] + 1);  // Update dp[i] to the maximum subsequence length found by including nums[i]
            }
        }
    }

    return *max_element(dp.begin(), dp.end());  // The result is the maximum value in the dp array, which represents the length of the longest subsequence
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};  // Example input array

    // Output the length of the longest increasing subsequence
    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums) << endl;
    return 0;  // Return 0 to indicate successful execution
}
