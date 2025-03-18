// function overloading is a compile time polymorphism which allows us to define multiple functions with the same name but different parameters.

#include <iostream>
using namespace std;

class MathOperations {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function to add two floating-point numbers
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    MathOperations math;

    cout << "Sum of 5 and 10: " << math.add(5, 10) << endl;
    cout << "Sum of 3, 7, and 2: " << math.add(3, 7, 2) << endl;
    cout << "Sum of 4.5 and 2.3: " << math.add(4.5, 2.3) << endl;

    return 0;
}
