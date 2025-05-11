#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
    vector<int> tree;  // This stores the Fenwick tree array
    int n;  // Size of the original array

    // Constructor to initialize the tree with zero values
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0);  // Resize the tree to n+1 for 1-based indexing
    }

    // Function to update the value at index 'idx' by 'value'
    void update(int idx, int value) {
        // Update the Fenwick tree from index 'idx' upwards
        while (idx <= n) {
            tree[idx] += value;  // Add the value to the current index
            idx += idx & (-idx);  // Move to the next index (next parent)
        }
    }

    // Function to query the sum of elements from 1 to 'idx'
    int query(int idx) {
        int sum = 0;
        // Traverse the Fenwick tree upwards to calculate the sum
        while (idx > 0) {
            sum += tree[idx];  // Add the value of the current node to sum
            idx -= idx & (-idx);  // Move to the parent node (using binary trick)
        }
        return sum;
    }

    // Function to query the sum of elements in the range [l, r]
    int rangeQuery(int l, int r) {
        // The sum in range [l, r] is the sum from 1 to r minus the sum from 1 to l-1
        return query(r) - query(l - 1);
    }
};

int main() {
    int n = 5;  // Size of the array
    FenwickTree fenwickTree(n);  // Create a Fenwick Tree of size 5

    // Perform updates
    fenwickTree.update(1, 1);  // Add 1 at index 1
    fenwickTree.update(2, 2);  // Add 2 at index 2
    fenwickTree.update(3, 3);  // Add 3 at index 3
    fenwickTree.update(4, 4);  // Add 4 at index 4
    fenwickTree.update(5, 5);  // Add 5 at index 5

    // Query the sum in the range [1, 3]
    cout << "Sum in range [1, 3]: " << fenwickTree.rangeQuery(1, 3) << endl;

    return 0;  // Return 0 to indicate successful execution
}
