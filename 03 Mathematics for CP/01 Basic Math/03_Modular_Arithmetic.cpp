#include <iostream>
using namespace std;

// Function to perform modular exponentiation
long long modExp(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod; // In case base is greater than mod

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod; // If exponent is odd, multiply the base with result
        }
        base = (base * base) % mod;  // Square the base
        exponent /= 2;  // Halve the exponent
    }
    return result;
}

int main() {
    long long base, exponent, mod;
    cout << "Enter base, exponent and mod: ";
    cin >> base >> exponent >> mod;
    cout << base << "^" << exponent << " % " << mod << " = " << modExp(base, exponent, mod) << endl;
    return 0;
}
