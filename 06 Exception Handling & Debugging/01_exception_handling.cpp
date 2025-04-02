/*
    Exception Handling in C++ (try-catch-throw)
    -----------------------------------------
    - Exception handling ensures programs can handle runtime errors gracefully.
    - Uses try-catch blocks to catch and handle errors without crashing.
    - The throw keyword is used to signal an error.
*/

#include <iostream>

using namespace std;

// Function that performs division and throws an exception if b is zero
void divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero error"); // Throw an exception if divisor is zero
    }
    cout << "Result: " << (a / b) << endl; // Perform division and print result
}

int main() {
    try {
        divide(10, 2); // Valid division: 10 / 2 = 5
        divide(5, 0);  // Invalid division: division by zero (exception will be thrown)
    } 
    catch (const exception &e) { 
        // Catch block to handle exceptions
        cout << "Exception caught: " << e.what() << endl;
    }
    
    return 0;
}
