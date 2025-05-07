#include <iostream>
using namespace std;

// Function to perform binary exponentiation
long long binaryExp(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;  // If exponent is odd, multiply with result
        }
        base *= base;  // Square the base
        exponent /= 2;  // Halve the exponent
    }
    return result;
}

int main() {
    long long base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << base << "^" << exponent << " = " << binaryExp(base, exponent) << endl;
    return 0;
}
