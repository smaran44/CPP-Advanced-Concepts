#include <iostream>    // For input and output functions
#include <unordered_map> // To use unordered_map (hash map)
#include <vector>      // To use vectors (dynamic arrays)
#include <algorithm>   // To use algorithms like sort
using namespace std;

// Function to find the frequency of each element in the array
unordered_map<int, int> findFrequency(const vector<int>& nums) {
    unordered_map<int, int> freqMap;  // Declaring an unordered_map to store element frequencies
    for (int num : nums) {            // Loop through each element in the input array 'nums'
        freqMap[num]++;               // For each element, increment its frequency in freqMap
    }
    return freqMap;                   // Return the map containing element frequencies
}

// Function to find the most frequent element in the array
int mostFrequentElement(const vector<int>& nums) {
    unordered_map<int, int> freqMap = findFrequency(nums); // Call findFrequency to get the frequency map

    int maxCount = 0;  // Variable to store the maximum frequency
    int mostFrequent = nums[0];  // Initialize mostFrequent to the first element of the array

    // Iterate through the frequency map to find the element with the highest frequency
    for (auto& entry : freqMap) {
        if (entry.second > maxCount) {  // If current frequency is greater than maxCount
            maxCount = entry.second;  // Update the maxCount
            mostFrequent = entry.first;  // Update the mostFrequent element
        }
    }

    return mostFrequent;  // Return the most frequent element
}

// Function to find the top k frequent elements
vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freqMap = findFrequency(nums);  // Get the frequency map of the array

    // Create a vector of pairs (element, frequency)
    vector<pair<int, int>> freqVec;
    for (auto& entry : freqMap) {
        freqVec.push_back(entry);  // Add each element and its frequency to the vector
    }

    // Sort the vector based on frequency in descending order
    sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;  // Compare frequencies (second part of the pair)
    });

    // Extract the top k frequent elements
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqVec[i].first);  // Add the element with the highest frequency to the result
    }

    return result;  // Return the list of top k frequent elements
}

int main() {
    // Example: Finding frequency of elements in an array
    vector<int> nums = {1, 1, 1, 2, 2, 3};  // Input array
    unordered_map<int, int> freqMap = findFrequency(nums);  // Get frequency map for nums

    cout << "Element frequencies:" << endl;
    for (auto& entry : freqMap) {
        cout << "Element " << entry.first << " appears " << entry.second << " times." << endl;
    }

    // Example: Finding the most frequent element
    cout << "Most frequent element: " << mostFrequentElement(nums) << endl;

    // Example: Finding the top 2 most frequent elements
    vector<int> topK = topKFrequent(nums, 2);  // Get top 2 frequent elements
    cout << "Top 2 frequent elements: ";
    for (int num : topK) {
        cout << num << " ";  // Print each top k frequent element
    }
    cout << endl;

    return 0;  // End of the program
}
