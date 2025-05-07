#include <iostream>
using namespace std;

// Function to calculate nCr (combinations) using Pascal's identity
long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    r = min(r, n - r); // Since nCr == nC(n-r), we reduce r to the smaller one

    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);      // Multiply by (n-i)
        result /= (i + 1);      // Divide by (i+1)
    }
    return result;
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    cout << "nCr = " << nCr(n, r) << endl;
    return 0;
}
