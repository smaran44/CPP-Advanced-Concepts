#include <iostream>
using namespace std;

// Function to compute GCD using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case: GCD is 'a' if 'b' is 0
    }
    return gcd(b, a % b);  // Recursive call
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}
