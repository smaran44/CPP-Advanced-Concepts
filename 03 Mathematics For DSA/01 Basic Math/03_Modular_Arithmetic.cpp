#include <iostream> // For input and output operations
using namespace std;

// Recursive function to perform modular exponentiation
// Computes (base^exponent) % mod efficiently using:
// If exponent is even: (base^exp) % mod = [(base^(exp/2) % mod)^2] % mod
// If exponent is odd:  (base^exp) % mod = [base % mod * (base^(exp-1) % mod)] % mod

long long modExp(long long base, long long exponent, long long mod) {
    if (exponent == 0)
        return 1; // Base case: anything to the power 0 is 1

    // Reduce base to stay within mod range
    base = base % mod;

    // Recursive call
    long long half = modExp(base, exponent / 2, mod);

    // (a × b) % m = [(a % m) × (b % m)] % m — property used to prevent overflow
    long long result = (half * half) % mod;

    // If exponent is odd, multiply one more base
    if (exponent % 2 == 1)
        result = (result * base) % mod;

    return result;
}

int main() {
    long long base, exponent, mod;
    cout << "Enter base, exponent and mod: ";
    cin >> base >> exponent >> mod;  // Input values

    // Output the result of modular exponentiation
    cout << base << "^" << exponent << " % " << mod << " = " << modExp(base, exponent, mod) << endl;

    return 0;  // End of program
}


/*
// Example: modExp(3, 5, 7)

Step 1: modExp(3, 5, 7)
  - b = 5 is odd
  - Call: half = modExp(3, 2, 7)

Step 2: modExp(3, 2, 7)
  - b = 2 is even
  - Call: half = modExp(3, 1, 7)

Step 3: modExp(3, 1, 7)
  - b = 1 is odd
  - Call: half = modExp(3, 0, 7)

Step 4: modExp(3, 0, 7)
  - b == 0 → return 1 (base case)

Unwinding the recursion:

Back to Step 3: modExp(3, 1, 7)
  - half = 1
  - result = (1 * 1) % 7 = 1
  - Since b = 1 is odd:
    result = (result * 3) % 7 = (1 * 3) % 7 = 3
  - Return 3

Back to Step 2: modExp(3, 2, 7)
  - half = 3
  - result = (3 * 3) % 7 = 9 % 7 = 2
  - Even exponent → return 2

Back to Step 1: modExp(3, 5, 7)
  - half = 2
  - result = (2 * 2) % 7 = 4
  - Since b = 5 is odd:
    result = (4 * 3) % 7 = 12 % 7 = 5
  - Final answer: 5

Final result:
3^5 % 7 = 5

*/
