#include <iostream>

using namespace std;

/*
 * What is a Segment Tree?
 * ------------------------
 * - A Segment Tree is a data structure used for answering **range queries** efficiently.
 * - It helps in operations like:
 *   ✅ Finding sum over a range
 *   ✅ Finding minimum/maximum in a range
 *   ✅ Updating elements efficiently
 * - Time Complexity:
 *   🔹 Build: O(N)
 *   🔹 Query: O(log N)
 *   🔹 Update: O(log N)
 * - Used in Competitive Programming for Range Queries.
 */

/*
 * Basic Structure of a Segment Tree:
 * ----------------------------------
 * - A Segment Tree is represented as an **array** (tree stored in an array).
 * - For an array of size N, segment tree needs **4*N** memory.
 * - Parent node stores information about a range of elements.
 * - Left child handles left half, Right child handles right half.
 *
 * Example:
 * --------
 * Given array: [1, 3, 5, 7, 9, 11]
 * Segment tree built for sum queries:
 *
 *                        [36]
 *                      /      \
 *                  [9]        [27]
 *                 /   \       /    \
 *              [4]   [5]   [16]    [11]
 *             /   \         /   \
 *          [1]   [3]    [7]    [9]
 */

int main() {
    cout << "A segment tree is usually represented as an array of size 4*N." << endl;
    return 0;
}
