#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * next_permutation() & prev_permutation() - Generate the next or previous lexicographical permutation.
 * ---------------------------------------------------------------------------------------------------
 * - `next_permutation()` moves to the next greater arrangement.
 * - `prev_permutation()` moves to the previous smaller arrangement.
 * - If already the largest (for `next_permutation`) or smallest (for `prev_permutation`), it resets.
 * - Time Complexity: O(N) (worst case swaps elements in linear time).
 */

int main() {
    vector<int> v = {1, 2, 3};

    cout << "Original vector: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // Generate the next permutation
    if (next_permutation(v.begin(), v.end())) {
        cout << "Next permutation: ";
        for (int num : v) cout << num << " ";
    } else {
        cout << "No next permutation available (already the largest)";
    }
    cout << endl;

    // Generate the previous permutation
    if (prev_permutation(v.begin(), v.end())) {
        cout << "Previous permutation: ";
        for (int num : v) cout << num << " ";
    } else {
        cout << "No previous permutation available (already the smallest)";
    }
    cout << endl;

    return 0;
}
