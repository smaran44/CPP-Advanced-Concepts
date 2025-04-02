/*
    Custom Exceptions in C++
    -----------------------
    - Custom exceptions allow defining specific error types for better debugging.
    - Inherit from std::exception and override the what() function.
    - Helps in handling specific errors more efficiently.
*/

#include <iostream>
#include <exception> // Required for exception handling

using namespace std;

// Custom exception class for division by zero
class DivisionByZeroException : public exception {
public:
    // Overriding the what() method to provide a custom error message
    const char* what() const noexcept override {
        return "Error: Attempted division by zero";
    }
};

// Function that performs division and throws a custom exception if denominator is zero
void divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException(); // Throw custom exception
    }
    cout << "Result: " << (a / b) << endl; // Print the division result
}

int main() {
    try {
        divide(10, 2); // ✅ Valid case: 10 / 2 = 5
        divide(5, 0);  // ❌ Invalid case: division by zero (exception thrown)
    } 
    catch (const exception &e) { 
        // Catch block to handle exceptions
        cout << "Exception caught: " << e.what() << endl;
    }
    
    return 0;
}
