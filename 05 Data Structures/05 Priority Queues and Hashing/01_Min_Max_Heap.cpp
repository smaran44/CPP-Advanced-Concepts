#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // For the reverse() function
using namespace std;

// Function to demonstrate Min-Heap
void minHeapExample() {
    // Creating a Min-Heap using a priority_queue with the 'greater' comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting elements into the Min-Heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(15);

    // Printing and removing elements from the Min-Heap in order (smallest to largest)
    cout << "Min-Heap elements (in order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";  // Print the top (smallest element)
        minHeap.pop();  // Remove the top element
    }
    cout << endl;  // Print newline after Min-Heap output
}

// Function to demonstrate Max-Heap
void maxHeapExample() {
    // Creating a Max-Heap using a priority_queue (default comparator is 'less', so it creates a Max-Heap)
    priority_queue<int> maxHeap;

    // Inserting elements into the Max-Heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(15);

    // Printing and removing elements from the Max-Heap in order (largest to smallest)
    cout << "Max-Heap elements (in order): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";  // Print the top (largest element)
        maxHeap.pop();  // Remove the top element
    }
    cout << endl;  // Print newline after Max-Heap output
}

// Function to find the k largest elements using a Min-Heap
vector<int> kLargestElements(const vector<int>& nums, int k) {
    // Min-Heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;

    // Loop through the elements of the array
    for (int num : nums) {
        minHeap.push(num);  // Insert the current element into the Min-Heap
        // If the heap size exceeds 'k', remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();  // Pop the smallest element to keep the heap size equal to 'k'
        }
    }

    // Now the heap contains the k largest elements, but in an unordered way
    // We need to extract them and store them in the result vector
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());  // Add the top (smallest) element in the heap to the result
        minHeap.pop();  // Remove the top element
    }

    // Reverse the result vector to get the largest elements in correct order (from largest to smallest)
    reverse(result.begin(), result.end());
    return result;  // Return the result containing the k largest elements
}

int main() {
    // Min-Heap demonstration
    cout << "Min-Heap example:" << endl;
    minHeapExample();

    // Max-Heap demonstration
    cout << "\nMax-Heap example:" << endl;
    maxHeapExample();

    // Example of finding k largest elements using a Min-Heap
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    vector<int> result = kLargestElements(nums, k);
    cout << "\n" << k << " largest elements: ";
    for (int num : result) {
        cout << num << " ";  // Print each of the k largest elements
    }
    cout << endl;

    return 0;  // Return 0 to indicate successful execution
}
