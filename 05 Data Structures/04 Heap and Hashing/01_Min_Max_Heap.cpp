#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Min Heap class
class MinHeap {
private:
    vector<int> heap; // Vector to store the heap elements

    // Function to maintain the heap property by heapifying down
    void heapify(int index) {
        int smallest = index; // Start with the current index as the smallest
        int left = 2 * index + 1; // Left child index
        int right = 2 * index + 2; // Right child index

        // If left child is smaller than the smallest element
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // If right child is smaller than the smallest element
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // If the smallest is not the current element, swap and heapify again
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify(smallest); // Recur to continue restoring the heap property
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int val) {
        heap.push_back(val); // Add the new element at the end of the heap
        int index = heap.size() - 1; // Get the index of the newly added element

        // Heapify upwards to restore the heap property
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]); // Swap with the parent
            index = (index - 1) / 2; // Move to the parent index
        }
    }

    // Function to remove the root element (minimum)
    int remove() {
        if (heap.size() == 0) return -1; // Return -1 if heap is empty

        int root = heap[0]; // Store the root value
        heap[0] = heap.back(); // Move the last element to the root
        heap.pop_back(); // Remove the last element
        heapify(0); // Heapify down from the root to restore the heap property

        return root; // Return the old root value
    }

    // Function to get the root element (minimum)
    int getMin() {
        return heap.size() > 0 ? heap[0] : -1; // Return the root, or -1 if heap is empty
    }
};

// Max Heap class
class MaxHeap {
private:
    vector<int> heap; // Vector to store the heap elements

    // Function to maintain the heap property by heapifying down
    void heapify(int index) {
        int largest = index; // Start with the current index as the largest
        int left = 2 * index + 1; // Left child index
        int right = 2 * index + 2; // Right child index

        // If left child is larger than the largest element
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        // If right child is larger than the largest element
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        // If the largest is not the current element, swap and heapify again
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest); // Recur to continue restoring the heap property
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int val) {
        heap.push_back(val); // Add the new element at the end of the heap
        int index = heap.size() - 1; // Get the index of the newly added element

        // Heapify upwards to restore the heap property
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]); // Swap with the parent
            index = (index - 1) / 2; // Move to the parent index
        }
    }

    // Function to remove the root element (maximum)
    int remove() {
        if (heap.size() == 0) return -1; // Return -1 if heap is empty

        int root = heap[0]; // Store the root value
        heap[0] = heap.back(); // Move the last element to the root
        heap.pop_back(); // Remove the last element
        heapify(0); // Heapify down from the root to restore the heap property

        return root; // Return the old root value
    }

    // Function to get the root element (maximum)
    int getMax() {
        return heap.size() > 0 ? heap[0] : -1; // Return the root, or -1 if heap is empty
    }
};

// Driver code to test MinHeap and MaxHeap
int main() {
    MinHeap minHeap;
    MaxHeap maxHeap;

    // Insert elements into MinHeap
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(4);

    // MinHeap Operations
    cout << "Min Heap Root: " << minHeap.getMin() << endl;  // Output: 1 (smallest element)
    cout << "Min Heap Remove: " << minHeap.remove() << endl;  // Output: 1 (removes the root, 1)
    cout << "Min Heap Root after remove: " << minHeap.getMin() << endl;  // Output: 2 (new root after removal)

    // Insert elements into MaxHeap
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(1);
    maxHeap.insert(4);

    // MaxHeap Operations
    cout << "Max Heap Root: " << maxHeap.getMax() << endl;  // Output: 4 (largest element)
    cout << "Max Heap Remove: " << maxHeap.remove() << endl;  // Output: 4 (removes the root, 4)
    cout << "Max Heap Root after remove: " << maxHeap.getMax() << endl;  // Output: 3 (new root after removal)

    return 0;
}
