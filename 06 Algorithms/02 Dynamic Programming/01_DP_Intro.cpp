#include <iostream>   // For input-output operations
#include <vector>     // For using the vector data structure
#include <algorithm>  // For using standard algorithms (though not needed in this code)
using namespace std;  // This allows us to use standard library names without prefixing them with 'std::'

// Function to compute the nth Fibonacci number using Dynamic Programming (Bottom-up approach)
int fib(int n) {
    if (n <= 1) return n; // Base case: If n is 0 or 1, return n directly as F(0) = 0 and F(1) = 1

    // DP array to store Fibonacci numbers (bottom-up approach)
    vector<int> dp(n + 1, 0); // Create a vector of size n+1 initialized to 0
    dp[1] = 1;  // The 1st Fibonacci number is 1, so we manually set dp[1] = 1

    // Fill the dp array using the recurrence relation
    for (int i = 2; i <= n; i++) {
        // The Fibonacci sequence is defined as F(n) = F(n-1) + F(n-2)
        dp[i] = dp[i - 1] + dp[i - 2];  // Calculate Fibonacci for each index starting from 2
    }

    return dp[n];  // Return the nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter the value of n to compute Fibonacci: ";  // Prompt user to enter the value of n
    cin >> n;  // Read the input value for n from user

    // Output the nth Fibonacci number calculated by the fib function
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
    return 0;  // Return 0 to indicate successful execution
}
