#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets of the given array
void generateSubsets(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n; // 2^n subsets, where n is the size of the array

    // Iterate through all possible subsets (from 0 to 2^n - 1)
    for (int mask = 0; mask < total; mask++) {
        cout << "{ "; // Start of subset
        // Iterate over each element of the array
        for (int i = 0; i < n; i++) {
            // Check if the ith bit of mask is set (1)
            // If it is set, include the element nums[i] in the current subset
            if (mask & (1 << i)) {//mask & (1 << i) checks if the ith bit is set in the mask
                cout << nums[i] << " ";
            }
        }
        cout << "}" << endl; // End of subset and move to the next line
    }
}

int main() {
    // Example array for which we want to generate all subsets
    vector<int> nums = {1, 2, 3, 4};
    generateSubsets(nums); // Generate and print all subsets
    return 0;
}
