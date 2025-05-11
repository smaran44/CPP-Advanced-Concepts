#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to find the kth largest element in an array using a Min-Heap
int kthLargest(vector<int>& nums, int k) {
    // Priority queue to implement a Min-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert first k elements into the min-heap
    for (int i = 0; i < k; i++) {
        minHeap.push(nums[i]); // Adding the first k elements into the heap
    }

    // Process remaining elements
    for (int i = k; i < nums.size(); i++) {
        // If the current element is greater than the root of the heap (the smallest in the heap)
        if (nums[i] > minHeap.top()) {
            minHeap.pop();  // Remove the smallest element
            minHeap.push(nums[i]);  // Insert the current element
        }
    }

    return minHeap.top();  // The root of the min-heap will be the kth largest element
}

// Function to merge k sorted arrays using a Min-Heap
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    // Min-Heap to store elements and track which array they belong to
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    vector<int> result;

    // Insert the first element from each array into the min-heap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            // Push a pair of (value, {array index, element index})
            minHeap.push({arrays[i][0], {i, 0}});
        }
    }

    // Extract the minimum element and move to the next element in the corresponding array
    while (!minHeap.empty()) {
        auto curr = minHeap.top();  // Get the smallest element
        minHeap.pop();  // Remove it from the heap
        result.push_back(curr.first);  // Add it to the result array

        int arrayIndex = curr.second.first;
        int elementIndex = curr.second.second;

        // If there's another element in the current array, push it into the heap
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
        }
    }

    return result;  // Return the merged sorted array
}

// Function to find the median of a stream of integers using two heaps
class MedianFinder {
private:
    priority_queue<int> maxHeap;  // Max-heap to store the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the larger half

public:
    // Adds a number into the data structure
    void addNum(int num) {
        maxHeap.push(num);  // Add the number to the maxHeap (for smaller half)

        // Balance the heaps if maxHeap has more than one extra element
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());  // Move the largest element from maxHeap to minHeap
            maxHeap.pop();
        }

        // Balance the heaps if minHeap has more elements than maxHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());  // Move the smallest element from minHeap to maxHeap
            minHeap.pop();
        }
    }

    // Returns the median of all elements so far
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();  // If maxHeap has more elements, return the top (median)
        }
        // If both heaps have equal size, return the average of the tops
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    // kth Largest Element in an Array
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "The " << k << "th largest element is: " << kthLargest(nums, k) << endl;

    // Merge K Sorted Arrays
    vector<vector<int>> arrays = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<int> merged = mergeKSortedArrays(arrays);
    cout << "Merged sorted array: ";
    for (int num : merged) {
        cout << num << " ";  // Print each element of the merged array
    }
    cout << endl;

    // Find the median of a stream
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median after adding 1 and 2: " << mf.findMedian() << endl;  // 1.5
    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << endl;  // 2

    return 0;
}
