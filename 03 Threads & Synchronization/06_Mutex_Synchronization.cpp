/*
 * Mutex & Synchronization in C++
 * --------------------------------
 * When multiple threads access shared data, race conditions can occur.
 * Mutex (short for "mutual exclusion") helps prevent data corruption by ensuring only one thread accesses shared data at a time.
 * 
 * Key Concepts:
 * 1. Race Conditions (Why Mutex is Needed)
 * 2. Using std::mutex for Synchronization
 * 3. Locking and Unlocking a Mutex
 * 4. Using std::lock_guard for Automatic Lock Management
 * 
 * 
==================================================
   Solving Race Conditions using Mutex
==================================================
 * 
 * What is a Mutex?
----------------
- A Mutex (Mutual Exclusion) is used to prevent multiple threads from accessing shared data simultaneously.
- It ensures that only one thread modifies the shared resource at a time.
- Helps to avoid race conditions and maintain data integrity.

How to Use a Mutex?
-------------------
- Lock the mutex before modifying shared data.
- Unlock the mutex after modification is done.
- Use std::lock_guard or std::unique_lock for automatic unlocking.

 */

 #include <iostream>   // For input and output operations
 #include <thread>     // For working with threads
 #include <mutex>      // For using mutex locks
 
 using namespace std;
 
 int counter = 0;  // Shared resource (global variable)
 mutex mtx;        // Mutex for synchronization
 
 // Function executed by multiple threads to increment the counter
 void increment(int id) {
     for (int i = 0; i < 100000; ++i) {
         mtx.lock();   // Lock the mutex to ensure only one thread modifies `counter` at a time
         ++counter;    // Critical section: modifying shared resource
         mtx.unlock(); // Unlock the mutex after updating the counter
     }
     
     // Print when the thread finishes execution
     cout << "Thread " << id << " finished execution.\n";
 }
 
 int main() {
     // Creating two threads that run the increment function
     thread t1(increment, 1);
     thread t2(increment, 2);
     
     // Wait for both threads to finish execution
     t1.join();
     t2.join();
     
     // Display the final value of the counter after both threads complete
     cout << "Final counter value: " << counter << "\n";
     
     return 0;
 }
 