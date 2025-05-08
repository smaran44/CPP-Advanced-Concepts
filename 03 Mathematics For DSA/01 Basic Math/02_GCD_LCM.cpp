#include <iostream>
using namespace std;

// Function to compute the GCD using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute the LCM
int lcm(int a, int b) {
    int maxVal = (a > b) ? a : b;

    // Start from the maximum and go upwards until a common multiple is found
    while (true) {
        if (maxVal % a == 0 && maxVal % b == 0) {
            return maxVal; // Found the LCM
        }
        maxVal++;
    }
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int resultGCD = gcd(a, b);
    int resultLCM = lcm(a, b);

    cout << "GCD of " << a << " and " << b << " is: " << resultGCD << endl;
    cout << "LCM of " << a << " and " << b << " is: " << resultLCM << endl;

    return 0;
}
