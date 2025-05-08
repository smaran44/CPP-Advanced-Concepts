#include <iostream>
using namespace std;

// Extended Euclidean Algorithm
// Modular inverse means finding x such that: (a*x)%m ≡ 1
// It finds integers x and y such that: a*x + b*y = gcd(a, b)
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        // Base case: gcd(a, 0) = a
        x = 1;  // x = 1, because a*1 + 0*0 = a
        y = 0;
        return a;
    }

    int x1, y1;  // To store results of recursive call
    // Recursive call: gcd(b, a % b)
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results from recursion
    x = y1;
    y = x1 - y1 * (a / b);  // Based on back-substitution

    return gcd;  // Return gcd of a and b
}

// Modular Inverse using Extended Euclidean Algorithm
// Works even when modulus 'm' is not prime
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);  // Find x such that a*x + m*y = gcd(a, m)

    if (g != 1)
        return -1;  // Modular inverse doesn't exist if gcd ≠ 1
    else
        return (x % m + m) % m;  // Ensure result is positive
}

int main() {
    int a, m;
    cout << "Enter a and mod (not necessarily prime): ";
    cin >> a >> m;  // Input integers a and m

    int inv = modInverse(a, m);  // Compute modular inverse

    if (inv == -1)
        cout << "Inverse doesn't exist!" << endl;
    else
        cout << "Modular inverse is: " << inv << endl;

    return 0;  // End of program
}
