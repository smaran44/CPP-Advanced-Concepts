#include <iostream>
using namespace std;

// Recursive function to perform binary exponentiation
// Computes base^exponent using:
// If exponent is even: base^exponent = (base^(exponent/2))^2
// If exponent is odd:  base^exponent = base * base^(exponent - 1)
long long binaryExp(long long base, long long exponent) {
    // Base case: any number to the power 0 is 1
    if (exponent == 0)
        return 1;

    // Recursive step: divide exponent by 2
    long long half = binaryExp(base, exponent / 2);

    // If exponent is even: result = half * half
    if (exponent % 2 == 0)
        return half * half;
    else
        // If exponent is odd: result = base * half * half
        return base * half * half;
}

int main() {
    long long base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;  // Input values

    // Output the result of exponentiation
    cout << base << "^" << exponent << " = " << binaryExp(base, exponent) << endl;

    return 0;  // End of program
}

/*for example 
binaryExp(2, 5)
= 2 * binaryExp(2, 2)^2    // because 5 is odd
= 2 * (binaryExp(2, 1)^2)^2
= 2 * ((2)^2)^2
= 2 * (4)^2
= 2 * 16
= 32
*/
