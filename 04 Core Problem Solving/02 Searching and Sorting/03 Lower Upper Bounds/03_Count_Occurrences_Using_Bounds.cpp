#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound and upper_bound
using namespace std;

/*
    Function: countOccurrences
    --------------------------
    Counts how many times a given target appears in a sorted array using STL.

    Explanation:
    - lower_bound returns the iterator to the first element >= target
    - upper_bound returns the iterator to the first element > target
    - The difference between upper and lower gives the total count of the target
*/
int countOccurrences(const vector<int>& arr, int target) {
    auto lower = lower_bound(arr.begin(), arr.end(), target); // first position >= target
    auto upper = upper_bound(arr.begin(), arr.end(), target); // first position > target

    return upper - lower; // difference is the count of 'target' in the array
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 6, 8}; // Sorted array
    int target = 4;

    // Display the number of occurrences of the target element
    cout << "Occurrences of " << target << ": " << countOccurrences(arr, target) << endl;

    return 0;
}
