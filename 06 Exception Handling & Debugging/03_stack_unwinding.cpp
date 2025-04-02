/*
    Stack Unwinding & Best Practices in Exception Handling
    ------------------------------------------------------
    - Stack unwinding ensures proper cleanup when exceptions occur.
    - When an exception is thrown, local objects are destroyed in reverse order of creation.
    - Best practices include using RAII (Resource Acquisition Is Initialization) to manage resources.
*/

#include <iostream>
#include <exception> // Required for exception handling

using namespace std;

// Class with constructor and destructor to observe stack unwinding
class Test {
public:
    // Constructor: Initializes object and prints a message
    Test(int id) : id(id) { 
        cout << "Constructing object " << id << endl; 
    }
    
    // Destructor: Cleans up when the object goes out of scope
    ~Test() { 
        cout << "Destroying object " << id << endl; 
    }

private:
    int id; // Unique identifier for each object
};

// Function that demonstrates stack unwinding
void func() {
    Test t1(1);  // Object t1 is created
    Test t2(2);  // Object t2 is created
    
    throw runtime_error("Exception occurred!"); // Exception is thrown here
    
    Test t3(3);  // This line will never execute because of the exception
}

int main() {
    try {
        func(); // Call function that throws an exception
    } 
    catch (const exception &e) { // Catch any exception derived from std::exception
        cout << "Caught exception: " << e.what() << endl;
    }
    
    return 0; // Program exits normally after handling exception
}
