/*
    Efficient Data Structures & Algorithms in C++
    ------------------------------------------------
    - Optimized data structures improve performance and efficiency.
    - Algorithms with lower time complexity execute faster.
    - Examples: Fast lookups using unordered_map, binary search for sorted data.

    Benchmarking & Profiling Tools
    ------------------------------
    - Benchmarking measures execution time and compares performance.
    - Profiling helps analyze bottlenecks and optimize code.
    - The chrono library in C++ provides high-precision timing for performance measurement.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>  // For binary_search
#include <chrono>     // For benchmarking execution time

using namespace std;

/*
 *  Key Concepts in this Program:
 * 1. Using `unordered_map` for **fast lookups** (O(1) average case).
 * 2. Using **binary search** on a sorted array (O(log N)).
 * 3. Using `chrono` library to **benchmark execution time** of an algorithm.
 */

// 1. Fast lookups using unordered_map (O(1) average case)
void fastLookupExample() {
    unordered_map<string, int> ageMap = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 22}
    };

    cout << "Alice's Age: " << ageMap["Alice"] << endl; // O(1) lookup operation
}

// 2. Binary Search on a sorted array (O(log N))
bool binarySearchExample(const vector<int>& arr, int key) {
    /*
     * Binary search requires a **sorted array**.
     * - If the key is found, returns `true`.
     * - If not found, returns `false`.
     * - Time complexity: **O(log N)**
     */
    return binary_search(arr.begin(), arr.end(), key);
}

// 3. Benchmarking execution time using chrono
void benchmarkExample() {
    /*
     * Benchmarking Concept:
     * - Measures how long a function or algorithm takes to execute.
     * - Helps identify slow operations and improve efficiency.
     * - Uses `chrono::high_resolution_clock` for precise timing.
     */

    // Creating a large sorted array (1 million elements)
    vector<int> largeArray(1000000);
    for (int i = 0; i < 1000000; ++i) {
        largeArray[i] = i;  // Filling the array with sequential numbers
    }

    int key = 999999; // Key to search

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    // Perform binary search
    bool found = binarySearchExample(largeArray, key);

    // End measuring time
    auto end = chrono::high_resolution_clock::now();

    // Compute execution duration in milliseconds
    chrono::duration<double, milli> duration = end - start;

    cout << "Binary search execution time: " << duration.count() << " ms" << endl;
}

int main() {
    // Demonstrate fast lookup using unordered_map
    cout << "\nFast Lookup Example:\n";
    fastLookupExample();

    // Demonstrate binary search
    cout << "\nBinary Search Example:\n";
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11}; // Must be sorted for binary search
    int key = 5;
    
    if (binarySearchExample(sortedArray, key)) {
        cout << "Key " << key << " found in array." << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }

    // Benchmarking example
    cout << "\nBenchmarking Example:\n";
    benchmarkExample();

    return 0;
}