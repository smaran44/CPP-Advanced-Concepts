#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for greater
using namespace std;

// Function to merge k sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    // Create a Min-Heap using priority_queue with the 'greater' comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all elements from all arrays into the min-heap
    for (auto& array : arrays) {
        for (int num : array) {
            minHeap.push(num);  // Push each element into the Min-Heap
        }
    }

    // Extract elements from the heap and put them into the result vector in sorted order
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());  // Get the smallest element
        minHeap.pop();  // Remove the smallest element from the heap
    }

    return result;  // Return the sorted array
}

// Function to find the kth largest element in an array
int kthLargestElement(vector<int>& nums, int k) {
    // Create a Max-Heap using the priority_queue (default comparator)
    priority_queue<int> maxHeap;

    // Insert all elements into the Max-Heap
    for (int num : nums) {
        maxHeap.push(num);  // Push each element into the Max-Heap
    }

    // Extract the top element k times to find the kth largest element
    for (int i = 1; i < k; i++) {
        maxHeap.pop();  // Remove the largest element (top of the Max-Heap)
    }

    return maxHeap.top();  // The kth largest element will be at the top
}

// Function to find the kth smallest element in an array using a max-heap
int kthSmallestElement(vector<int>& nums, int k) {
    // Create a Max-Heap using the priority_queue (default comparator)
    priority_queue<int> maxHeap;

    // Build a Max-Heap with the first k elements
    for (int i = 0; i < k; i++) {
        maxHeap.push(nums[i]);  // Insert the first k elements into the Max-Heap
    }

    // Process the remaining elements and replace the root of the heap if the element is smaller
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] < maxHeap.top()) {
            maxHeap.pop();  // Remove the largest element
            maxHeap.push(nums[i]);  // Insert the smaller element
        }
    }

    return maxHeap.top();  // The kth smallest element will be at the top of the Max-Heap
}

int main() {
    // Merge K sorted arrays example
    vector<vector<int>> arrays = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<int> mergedArray = mergeKSortedArrays(arrays);  // Merge arrays into a single sorted array
    cout << "Merged K sorted arrays: ";
    for (int num : mergedArray) {
        cout << num << " ";  // Print the merged array
    }
    cout << endl;

    // Find the kth largest element example
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << k << "th largest element: " << kthLargestElement(nums, k) << endl;

    // Find the kth smallest element example
    cout << k << "th smallest element: " << kthSmallestElement(nums, k) << endl;

    return 0;  // Return 0 to indicate successful execution
}
