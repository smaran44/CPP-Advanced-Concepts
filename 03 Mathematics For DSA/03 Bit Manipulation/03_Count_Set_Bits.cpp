#include <iostream>
using namespace std;

// Counts the number of 1's in binary representation of the given number n
int countSetBits(int n) {
    int count = 0;
    // Loop until n becomes 0
    while (n) {
        // n & (n - 1) clears the lowest set bit of n
        // Example: if n is 12 (1100 in binary), n - 1 becomes 11 (1011), and n & (n - 1) results in 8 (1000), clearing the lowest bit
        // it removes the least significant set bit from n
        //The least significant set bit (LSSB) refers to the rightmost 1 bit in the binary representation of a number
        n = n & (n - 1);
        count++; // Increment count for each set bit cleared
    }
    return count; // Return the total count of set bits
}

int main() {
    int n;
    cout << "Enter number to count set bits: ";
    cin >> n; // Take input from user
    // Display the number of set bits in the binary representation of n
    cout << "Number of set bits in " << n << " = " << countSetBits(n) << endl;
    return 0; // End of program
}
