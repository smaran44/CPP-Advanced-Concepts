/*
    constexpr, auto, decltype in C++
    --------------------------------
    - constexpr: Evaluates expressions at compile time, optimizing performance.
    - auto: Automatically deduces variable types, making code concise.
    - decltype: Extracts the exact type of an expression without evaluating it.
*/

#include <iostream>
using namespace std;

/*
 * Modern C++ Features: constexpr, auto, and decltype
 * - constexpr: Forces compile-time evaluation of expressions.
 * - auto: Allows automatic type deduction.
 * - decltype: Extracts the type of an expression without evaluating it.
 */

// 1. constexpr - Compile-time constant evaluation
constexpr int square(int x) {
    return x * x; // Computed at compile time if argument is a constant
}

// 2. auto - Automatic type deduction
auto add(int a, double b) {
    return a + b; // Compiler deduces return type as double
}

// 3. decltype - Extracts type without evaluation
int someFunction() { return 42; } // Returns an int

decltype(someFunction()) getValue() { // Deduces return type as int
    return 50;
}

int main() {
    // Demonstrate constexpr
    constexpr int result = square(5); // Computed at compile time
    cout << "constexpr square(5): " << result << endl;
    
    // Demonstrate auto
    auto sum = add(10, 5.5); // Compiler infers return type as double
    cout << "auto sum: " << sum << endl;
    
    // Demonstrate decltype
    decltype(sum) anotherSum = 20.5; // Extracts type of sum (double)
    cout << "decltype example: " << anotherSum << endl;
    
    return 0;
}
