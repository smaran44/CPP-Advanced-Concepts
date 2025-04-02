/*
    Memory Leaks & Prevention in C++
    --------------------------------
    - A memory leak occurs when dynamically allocated memory is not properly deallocated.
    - This leads to increased memory usage and potential crashes in long-running programs.
    - Prevention strategies:
        1. Always deallocate memory using 'delete' or smart pointers.
        2. Avoid dangling pointers (accessing freed memory).
        3. Use tools like Valgrind to detect memory leaks.
        4. Prefer RAII (Resource Acquisition Is Initialization) for automatic resource management.
*/

#include <iostream>
#include <memory> // For smart pointers

using namespace std;

void memoryLeakExample() {
    int* ptr = new int(50); // Dynamically allocated memory
    cout << "Value: " << *ptr << endl;
    // OOPS! Memory leak because 'delete' is missing!
}

void fixedMemoryLeakExample() {
    int* ptr = new int(100); 
    cout << "Value: " << *ptr << endl;
    delete ptr; // ✅ Properly deallocating memory
    ptr = nullptr; // ✅ Avoiding dangling pointer
}

void smartPointerExample() {
    unique_ptr<int> ptr = make_unique<int>(200); // ✅ RAII ensures automatic cleanup
    cout << "Value using smart pointer: " << *ptr << endl;
}

int main() {
    cout << "Demonstrating memory leak (avoid this in real code):" << endl;
    memoryLeakExample();
    
    cout << "\nFixing memory leak properly:" << endl;
    fixedMemoryLeakExample();
    
    cout << "\nUsing smart pointer (best practice):" << endl;
    smartPointerExample();
    
    return 0;
}
// Note: In real-world applications, always prefer smart pointers over raw pointers to manage memory automatically and avoid leaks.
// This code demonstrates memory leak prevention techniques in C++ using both raw pointers and smart pointers.
