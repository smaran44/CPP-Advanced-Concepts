/*
    weak_ptr in C++
    ----------------
    - weak_ptr is used to prevent circular references that can occur with shared_ptr.
    - It does NOT increase the reference count of an object.
    - It can check if the shared object is still available before accessing it.
*/

#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;

int main() {
    shared_ptr<int> sharedPtr = make_shared<int>(30);
    weak_ptr<int> weakPtr = sharedPtr; // weak_ptr does not increase reference count
    
    cout << "Shared Pointer Reference Count: " << sharedPtr.use_count() << endl; // 1
    
    // Checking if weak_ptr is still valid before accessing it
    if (auto lockedPtr = weakPtr.lock()) { // Converts weak_ptr to shared_ptr safely
        cout << "Value inside weak_ptr (locked): " << *lockedPtr << endl;
    } else {
        cout << "The object has been deleted." << endl;
    }
    
    sharedPtr.reset(); // Manually deleting shared_ptr
    
    // Now weak_ptr is expired (dangling reference)
    if (weakPtr.expired()) {
        cout << "weak_ptr is expired." << endl;
    }
    
    return 0;
}
