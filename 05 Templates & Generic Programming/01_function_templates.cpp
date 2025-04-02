/*
    Function Templates in C++
    --------------------------
    - Function templates allow writing generic functions that work with different data types.
    - Instead of writing multiple versions of the same function for different types, we define a single template.
    - This is useful for code reusability and reduces redundancy in DSA & CP.
*/

#include <iostream>

using namespace std;

// Function Template: Works for multiple data types
template <typename T> // 'T' is a placeholder for any data type
T findMax(T a, T b) {
    return (a > b) ? a : b; // Returns the larger of the two values
}

int main() {
    // Calling findMax() with different data types
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;      // Works with int
    cout << "Max of 5.5 and 2.2: " << findMax(5.5, 2.2) << endl;  // Works with double
    cout << "Max of 'A' and 'B': " << findMax('A', 'B') << endl;  // Works with char (compares ASCII values)
    
    return 0;
}

