#include <iostream>   // For input-output operations
#include <vector>     // For using the vector data structure
#include <algorithm>  // For using standard algorithms (although not used here directly)
using namespace std;  // This allows us to use standard library names without prefixing them with 'std::'

// Function to find the length of the Longest Common Subsequence (LCS) of two strings
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();  // Length of the first string
    int n = text2.size();  // Length of the second string

    // DP table to store results of subproblems
    // dp[i][j] will store the length of LCS of text1[0..i-1] and text2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  // Initialize table with 0s

    // Fill the DP table using the recurrence relations
    for (int i = 1; i <= m; i++) {  // Iterate through each character of the first string
        for (int j = 1; j <= n; j++) {  // Iterate through each character of the second string
            if (text1[i - 1] == text2[j - 1]) {  // If characters match
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Increment the LCS length from the previous diagonal value
            } else {
                // Otherwise, take the maximum value from excluding one character from either string
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The bottom-right cell of the table contains the length of the LCS of the two strings
    return dp[m][n];  // Return the final value
}

int main() {
    string text1, text2;
    cout << "Enter first string: ";  // Prompt user to enter the first string
    cin >> text1;  // Read the first string
    cout << "Enter second string: ";  // Prompt user to enter the second string
    cin >> text2;  // Read the second string

    // Output the length of the longest common subsequence calculated by the LCS function
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(text1, text2) << endl;
    return 0;  // Return 0 to indicate successful execution
}
