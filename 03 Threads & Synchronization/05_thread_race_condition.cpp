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

#include <iostream>   // For input and output operations
#include <thread>     // For working with multiple threads

int counter = 0;  // Shared variable (global variable)

// Function executed by multiple threads to increment the counter
void incrementCounter() {
    for (int i = 0; i < 10000; i++) {
        counter++;  // Critical section: multiple threads modifying `counter` simultaneously
    }
}

int main() {
    std::cout << "Main thread started.\n";

    // Creating two threads that run the incrementCounter function
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    // Expected result: 20000, but due to race conditions, the actual result may be inconsistent
    std::cout << "Final Counter Value: " << counter << "\n";

    std::cout << "Main thread finished.\n";
    return 0;
}
