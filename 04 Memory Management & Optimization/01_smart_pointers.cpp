/*
    Smart Pointers in C++
    ----------------------
    - Smart pointers help manage dynamic memory automatically.
    - They avoid memory leaks by deallocating memory when no longer needed.
    - Types of smart pointers in C++:
        1. unique_ptr - Sole ownership of an object (non-copyable)
        2. shared_ptr - Shared ownership (reference counting)
        3. weak_ptr - Avoids circular references with shared_ptr

    unique pointer:
    - A unique pointer is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique pointer goes out of scope.
    - It cannot be copied, only moved. This ensures that there is only one unique pointer to a given resource at any time.
*/

#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;

int main() {
    // 1. unique_ptr - Owns the object exclusively
    unique_ptr<int> ptr1 = make_unique<int>(10); // Allocating integer dynamically
    cout << "Value inside unique_ptr: " << *ptr1 << endl;
    
    // unique_ptr does NOT allow copying
    // unique_ptr<int> ptr2 = ptr1; // ❌ ERROR: Copy not allowed
    
    // But we can transfer ownership using std::move()
    unique_ptr<int> ptr2 = move(ptr1);
    if (!ptr1) {
        cout << "ptr1 is now nullptr after move." << endl;
    }
    cout << "Value inside moved unique_ptr (ptr2): " << *ptr2 << endl;
    
    // ptr2 will automatically delete the allocated memory when it goes out of scope
    return 0;
}
