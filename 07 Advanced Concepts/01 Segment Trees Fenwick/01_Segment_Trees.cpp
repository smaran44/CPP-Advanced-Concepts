#include <iostream>
#include <vector>
using namespace std;

// Segment Tree class definition
class SegmentTree {
public:
    vector<int> tree;  // This will store the segment tree
    int n;  // Size of the original array

    // Constructor to initialize the tree with 4 times the size of the array
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);  // Allocate space for the segment tree
    }

    // Function to build the segment tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {  // If we reach a leaf node
            tree[node] = arr[start];  // Store the value at the leaf
        } else {
            int mid = (start + end) / 2;  // Find the middle index
            build(arr, 2 * node + 1, start, mid);  // Build the left child
            build(arr, 2 * node + 2, mid + 1, end);  // Build the right child
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Sum the values from left and right children
        }
    }

    // Function to query the sum in a range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;  // Out of range, return 0 (identity element for sum)
        }
        if (l <= start && end <= r) {
            return tree[node];  // Fully within range, return the value stored in the node
        }
        // Partially in range, split the query into left and right
        int mid = (start + end) / 2;
        int leftQuery = query(2 * node + 1, start, mid, l, r);  // Query the left subtree
        int rightQuery = query(2 * node + 2, mid + 1, end, l, r);  // Query the right subtree
        return leftQuery + rightQuery;  // Combine results from both subtrees
    }

    // Function to update the value at index 'idx'
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {  // If we reach the leaf node
            tree[node] = value;  // Update the value at the leaf
        } else {
            int mid = (start + end) / 2;  // Find the middle index
            if (start <= idx && idx <= mid) {  // If idx is in the left subtree
                update(2 * node + 1, start, mid, idx, value);  // Update the left child
            } else {  // If idx is in the right subtree
                update(2 * node + 2, mid + 1, end, idx, value);  // Update the right child
            }
            // After updating, we need to update the parent node to reflect the changes
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Update the current node value
        }
    }
};

int main() {
    int n = 5;  // Number of elements in the array
    vector<int> arr = {1, 2, 3, 4, 5};  // The input array

    // Create a segment tree for the array
    SegmentTree segTree(n);

    // Build the segment tree
    segTree.build(arr, 0, 0, n - 1);

    // Query the sum of elements in the range [1, 3]
    cout << "Sum in range [1, 3]: " << segTree.query(0, 0, n - 1, 1, 3) << endl;

    // Update the value at index 2 to 10
    segTree.update(0, 0, n - 1, 2, 10);

    // Query again after the update
    cout << "Sum in range [1, 3] after update: " << segTree.query(0, 0, n - 1, 1, 3) << endl;

    return 0;  // Return 0 to indicate successful execution
}
