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

class RAII_Resource {
public:
    RAII_Resource() {
        resource = new int(500); // Acquiring resource
        cout << "Resource acquired: " << *resource << endl;
    }
    
    ~RAII_Resource() {
        delete resource; // Releasing resource automatically
        cout << "Resource released." << endl;
    }
    
    void showValue() {
        cout << "Resource value: " << *resource << endl;
    }

private:
    int* resource;
};

int main() {
    cout << "Using RAII for resource management:" << endl;
    {
        RAII_Resource obj; // Resource acquired
        obj.showValue();
    } // Resource released automatically when obj goes out of scope
    
    return 0;
}
