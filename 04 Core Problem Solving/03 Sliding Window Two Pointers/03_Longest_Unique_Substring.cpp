/*
    Program: Length of the Longest Substring Without Repeating Characters
    -----------------------------------------------------------------------
    What it does:
    - Finds the length of the longest substring in string `s` that contains no repeating characters.
    - Uses a sliding window approach to efficiently solve the problem in O(n) time.

    Logic used:
    - We maintain a sliding window using two pointers (`start` and `end`) to track the current substring.
    - An unordered map (`lastSeen`) is used to keep track of the most recent index of each character.
    - As we move the `end` pointer to the right, we update the `start` pointer to avoid repeating characters in the window.
    - The result is the length of the longest window without repeating characters.
*/

#include <iostream>        // For input/output operations
#include <unordered_map>   // For unordered_map (to store last seen indices)

using namespace std;

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;  // Stores the last index where each character was seen
    int maxLength = 0;  // Maximum length of substring found
    int start = 0;      // Start index of the current window (substring)

    // Loop through the string using `end` as the right pointer of the window
    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the character is inside the current window and has been seen before
        if (lastSeen.count(currentChar) && lastSeen[currentChar] >= start) {
            // Move `start` to one index after the last occurrence of the current character
            start = lastSeen[currentChar] + 1;  
        }

        // Update the last seen index for the current character
        lastSeen[currentChar] = end;  

        // Calculate the length of the current window and update maxLength if it's larger
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;  // Return the length of the longest substring
}

int main() {
    string input = "abcabcbb";  // Example input string
    cout << "Length of longest unique substring: "
         << lengthOfLongestSubstring(input) << endl;  // Output the result

    return 0;  // End of program
}
