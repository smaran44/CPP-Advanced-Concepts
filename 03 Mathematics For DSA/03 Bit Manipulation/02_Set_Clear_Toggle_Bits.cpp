#include <iostream>
using namespace std;

// Function to check if the ith bit is set
bool isBitSet(int n, int i) {
    // Shift 1 left by i bits to create a mask, then AND with n
    // If result is not zero, the ith bit is set
    return (n & (1 << i)) != 0;
}

// Function to set the ith bit
int setBit(int n, int i) {
    // OR n with mask having 1 at ith position sets that bit to 1
    return n | (1 << i);
}

// Function to clear the ith bit
int clearBit(int n, int i) {
    // Invert the mask with 1 at ith position and AND with n to clear that bit
    return n & (~(1 << i));// Clears the specific bit at position i
}

// Function to toggle the ith bit
int toggleBit(int n, int i) {
    // XOR n with mask flips the ith bit (0 becomes 1, 1 becomes 0)
    return n ^ (1 << i);
}

int main() {
    int n = 10; // Binary: 1010
    int i = 1;  // We are targeting the 1st bit (counting from 0 at the right)

    cout << "Original number: " << n << " (binary: 1010)" << endl;

    // Check if the ith bit is set
    cout << "Is bit " << i << " set? " << (isBitSet(n, i) ? "Yes" : "No") << endl;

    // Set the ith bit
    cout << "After setting bit " << i << ": " << setBit(n, i) << endl;

    // Clear the ith bit
    cout << "After clearing bit " << i << ": " << clearBit(n, i) << endl;

    // Toggle the ith bit
    cout << "After toggling bit " << i << ": " << toggleBit(n, i) << endl;

    return 0;
}
