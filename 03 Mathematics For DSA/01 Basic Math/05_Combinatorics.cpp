#include <iostream>
using namespace std;

// Function to calculate nCr (number of combinations)
// Using an efficient iterative approach based on Pascal's identity
long long nCr(int n, int r) {
    // If r > n, combinations are not defined
    if (r > n) return 0;

    // Base cases: nC0 = nCn = 1
    if (r == 0 || r == n) return 1;

    // Use symmetry: nCr == nC(n - r)
    // This minimizes the number of iterations
    r = min(r, n - r);

    long long result = 1;

    // Compute nCr using the formula:
    // nCr = (n * (n - 1) * ... * (n - r + 1)) / (r!)
    // This avoids calculating large factorials
    for (int i = 0; i < r; ++i) {
        result *= (n - i);      // Multiply numerator terms: (n-i)
        result /= (i + 1);      // Divide by denominator terms: (i+1)
    }

    return result;
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;  // Input values

    // Output the value of nCr
    cout << "nCr = " << nCr(n, r) << endl;

    return 0;
}
