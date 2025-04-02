/*
    Debugging Techniques & Tools in C++
    -----------------------------------
    - Debugging helps identify and fix runtime errors efficiently.
    - Common techniques:
        1. Print Debugging (cout statements for variable tracking)
        2. Assertions (assert() to verify conditions)
        3. Debugging Tools (GDB, Visual Studio Debugger)
    - Using breakpoints and step-by-step execution is crucial for complex programs.
*/

#include <iostream>
#include <cassert> // Required for assertion debugging

using namespace std;

// Function to demonstrate debugging techniques
void debugExample(int x) {
    // Print Debugging: Prints the value of x to help track execution
    cout << "Debug: x = " << x << endl; 

    // Assertion Debugging: Ensures x is not zero
    // If x is zero, the program will terminate with an assertion failure
    assert(x != 0 && "Assertion Failed: x should not be zero"); 

    // If assertion passes, this line executes
    cout << "Square of x: " << (x * x) << endl;
}

int main() {
    debugExample(5);  // Valid case, prints square of 5

    debugExample(0);  // This will trigger an assertion failure and terminate the program

    return 0;
}
