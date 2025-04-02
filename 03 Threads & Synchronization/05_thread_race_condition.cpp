/*
==================================================
   Race Condition in Multithreading
==================================================

What is a Race Condition?
-------------------------
- Occurs when multiple threads access and modify shared data simultaneously.
- Leads to unpredictable behavior and incorrect results.
- Common in scenarios where threads perform read-modify-write operations on shared variables.

Example Issue:
--------------
- Suppose multiple threads increment a shared counter without synchronization.
- Due to race conditions, some increments may be lost.

How to Fix?
-----------
- Use Mutex (Mutual Exclusion) to prevent simultaneous access.
- We'll cover mutex in the next section.
*/

#include <iostream>
#include <thread>

int counter = 0; // Shared variable

void incrementCounter() {
    for (int i = 0; i < 10000; i++) {
        counter++; // Race condition: multiple threads modifying the same variable
    }
}

int main() {
    std::cout << "Main thread started.\n";
    
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);
    
    t1.join();
    t2.join();
    
    // Expected result: 20000, but actual result may be inconsistent
    std::cout << "Final Counter Value: " << counter << "\n";
    
    std::cout << "Main thread finished.\n";
    return 0;
}
