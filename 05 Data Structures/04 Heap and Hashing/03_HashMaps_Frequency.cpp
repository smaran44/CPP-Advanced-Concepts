#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to find the frequency of each element in an array
void frequencyCount(vector<int>& nums) {
    unordered_map<int, int> freqMap;  // Map to store the frequency of each element

    // Count the frequency of each element in the array
    for (int num : nums) {
        freqMap[num]++;  // Increment the frequency of each element
    }

    // Print the frequency of each element
    for (auto& pair : freqMap) {
        cout << pair.first << " occurs " << pair.second << " times." << endl;
    }
}

// Function to find the top k frequent elements in an array
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;  // Map to store the frequency of each element

    // Count the frequency of each element in the array
    for (int num : nums) {
        freqMap[num]++;
    }

    // Create a vector of pairs (element, frequency) from the map
    vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());

    // Sort the vector based on frequency in descending order
    sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;  // Sort by frequency (second element of the pair)
    });

    // Extract the top k frequent elements
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqVec[i].first);  // Push the element into the result vector
    }

    return result;  // Return the top k frequent elements
}

// Function to find the longest substring with at most two distinct characters
int longestSubstringTwoDistinct(string s) {
    unordered_map<char, int> charCount;  // Map to store the count of characters in the current window
    int left = 0, maxLength = 0;  // Initialize the left pointer of the window and max length

    // Sliding window to find the longest valid substring with at most two distinct characters
    for (int right = 0; right < s.size(); right++) {
        charCount[s[right]]++;  // Increment the count of the character at the right pointer

        // If there are more than two distinct characters in the window, shrink the window
        while (charCount.size() > 2) {
            charCount[s[left]]--;  // Decrease the count of the character at the left pointer
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);  // Remove the character if its count becomes zero
            }
            left++;  // Move the left pointer to shrink the window
        }

        // Update the maximum length of the valid substring
        maxLength = max(maxLength, right - left + 1);  // Calculate the window size and update the result
    }

    return maxLength;  // Return the maximum length of the valid substring
}

int main() {
    // Frequency count in an array
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout << "Frequency count:" << endl;
    frequencyCount(nums);  // Output the frequency of each element in the array

    // Top K Frequent Elements
    vector<int> nums2 = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> topK = topKFrequent(nums2, k);  // Find the top k frequent elements
    cout << "\nTop " << k << " frequent elements: ";
    for (int num : topK) {
        cout << num << " ";  // Print each of the top k frequent elements
    }
    cout << endl;

    // Longest Substring with At Most Two Distinct Characters
    string s = "eceba";
    cout << "Longest substring with at most two distinct characters: " << longestSubstringTwoDistinct(s) << endl;

    return 0;
}
