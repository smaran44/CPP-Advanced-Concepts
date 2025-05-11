#include <iostream>   // For input-output operations
#include <vector>     // For using the vector data structure
using namespace std;  // This allows us to use standard library names without prefixing them with 'std::'

// Function to find the number of ways to climb to the nth step
int climbStairs(int n) {
    // Base cases: If there's 1 step, there's only 1 way to climb it, and for 2 steps, there are 2 ways
    if (n == 1) return 1;  // If there's only one step, the only way is to take one step
    if (n == 2) return 2;  // If there are two steps, there are two ways: 1+1 or 2

    // DP array to store the number of ways to reach each step from 1 to n
    vector<int> dp(n + 1);  // We create a vector of size n+1, to store the result for each step from 0 to n
    dp[1] = 1;  // There's 1 way to reach the first step (take 1 step)
    dp[2] = 2;  // There are 2 ways to reach the second step (1+1 or 2)

    // Use the DP array to fill in the number of ways for each step
    for (int i = 3; i <= n; i++) {
        // The number of ways to reach the ith step is the sum of the ways to reach the (i-1)th and (i-2)th steps
        dp[i] = dp[i - 1] + dp[i - 2];  // From (i-1)th step (take 1 step) or (i-2)th step (take 2 steps)
    }

    return dp[n];  // Return the result for the nth step, which will be stored in dp[n]
}

int main() {
    int n;
    cout << "Enter the number of steps: ";  // Prompt user to enter the number of steps in the staircase
    cin >> n;  // Read input for the number of steps

    // Output the number of ways to climb the staircase based on the value of n
    cout << "Number of ways to climb the staircase: " << climbStairs(n) << endl;
    return 0;  // Return 0 to indicate successful execution
}
