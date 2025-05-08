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
// Example: binaryExp(3, 5)

Step 1: binaryExp(3, 5)
  - exponent = 5 is odd
  - Formula: 3^5 = 3 * (3^4)
  - Call: binaryExp(3, 4)

Step 2: binaryExp(3, 4)
  - exponent = 4 is even
  - Formula: 3^4 = (3^2) * (3^2)
  - Call: binaryExp(3, 2)

Step 3: binaryExp(3, 2)
  - exponent = 2 is even
  - Formula: 3^2 = (3^1) * (3^1)
  - Call: binaryExp(3, 1)

Step 4: binaryExp(3, 1)
  - exponent = 1 is odd
  - Formula: 3^1 = 3 * (3^0)
  - Call: binaryExp(3, 0)

Step 5: binaryExp(3, 0)
  - exponent = 0, base case reached → return 1

Unwinding the recursion:

Back to Step 4: binaryExp(3, 1)
  - half = 1
  - Formula: 3^1 = 3 * 1 * 1 = 3
  - Return 3

Back to Step 3: binaryExp(3, 2)
  - half = 3
  - Formula: 3^2 = 3 * 3 = 9
  - Return 9

Back to Step 2: binaryExp(3, 4)
  - half = 9
  - Formula: 3^4 = 9 * 9 = 81
  - Return 81

Back to Step 1: binaryExp(3, 5)
  - half = 81
  - Formula: 3^5 = 3 * 81 = 243
  - Final result: 243

Final result:
3^5 = 243

*/
