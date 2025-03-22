#include <iostream>

using namespace std;

/*
 * Segment Tree Construction (Divide & Conquer Approach)
 * -----------------------------------------------------
 * - Segment Trees are built using a **recursive approach**.
 * - Each node stores information for a range.
 * - **Divide & Conquer**: 
 *   🔹 Left child handles left half
 *   🔹 Right child handles right half
 */

void buildSegmentTree(int arr[], int segTree[], int node, int start, int end) {
    if (start == end) {
        // Leaf node, store array value
        segTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    // Recursively build left and right children
    buildSegmentTree(arr, segTree, 2 * node + 1, start, mid);
    buildSegmentTree(arr, segTree, 2 * node + 2, mid + 1, end);

    // Store sum in parent node (for sum queries)
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

int main() {
    cout << "Segment Trees use Recursion and Divide & Conquer to build efficiently!" << endl;
    return 0;
}
