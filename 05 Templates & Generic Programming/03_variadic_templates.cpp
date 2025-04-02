/*
    Variadic Templates in C++ (Handling Multiple Arguments)
    ------------------------------------------------------
    - Variadic templates allow functions and classes to accept multiple arguments of different types.
    - They enable writing generic code that can handle any number of parameters.
    - Used in logging, serialization, and flexible utility functions.
*/

#include <iostream>

using namespace std;

// **Base case**: Function with a single argument (stopping condition for recursion)
template <typename T>
void printArgs(T arg) {
    cout << arg << endl; // Print the last argument and end recursion
}

// **Recursive variadic template function**: Handles multiple arguments
template <typename T, typename... Args>
void printArgs(T first, Args... rest) {
    cout << first << " "; // Print the first argument
    printArgs(rest...);   // Recursive call with the remaining arguments
}

int main() {
    cout << "Printing multiple arguments using variadic templates:" << endl;
    
    // Calling the variadic function with different types of arguments
    printArgs(10, 3.14, "Hello", 'A'); // Prints each argument in sequence
    
    return 0;
}
