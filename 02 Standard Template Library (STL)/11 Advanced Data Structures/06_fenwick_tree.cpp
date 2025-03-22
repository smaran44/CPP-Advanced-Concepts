#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) class
class FenwickTree {
private:
    vector<int> BIT;  // Binary Indexed Tree (1-based index)
    int n;            // Size of the tree

    // Function to get the Least Significant Bit (LSB)
    int lsb(int x) { return x & -x; }

public:
    // Constructor to initialize the BIT with given size
    FenwickTree(int size) {
        n = size;
        BIT.resize(n + 1, 0); // Initialize BIT with 0s (1-based indexing)
    }

    // Function to update the Fenwick Tree at a specific index
    void update(int index, int value) {
        // Traverse and update all affected elements in the tree
        for (; index <= n; index += lsb(index)) {
            BIT[index] += value;  // Add the value to BIT[index]
        }
    }

    // Function to get the prefix sum from 1 to index
    int prefixSum(int index) {
        int sum = 0;
        // Traverse towards the root (index 0)
        for (; index > 0; index -= lsb(index)) {
            sum += BIT[index];  // Add the current BIT value to sum
        }
        return sum;
    }

    // Function to get the sum of elements in range [l, r]
    int rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};

// Main function to demonstrate Fenwick Tree usage
int main() {
    FenwickTree ft(6); // Create a Fenwick Tree of size 6

    // Updating values in Fenwick Tree
    ft.update(1, 1);  // Add 1 to index 1
    ft.update(2, 3);  // Add 3 to index 2
    ft.update(3, 5);  // Add 5 to index 3
    ft.update(4, 7);  // Add 7 to index 4
    ft.update(5, 9);  // Add 9 to index 5
    ft.update(6, 11); // Add 11 to index 6

    // Querying sum in range [1, 3]
    cout << "Sum of range (1, 3): " << ft.rangeSum(1, 3) << endl; 
    // Expected output: 1 + 3 + 5 = 9

    return 0;
}
