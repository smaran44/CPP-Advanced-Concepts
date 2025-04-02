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

 #include <iostream>
 #include <thread>
 #include <mutex>  // Include mutex library
 using namespace std;
 
 int counter = 0; // Shared resource
 mutex mtx; // Mutex for synchronization
 
 // Function that increments counter in a loop
 void increment(int id) {
     for (int i = 0; i < 100000; ++i) {
         mtx.lock();  // Lock the mutex
         ++counter;   // Critical section
         mtx.unlock(); // Unlock the mutex
     }
     cout << "Thread " << id << " finished execution.\n";
 }
 
 int main() {
     // Creating multiple threads
     thread t1(increment, 1);
     thread t2(increment, 2);
     
     // Joining threads to ensure they complete execution
     t1.join();
     t2.join();
     
     // Display final counter value
     cout << "Final counter value: " << counter << "\n";
     
     return 0;
 }
 