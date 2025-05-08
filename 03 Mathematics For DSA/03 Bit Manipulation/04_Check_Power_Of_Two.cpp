#include <iostream>
using namespace std;

// Function to check if the number n is a power of 2
bool isPowerOfTwo(int n) {
    // A number is a power of 2 if it is greater than 0 and the result of n & (n - 1) is 0
    // Example: for n = 8 (binary 1000), n - 1 = 7 (binary 0111), so n & (n - 1) = 1000 & 0111 = 0000
    // This works because a power of 2 has exactly one bit set to 1, so subtracting 1 flips all the bits to the right of that bit.
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n; // Take input from user
    // Check if the number is a power of 2 and print the result
    if (isPowerOfTwo(n))
        cout << n << " is a power of 2." << endl;
    else
        cout << n << " is NOT a power of 2." << endl;
    return 0; // End of program
}
