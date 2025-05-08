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


/*for example 
modExp(2, 5, 13)
= (modExp(2, 2, 13)^2 * 2) % 13     // because 5 is odd
= ((modExp(2, 1, 13)^2)^2 * 2) % 13
= (((2)^2)^2 * 2) % 13
= (4^2 * 2) % 13
= (16 * 2) % 13
= 32 % 13
= 6
*/
