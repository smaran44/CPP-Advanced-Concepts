/*
    Program: Find All Anagrams of String 'p' in String 's'
    --------------------------------------------------------
    What it does:
    - Finds all starting indices in string `s` where an anagram of string `p` is present.
    - Uses a sliding window approach and character frequency maps to detect anagrams efficiently.

    Logic used:
    - Build a frequency map (`unordered_map`) for string `p`.
    - Initialize a sliding window of the same length as `p` and track the character frequency in this window.
    - Slide the window across `s`, comparing the current window's frequency map with that of `p`. If they match, an anagram is found.
*/

#include <iostream>         // For input/output operations
#include <vector>           // For using vector container
#include <unordered_map>    // For unordered_map (frequency counting)

using namespace std;

// Helper function to compare two frequency maps
bool isSame(unordered_map<char, int>& a, unordered_map<char, int>& b) {
    for (auto& entry : a) {
        if (b[entry.first] != entry.second)  // If frequencies don't match, return false
            return false;
    }
    return true;  // Return true if all frequencies match
}
// For every character and its count in map a, check if map b has the same count for that character.
// If any character is missing or has a different count, return false.
// If all characters match in count, return true

// Main function to find all starting indices of anagrams of p in s
vector<int> findAnagrams(string s, string p) {
    int ns = s.length(), np = p.length();
    vector<int> result;  // To store the starting indices of anagrams
    if (ns < np) return result;  // If s is smaller than p, return empty result

    unordered_map<char, int> pCount, windowCount;

    // Build frequency map for p
    for (char ch : p) pCount[ch]++;

    // Initialize first window (first 'np' characters of s)
    for (int i = 0; i < np; i++) windowCount[s[i]]++;

    // Check for anagram in the first window
    if (isSame(pCount, windowCount)) result.push_back(0);

    // Slide the window over the rest of string s
    for (int i = np; i < ns; i++) {
        windowCount[s[i]]++;                    // Include new character in the window
        windowCount[s[i - np]]--;               // Remove the character that slides out
        if (windowCount[s[i - np]] == 0)        // Clean up: remove character if its count reaches zero
            windowCount.erase(s[i - np]);

        // If the frequency maps match, it's an anagram
        if (isSame(pCount, windowCount))
            result.push_back(i - np + 1);  // Store the starting index of the anagram
    }

    return result;  // Return the list of starting indices
}

int main() {
    string s = "cbaebabacd";  // Input string
    string p = "abc";         // String for which we find anagrams

    // Find the starting indices of anagrams of p in s
    vector<int> indices = findAnagrams(s, p);

    // Output the result
    cout << "Start indices of anagrams: ";
    for (int idx : indices) cout << idx << " ";  // Print each index

    return 0;  // End of program
}
