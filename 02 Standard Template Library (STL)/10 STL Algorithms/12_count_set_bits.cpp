#include <iostream>
#include <bitset>   // For binary representation (optional)
#include <limits.h> // For __builtin_popcount functions

using namespace std;

/*
 * Count Set Bits in an Integer using Built-in Functions
 * ------------------------------------------------------
 * - Uses three built-in GCC functions:
 *   1. __builtin_popcount()   → Works for 32-bit integers
 *   2. __builtin_popcountl()  → Works for long integers
 *   3. __builtin_popcountll() → Works for long long integers
 * - Efficient and works in O(1) time complexity.
 */

// Function to count set bits using built-in functions
void countSetBits(unsigned int num) {
    cout << "Number: " << num << " (" << bitset<32>(num) << " in binary)" << endl;
    
    // Count set bits using built-in functions
    cout << "Set bits (32-bit int)  : " << __builtin_popcount(num) << endl;
    cout << "Set bits (long int)    : " << __builtin_popcountl(num) << endl;
    cout << "Set bits (long long int): " << __builtin_popcountll(num) << endl;

    cout << "---------------------------------\n";
}

int main() {
    unsigned int num1 = 29;  // Binary: 11101 → 4 set bits
    unsigned int num2 = 255; // Binary: 11111111 → 8 set bits
    unsigned int num3 = 1023; // Binary: 1111111111 → 10 set bits

    countSetBits(num1);
    countSetBits(num2);
    countSetBits(num3);

    return 0;
}
