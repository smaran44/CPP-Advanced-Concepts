#include <iostream>
#include <bitset> // For using the bitset class

using namespace std;

int main() {
    // Defining a bitset of size 8 (8-bit binary number)
    bitset<8> b1("11001100"); // Binary representation of the number

    // Display the bitset
    cout << "Bitset: " << b1 << endl;

    // Accessing a specific bit at index 2 (counting from right, 0-based index)
    cout << "Bit at position 2: " << b1[2] << endl;

    // Counting the number of '1's in the bitset
    cout << "Count of 1s: " << b1.count() << endl;

    // Counting the number of '0's in the bitset
    cout << "Count of 0s: " << b1.size() - b1.count() << endl;

    // converting binary to decimal
    cout << "Decimal value: " << b1.to_ulong() << endl;

    // Converting decimal to binary
    unsigned long decimalValue = 204; // Decimal number
    bitset<8> b3(decimalValue); // Convert decimal to binary
    cout << "Decimal to Binary: " << b3 << endl;

    // Defining another bitset for bitwise operations
    bitset<8> b2("10101010"); // Another 8-bit binary number

    // Performing bitwise operations
    cout << "AND: " << (b1 & b2) << endl;  // Bitwise AND
    cout << "OR:  " << (b1 | b2) << endl;  // Bitwise OR
    cout << "XOR: " << (b1 ^ b2) << endl;  // Bitwise XOR

    return 0;
}
