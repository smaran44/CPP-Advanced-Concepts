#include <iostream>

using namespace std;

/*
 * What is a Fenwick Tree (Binary Indexed Tree - BIT)?
 * ---------------------------------------------------
 * - A Fenwick Tree (or BIT) is a data structure used for:
 *   ✅ Efficiently computing prefix sums
 *   ✅ Updating values in logarithmic time
 * - It provides:
 *   🔹 Query in O(log N)
 *   🔹 Update in O(log N)
 * - More memory efficient than a Segment Tree (uses N size instead of 4*N)
 * - Useful in Competitive Programming for **range sum queries & updates**.
 */

/*
 * Basic Structure of a Fenwick Tree (BIT)
 * ---------------------------------------
 * - BIT is represented as a **1-based indexed array**.
 * - To update or query, we move through indices using **Least Significant Bit (LSB)**.
 *
 * Example:
 * --------
 * Given array: [1, 3, 5, 7, 9, 11]
 * Fenwick Tree stores prefix sums in a way that allows:
 *   ✅ Fast updates (O(log N))
 *   ✅ Fast prefix sum queries (O(log N))
 *
 * BIT Indexing (1-based):
 * ------------------------
 * Original Array:    [1, 3, 5, 7, 9, 11]
 * BIT Representation:
 * Index 1 -> Sum of first 1 element
 * Index 2 -> Sum of first 2 elements
 * Index 4 -> Sum of first 4 elements
 * Index 8 -> Sum of first 8 elements (if exists)
 */

int main() {
    cout << "A Fenwick Tree (BIT) is usually represented as a 1-based indexed array." << endl;
    return 0;
}
