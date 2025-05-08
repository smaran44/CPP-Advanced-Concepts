#include <iostream>     
#include <vector>       // To use the vector container
using namespace std;

// Function to perform the Sieve of Eratosthenes algorithm
void sieveOfEratosthenes(int n) {
    // Create a boolean vector "isPrime" of size n+1 and initialize all entries as true
    vector<bool> isPrime(n + 1, true);

    // 0 and 1 are not prime numbers, so set them to false
    isPrime[0] = isPrime[1] = false;

    // Loop from 2 to square root of n
    for (int i = 2; i * i <= n; i++) {
        // If i is still marked as prime
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            //We're marking all multiples of i (i * i, i * (i+1), i * (i+2)...) as not prime.
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all numbers that are still marked as prime
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";  // Output the prime number
        }
    }
}

int main() {
    int n;
    cout << "Enter the number up to which you want to find primes: ";
    cin >> n;                      // Take input from the user
    sieveOfEratosthenes(n);       // Call the function to find all primes up to n
    return 0;                     // Indicate successful program termination
}
