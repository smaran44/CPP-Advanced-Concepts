/*
    Move Semantics & Rvalue References in C++
    ------------------------------------------
    - Move semantics optimize performance by avoiding unnecessary copies.
    - Rvalue references allow transferring ownership of resources instead of copying them.
    - Helps improve efficiency in scenarios involving dynamic memory allocation.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
 * Copy vs Move Semantics in C++
 * - Copy Constructor: Creates a deep copy, allocating new memory.
 * - Move Constructor: Transfers ownership, preventing unnecessary deep copies.
 * - Prevents unnecessary allocations & deallocations, improving performance.
 */

class Data {
private:
    int* value; // Dynamically allocated integer
public:
    // Constructor: Allocates memory and initializes value
    Data(int v) {
        value = new int(v);
        cout << "Resource allocated for " << *value << endl;
    }
    
    // Copy Constructor (Deep Copy)
    // - Creates a new memory allocation with the same value.
    Data(const Data& other) {
        value = new int(*other.value); // Allocate new memory and copy value
        cout << "Copy Constructor: Resource copied for " << *value << endl;
    }
    
    // Move Constructor (Move Semantics)
    // - Transfers ownership instead of copying.
    // - Avoids expensive memory allocation & copy operations.
    Data(Data&& other) noexcept {
        value = other.value;  // Steal the pointer
        other.value = nullptr; // Nullify the source pointer to prevent double deletion
        cout << "Move Constructor: Resource moved" << endl;
    }
    
    // Destructor: Releases allocated memory
    ~Data() {
        if (value) { // Check if resource exists before deleting
            cout << "Resource deallocated for " << *value << endl;
            delete value;
        }
    }
};

// Function that returns an rvalue (temporary object)
// - Since it's a temporary object, Move Constructor is preferred.
Data createData(int v) {
    return Data(v); // Temporary object (rvalue)
}

int main() {
    cout << "\n--- Copy vs Move Semantics ---\n";
    Data d1(10); // Normal object creation
    Data d2 = d1; // Calls Copy Constructor (Deep Copy)
    
    cout << "\n--- Move Semantics in Action ---\n";
    Data d3 = createData(20); // Calls Move Constructor instead of Copy Constructor
    
    return 0;
}
