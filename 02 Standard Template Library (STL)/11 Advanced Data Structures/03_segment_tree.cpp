#include <iostream>
#include <vector>

using namespace std;

// Segment Tree : A data structure that allows efficient range queries and updates on an array.
// It is particularly useful for problems involving range queries like sum, minimum, maximum, etc.

// Class to implement a Segment Tree for range sum queries
class SegmentTree {
private:
    vector<int> tree;  // Segment tree stored as an array
    int n;  // Size of the original array

    // Build the segment tree recursively
    void buildTree(vector<int>& arr, int node, int start, int end) {
        // node is the index of the current node in the segment tree
        // start and end are the indices of the segment represented by this node
        if (start == end) {
            // Leaf node stores the value of the corresponding array element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build left and right subtrees
            buildTree(arr, 2 * node + 1, start, mid);      // Left child
            buildTree(arr, 2 * node + 2, mid + 1, end);    // Right child
            
            // Internal node stores the sum of both children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Function to compute the sum of elements in a given range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // No overlap: return 0 (this node does not contribute to the sum)
            return 0;
        }
        if (l <= start && end <= r) {
            // Complete overlap: return the sum stored at this node
            return tree[node];
        }

        // Partial overlap: Query both left and right children
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) +   // Left subtree
               query(2 * node + 2, mid + 1, end, l, r);  // Right subtree
    }

    // Function to update a specific index in the segment tree
    void update(int node, int start, int end, int index, int value) {
        if (start == end) {
            // If the leaf node corresponds to the index, update its value
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                // Update left subtree if the index lies in the left half
                update(2 * node + 1, start, mid, index, value);
            } else {
                // Otherwise, update right subtree
                update(2 * node + 2, mid + 1, end, index, value);
            }
            // Update the parent node after modifying the child
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    // Constructor: Initializes and builds the segment tree
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);  // Allocate enough space for segment tree
        buildTree(arr, 0, 0, n - 1);  // Build the segment tree
    }

    // Function to get the sum of elements in the range [l, r]
    int rangeSum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Function to update a specific element in the array
    void updateValue(int index, int value) {
        update(0, 0, n - 1, index, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};  // Input array
    SegmentTree segTree(arr);  // Create the segment tree

    // Query sum of elements in range [1, 3] (3 + 5 + 7 = 15)
    cout << "Sum of range (1, 3): " << segTree.rangeSum(1, 3) << endl;

    // Update value at index 2 from 5 to 10
    segTree.updateValue(2, 10);

    // Query again after the update (3 + 10 + 7 = 20)
    cout << "Sum of range (1, 3) after update: " << segTree.rangeSum(1, 3) << endl;

    return 0;
}
