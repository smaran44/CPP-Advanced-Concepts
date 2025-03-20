#include <iostream>
using namespace std;

// Class definition
class Box {
private:
    int width;

public:
    // Constructor
    Box(int w) { width = w; }

    // Friend function declaration
    friend void printWidth(Box b);
};

// Friend function definition (outside the class)
void printWidth(Box b) {
    // Accessing private member
    cout << "Width of the box: " << b.width << endl;
}

int main() {
    Box b1(10); // Create object
    printWidth(b1); // Call friend function
    return 0;
}
