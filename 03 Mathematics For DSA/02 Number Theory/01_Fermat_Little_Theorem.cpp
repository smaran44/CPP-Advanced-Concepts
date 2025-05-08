#include <iostream>
using namespace std;

// Recursive binary exponentiation to compute (a^b) % mod
// Uses: (a^b) % mod = ((a^(b/2) % mod)^2) % mod  if b even
//       (a^b) % mod = (a * a^(b-1)) % mod        if b odd
long long binExpo(long long a, long long b, long long mod) {
    if (b == 0)
        return 1; // Base case: anything to the power 0 is 1

    long long half = binExpo(a, b / 2, mod);
    long long result = (half * half) % mod;

    if (b % 2 == 1) // If exponent is odd, multiply one more 'a'
        result = (result * a) % mod;

    return result;
}

// Modular inverse using Fermat’s Little Theorem
// Only valid when 'mod' is prime
// a^(-1) ≡ a^(mod-2) % mod
long long modInverse(long long a, long long mod) {
    return binExpo(a, mod - 2, mod); // Use recursive binary exponentiation
}

int main() {
    long long a, mod;
    cout << "Enter number and prime modulus: ";
    cin >> a >> mod;

    // Output modular inverse
    cout << "Modular inverse of " << a << " under mod " << mod << " is: "
         << modInverse(a, mod) << endl;

    return 0;
}

/*
// Example: binExpo(3, 5, 7)

Step 1: binExpo(3, 5, 7)
  - b = 5 is odd
  - Call: half = binExpo(3, 2, 7)

Step 2: binExpo(3, 2, 7)
  - b = 2 is even
  - Call: half = binExpo(3, 1, 7)

Step 3: binExpo(3, 1, 7)
  - b = 1 is odd
  - Call: half = binExpo(3, 0, 7)

Step 4: binExpo(3, 0, 7)
  - b = 0 → return 1 (base case)

Unwinding the recursion:

Back to Step 3: binExpo(3, 1, 7)
  - half = 1
  - result = (1 * 1) % 7 = 1
  - Since b = 1 is odd:
    result = (result * 3) % 7 = (1 * 3) % 7 = 3
  - Return 3

Back to Step 2: binExpo(3, 2, 7)
  - half = 3
  - result = (3 * 3) % 7 = 9 % 7 = 2
  - Even exponent → return 2

Back to Step 1: binExpo(3, 5, 7)
  - half = 2
  - result = (2 * 2) % 7 = 4
  - Since b = 5 is odd:
    result = (4 * 3) % 7 = 12 % 7 = 5
  - Final answer: 5

Final result:
3^5 % 7 = 5

*/