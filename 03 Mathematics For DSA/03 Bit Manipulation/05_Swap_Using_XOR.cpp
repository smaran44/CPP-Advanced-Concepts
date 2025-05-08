#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 9;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    // XOR swap algorithm:
    // Step 1: a = a ^ b
    a = a ^ b;  // a now holds the XOR of a and b
    // Step 2: b = a ^ b
    b = a ^ b;  // b is now equal to the original a (since a ^ b ^ b = a)
    // Step 3: a = a ^ b
    a = a ^ b;  // a is now equal to the original b (since a ^ b ^ a = b)

    cout << "After swap: a = " << a << ", b = " << b << endl;
    return 0;
}
