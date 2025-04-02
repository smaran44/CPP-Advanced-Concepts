/*
=========================================================
   Using Lambda Functions with std::thread in C++
=========================================================

Why Use Lambda Functions with Threads?
--------------------------------------
- Avoids the need for separate function definitions.
- Useful for short, inline thread functions.
- Improves code readability and maintainability.

Key Concepts:
-------------
- A lambda function is an anonymous function defined using `[]`.
- Lambda functions can capture variables by value `[=]` or by reference `[&]`.
- They can be passed directly to `std::thread` without needing a separate function.
*/

#include <iostream>
#include <thread>

int main() {
    std::cout << "Main thread started.\n";
    
    // Creating a thread using a lambda function
    std::thread t1([]() {
        std::cout << "Hello from Lambda Thread!\n";
    });
    
    // Joining the thread
    t1.join();
    
    std::cout << "Main thread finished.\n";
    return 0;
}
