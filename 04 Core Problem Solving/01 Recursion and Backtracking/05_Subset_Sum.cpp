#include <iostream>
#include <vector>
using namespace std;

/*
    Program: Find all subsets of an array whose elements sum up to a given target
    ------------------------------------------------------------------------------
    What we are doing:
    - Given an array of integers and a target sum, we find all combinations (subsets) 
      where the sum of selected elements equals the target.
    - We use recursion and backtracking to explore:
        1. Including an element
        2. Excluding an element
    - When we reach the end of the array, we check if the current subset sum equals the target.

    Concept used: Recursion + Backtracking – try each element in the subset and backtrack.
*/

// Recursive function to find subsets with target sum
void subsetSum(int index, vector<int> &arr, vector<int> &current, int currentSum, int target) {
    // Base case: if we reached the end of the array
    if (index == arr.size()) {
        // If the current subset's sum equals target, print it
        if (currentSum == target) {
            for (int num : current) cout << num << " ";
            cout << endl;
        }
        return;
    }

    // Include current element in the subset
    current.push_back(arr[index]);
    subsetSum(index + 1, arr, current, currentSum + arr[index], target);

    // Backtrack: remove the element and move to the next
    current.pop_back();
    subsetSum(index + 1, arr, current, currentSum, target);
}

int main() {
    // Input array
    vector<int> arr = {1, 2, 1};

    // Target sum to achieve
    int target = 2;

    cout << "Subsets with sum " << target << ":\n";

    // To store the current subset
    vector<int> current;

    // Start recursive function from index 0, current sum 0
    subsetSum(0, arr, current, 0, target);

    return 0;
}
/*
Start: []
|
|-- Include 1 ➝ [1] (sum = 1)
|   |
|   |-- Include 2 ➝ [1, 2] (sum = 3)
|   |   |
|   |   |-- Include 1 ➝ [1, 2, 1] (sum = 4) ❌ (not printed)
|   |   |-- Exclude 1 ➝ [1, 2] (sum = 3) ❌
|   |
|   |-- Exclude 2 ➝ [1] (sum = 1)
|       |
|       |-- Include 1 ➝ [1, 1] (sum = 2) ✅ ✔️
|       |-- Exclude 1 ➝ [1] (sum = 1)
|
|-- Exclude 1 ➝ [] (sum = 0)
    |
    |-- Include 2 ➝ [2] (sum = 2) ✅ ✔️
    |   |
    |   |-- Include 1 ➝ [2, 1] (sum = 3) ❌
    |   |-- Exclude 1 ➝ [2] (sum = 2) ✅ ✔️
    |
    |-- Exclude 2 ➝ [] (sum = 0)
        |
        |-- Include 1 ➝ [1] (sum = 1)
        |-- Exclude 1 ➝ [] (sum = 0)
*/