/*
    shared_ptr in C++
    -----------------
    - shared_ptr allows multiple pointers to share ownership of the same object.
    - It keeps a reference count of how many shared_ptr instances are pointing to the same object.
    - When the last shared_ptr goes out of scope, the object is automatically deleted.
*/

#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;

int main() {
    // Creating a shared_ptr
    shared_ptr<int> ptr1 = make_shared<int>(20);
    cout << "Value inside shared_ptr: " << *ptr1 << endl;
    cout << "Reference count: " << ptr1.use_count() << endl;
    
    {
        // Creating another shared_ptr that shares ownership
        shared_ptr<int> ptr2 = ptr1;
        cout << "Inside inner block:" << endl;
        cout << "Value inside shared_ptr (ptr2): " << *ptr2 << endl;
        cout << "Reference count: " << ptr1.use_count() << endl; // Should be 2
    }
    
    // After ptr2 goes out of scope, reference count decreases
    cout << "Outside inner block:" << endl;
    cout << "Reference count: " << ptr1.use_count() << endl; // Should be 1
    
    //cout << "Value inside shared_ptr (ptr2): " << *ptr2 << endl; // ❌ ERROR: ptr2 is out of scope
    
    // ptr1 will automatically delete the allocated memory when it goes out of scope
    return 0;
}
