#include <iostream>
#include <vector>
using namespace std;

// Function to find the unique element in an array where every other element appears twice
int findUnique(const vector<int> &arr) {
    int result = 0;
    // Loop through the array
    for (int num : arr) {
        // XOR all elements together
        // All duplicates cancel out because a ^ a = 0, and 0 ^ b = b, so only the unique element remains
        result ^= num;
    }
    return result; // Return the unique element
}

int main() {
    // Array where each element appears twice except for one unique element
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4};
    // Call the findUnique function and print the result
    cout << "The unique element is: " << findUnique(arr) << endl;
    return 0;
}
