/*
    weak_ptr in C++
    ----------------
    - weak_ptr is used to prevent circular references that can occur with shared_ptr.
    - It does NOT increase the reference count of an object.
    - It can check if the shared object is still available before accessing it.
*/

#include <iostream>   // For input and output operations
#include <memory>     // Required for smart pointers

using namespace std;

int main() {
    // Creating a shared_ptr that manages an integer with value 30
    shared_ptr<int> sharedPtr = make_shared<int>(30);

    // Creating a weak_ptr that observes the same resource as sharedPtr
    weak_ptr<int> weakPtr = sharedPtr; // weak_ptr does not increase the reference count

    // Displaying the current reference count of the shared pointer
    cout << "Shared Pointer Reference Count: " << sharedPtr.use_count() << endl; // Output: 1

    // Checking if weak_ptr is still valid before accessing the resource
    if (auto lockedPtr = weakPtr.lock()) { // Converts weak_ptr to shared_ptr safely
        cout << "Value inside weak_ptr (locked): " << *lockedPtr << endl; // Output: 30
    } else {
        cout << "The object has been deleted." << endl;
    }

    // Resetting sharedPtr, which deletes the managed object if no other shared_ptr exists
    sharedPtr.reset(); // Now, the object is deleted as there are no more shared_ptr references

    // Now weak_ptr is expired (it points to an object that no longer exists)
    if (weakPtr.expired()) {
        cout << "weak_ptr is expired." << endl;
    }

    return 0;
}

