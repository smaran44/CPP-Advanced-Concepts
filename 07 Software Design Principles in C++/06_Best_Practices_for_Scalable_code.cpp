/*
    Best Practices for Scalable Code in C++
    --------------------------------------
    - Scalable code can handle increasing complexity without major rewrites.
    - These best practices improve maintainability, performance, and efficiency.
*/

#include <iostream>   // For standard input-output operations
#include <vector>     // For using the vector container
#include <memory>     // For smart pointers
#include <thread>     // For multithreading
using namespace std;

// 1️⃣ Modular Code (Separation of Concerns)
//    - Breaking code into small, reusable, independent functions.
//    - Each function has a **single responsibility** for maintainability.

void processData() { 
    cout << "Processing data..." << endl; 
}

void saveData() { 
    cout << "Saving data..." << endl; 
}

// 2️⃣ Avoid Hardcoded Values (Use Constants & Configurations)
//    - Hardcoded values reduce flexibility and make future modifications difficult.
//    - Use `#define` or `const` for easy configuration and scalability.

#define MAX_USERS 1000  // Defining a constant for scalability

void createUsers() {
    cout << "Creating up to " << MAX_USERS << " users..." << endl;
}

// 3️⃣ Use Smart Pointers for Memory Management
//    - Avoid raw pointers to prevent memory leaks.
//    - Use `unique_ptr`, `shared_ptr`, and `weak_ptr` to handle memory automatically.

class Data {
public:
    void show() { cout << "Data Loaded\n"; }
};

void useSmartPointer() {
    // Using unique_ptr for automatic memory management
    unique_ptr<Data> ptr = make_unique<Data>();  
    ptr->show();
} // `ptr` is automatically destroyed when function exits (RAII - Resource Acquisition Is Initialization)

// 4️⃣ Optimize Performance with Efficient Data Structures
//    - Choosing the right STL container for better performance.
//    - `vector` is dynamic and more efficient than an array in most cases.

void useEfficientDataStructures() {
    vector<int> numbers = {1, 2, 3, 4, 5}; // Dynamic array (vector)
    cout << "Stored numbers: ";
    for (int num : numbers)  // Range-based loop for simplicity
        cout << num << " ";
    cout << endl;
}

// 5️⃣ Use Multithreading for High Performance
//    - Multithreading enables parallel execution, boosting performance for CPU-bound tasks.

void task() { 
    cout << "Running in a separate thread\n"; 
}

void runMultithreading() {
    thread t(task);  // Launch a separate thread
    t.join();        // Wait for the thread to complete execution
}

// 6️⃣ Follow SOLID Principles
//    - Ensuring **good design** for scalable and maintainable code.
//    - Applying **SOLID**: Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, Dependency Inversion.

// 7️⃣ Use Logging & Debugging Tools
//    - Logging helps track program execution and errors in real-time.
//    - Instead of `cout`, real-world applications use logging libraries like `spdlog`, `log4cpp`, etc.

void logMessage(const string& msg) {
    cout << "[LOG]: " << msg << endl;  // Simulated logging system
}

// 8️⃣ Write Unit Tests
//    - Using testing frameworks like Google Test (`gtest`) or Catch2 for automated testing.
//    - Helps ensure reliability and prevents regressions in large codebases.

int main() {
    // Logging application start
    logMessage("Application started");

    // Demonstrating modular functions
    processData();
    saveData();
    
    // Demonstrating scalable constants
    createUsers();

    // Using smart pointers for memory management
    useSmartPointer();

    // Using efficient data structures (vector)
    useEfficientDataStructures();

    // Demonstrating multithreading
    runMultithreading();
    
    // Logging application end
    logMessage("Application finished successfully");

    return 0;
}
