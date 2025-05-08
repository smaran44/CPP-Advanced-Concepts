#include <iostream>  
using namespace std; 

int main() {
    // Declare two integers a and b with values 5 and 3
    // Binary representation:
    // a = 5  => 0101
    // b = 3  => 0011
    int a = 5, b = 3;

    // Bitwise AND: Each bit is compared; 1 & 1 = 1, else 0
    // 0101 & 0011 = 0001 => 1
    cout << "a & b = " << (a & b) << endl;

    // Bitwise OR: Each bit is compared; if at least one bit is 1, result is 1
    // 0101 | 0011 = 0111 => 7
    cout << "a | b = " << (a | b) << endl;

    // Bitwise XOR: Each bit is compared; if bits are different, result is 1
    // 0101 ^ 0011 = 0110 => 6
    cout << "a ^ b = " << (a ^ b) << endl;

    // Bitwise NOT: All bits are flipped
    // ~0101 = 1010 (in binary for 4-bit), but in actual memory it's stored in 2's complement form
    // So ~5 = -6 (due to how negative numbers are represented in binary)
    cout << "~a = " << (~a) << endl;

    // Left Shift: Shifts bits to the left, inserting 0 at the right
    // 0011 << 1 = 0110 => 6 (same as multiplying by 2)
    cout << "b << 1 = " << (b << 1) << endl;

    // Right Shift: Shifts bits to the right, discarding the rightmost bit
    // 0011 >> 1 = 0001 => 1 (same as integer division by 2)
    cout << "b >> 1 = " << (b >> 1) << endl;

    return 0; // Indicate successful program execution
}
