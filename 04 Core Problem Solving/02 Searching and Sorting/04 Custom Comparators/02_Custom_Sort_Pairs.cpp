/*
    Program: Custom Sort of Pairs
    -----------------------------------------
    What it does:
    - Sorts a vector of pairs (int, int) using custom logic.
    - Sorting rule:
        → First, sort by the **second value in ascending** order.
        → If the second values are equal, sort by the **first value in descending** order.

    Logic used:
    - Uses `std::sort()` with a custom comparator function to achieve the sorting logic.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort pairs by second value ascending, if equal, by first descending
bool customPairSort(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;  // If second elements are equal, sort by first in descending order
    return a.second < b.second;   // Otherwise, sort by second in ascending order
}

int main() {
    // Initialize a vector of pairs
    vector<pair<int, int>> v = {
        {1, 3},
        {2, 2},
        {3, 2},
        {4, 3}
    };

    // Sort the vector using the custom comparator
    sort(v.begin(), v.end(), customPairSort);

    // Print the sorted pairs
    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;  // End of program
}
