#include <iostream>
using namespace std;

// Euler's Totient Function φ(n)
// Computes the number of integers from 1 to n that are coprime with n
// Formula: φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk), where p1, p2, ..., pk are the distinct prime factors of n
int phi(int n) {
    int result = n;  // Initialize result to n
    
    // Loop over every integer p from 2 to sqrt(n)
    for (int p = 2; p * p <= n; ++p) {
        // If p is a divisor of n
        if (n % p == 0) {
            // If p is a prime factor, subtract multiples of p from result
            while (n % p == 0){  // Divide out all instances of p from n
                n /= p;}
            result -= result / p;  // Apply Euler's formula: result = result * (1 - 1/p)
        }
    }

    // If n is still greater than 1, it must be a prime factor larger than sqrt(n)
    if (n > 1)
        result -= result / n;  // Apply the formula for the remaining prime factor

    return result;  // Return the final result which is φ(n)
}

int main() {
    int n;
    cout << "Enter a number to compute phi(n): ";
    cin >> n;  // Input number n
    
    // Output the result of Euler's Totient Function
    cout << "Euler's Totient Function φ(" << n << ") = " << phi(n) << endl;

    return 0;  // End of program
}
