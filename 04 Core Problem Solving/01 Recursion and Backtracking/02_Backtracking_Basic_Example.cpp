#include <iostream>
using namespace std;

/*
    Program: Generate Binary Strings with No Two Consecutive 1s
    -----------------------------------------------------------
    What we are doing:
    - We generate all binary strings of length 'n' such that no two 1s are adjacent.
    - We use recursion to build the string step by step.
    - At each step, we can always place a '0'.
    - We can place a '1' **only if** the last digit was '0'.

    Concept used: Recursion with backtracking – building possible strings by making choices at each position.
*/

// Recursive function to generate binary strings
// n = number of positions left
// str = current string being built
// lastDigit = last digit placed (0 or 1)
void generateBinaryStrings(int n, string str, int lastDigit) {
    // Base case: if no positions left, print the string
    if (n == 0) {
        cout << str << endl;
        return;
    }

    // Choice 1: Always allowed to place '0'
    generateBinaryStrings(n - 1, str + "0", 0);

    // Choice 2: Place '1' only if previous digit is not '1'
    if (lastDigit == 0) {
        generateBinaryStrings(n - 1, str + "1", 1);
    }
}

int main() {
    int n;
    cout << "Enter length of binary string: ";
    cin >> n;

    // Start generating binary strings from empty string with lastDigit = 0
    generateBinaryStrings(n, "", 0);

    return 0;
}
/* example
generateBinaryStrings(3, "", 0)
├── generateBinaryStrings(2, "0", 0)
│   ├── generateBinaryStrings(1, "00", 0)
│   │   ├── generateBinaryStrings(0, "000", 0) → prints "000"
│   │   └── generateBinaryStrings(0, "001", 1) → prints "001"
│   └── generateBinaryStrings(1, "01", 1)
│       ├── generateBinaryStrings(0, "010", 0) → prints "010"
│       (no call with "011" because lastDigit is 1)
├── generateBinaryStrings(2, "1", 1)
│   ├── generateBinaryStrings(1, "10", 0)
│   │   ├── generateBinaryStrings(0, "100", 0) → prints "100"
│   │   └── generateBinaryStrings(0, "101", 1) → prints "101"
│   (no call with "11" because lastDigit is 1)
*/