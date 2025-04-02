/*
    RAII (Resource Acquisition Is Initialization) in C++
    ---------------------------------------------------
    - RAII is a technique where resources (memory, file handles, sockets) are tied to object lifetime.
    - When an RAII object goes out of scope, its destructor releases the acquired resource automatically.
    - This ensures exception safety and prevents resource leaks.
*/

#include <iostream>
#include <memory> // For smart pointers

using namespace std;

// Class implementing RAII (Resource Acquisition Is Initialization)
class RAII_Resource {
public:
    // Constructor: Acquires the resource
    RAII_Resource() {
        resource = new int(500); // Dynamically allocating memory (heap)
        cout << "Resource acquired: " << *resource << endl;
    }
    
    // Destructor: Releases the resource automatically
    ~RAII_Resource() {
        delete resource; // Freeing allocated memory
        cout << "Resource released." << endl;
    }
    
    // Method to display the resource value
    void showValue() {
        cout << "Resource value: " << *resource << endl;
    }

private:
    int* resource; // Raw pointer to dynamically allocated resource
};

int main() {
    cout << "Using RAII for resource management:" << endl;
    
    { // Creating a scope to demonstrate RAII
        RAII_Resource obj; // ✅ Resource is acquired in constructor
        obj.showValue();
    } // ✅ Resource is automatically released when obj goes out of scope
    
    return 0;
}
