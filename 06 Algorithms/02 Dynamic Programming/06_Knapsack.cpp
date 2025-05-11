#include <iostream>   // For input-output operations
#include <vector>     // For using the vector data structure
#include <algorithm>  // For using the max() function
using namespace std;  // This allows us to use standard library names without prefixing them with 'std::'

// Function to solve the 0/1 Knapsack problem using Dynamic Programming (DP)
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // DP table to store the maximum value for each item and weight combination
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table by checking each item and weight combination
    for (int i = 1; i <= n; i++) {  // Loop over all items
        for (int w = 1; w <= W; w++) {  // Loop over all possible weights
            if (wt[i - 1] <= w) {  // If the weight of the current item is less than or equal to the current capacity
                // Either include the current item or exclude it, and take the maximum value
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                // If the current item's weight exceeds the capacity, don't include it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result will be stored in the bottom-right cell of the DP table
    return dp[n][W]; // Return the maximum value that can be obtained for the given knapsack capacity
}

int main() {
    int n, W;
    cout << "Enter number of items: ";  // Prompt for the number of items
    cin >> n;  // Read the number of items

    vector<int> val(n), wt(n);  // Arrays to store values and weights of the items
    cout << "Enter values of the items: ";  // Prompt for the values of the items
    for (int i = 0; i < n; i++) {  // Read the values of the items
        cin >> val[i];
    }

    cout << "Enter weights of the items: ";  // Prompt for the weights of the items
    for (int i = 0; i < n; i++) {  // Read the weights of the items
        cin >> wt[i];
    }

    cout << "Enter capacity of the knapsack: ";  // Prompt for the knapsack capacity
    cin >> W;  // Read the knapsack capacity

    // Output the maximum value that can be obtained in the knapsack
    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;  // Return 0 to indicate successful execution
}
