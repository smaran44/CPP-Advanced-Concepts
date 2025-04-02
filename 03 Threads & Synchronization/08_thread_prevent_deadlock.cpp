/*
==================================================
   Preventing Deadlocks in Multithreading
==================================================

How to Avoid Deadlocks?
------------------------
- Always acquire locks in the same order in all threads.
- Use std::lock() to lock multiple mutexes at once.
- Use std::unique_lock for more flexible locking mechanisms.

Better Approach:
----------------
- Instead of locking mutexes separately, use std::lock() to lock both mutexes simultaneously.
- This prevents circular waiting and eliminates deadlock risk.
*/

#include <iostream>  // For input and output operations
#include <thread>    // For multithreading support
#include <mutex>     // For mutex (mutual exclusion) to handle concurrency

// Define two mutexes for synchronization
std::mutex mtxA, mtxB; 

// Function executed by the first thread
void thread1() {
    std::cout << "Thread 1: Trying to lock Mutex A and B\n";
    
    // Use std::lock to lock both mutexes at the same time, preventing deadlock
    std::lock(mtxA, mtxB);
    
    // Associate the acquired locks with unique_lock and adopt them
    std::unique_lock<std::mutex> lockA(mtxA, std::adopt_lock);
    std::unique_lock<std::mutex> lockB(mtxB, std::adopt_lock);
    
    // Critical section - both mutexes are acquired
    std::cout << "Thread 1: Acquired both Mutex A and B\n";
}

// Function executed by the second thread
void thread2() {
    std::cout << "Thread 2: Trying to lock Mutex A and B\n";
    
    // Use std::lock to avoid deadlocks by locking both mutexes at once
    std::lock(mtxA, mtxB);
    
    // Use unique_lock with adopt_lock to manage the locks
    std::unique_lock<std::mutex> lockA(mtxA, std::adopt_lock);
    std::unique_lock<std::mutex> lockB(mtxB, std::adopt_lock);
    
    // Critical section - both mutexes are acquired
    std::cout << "Thread 2: Acquired both Mutex A and B\n";
}

int main() {
    std::cout << "Main thread started.\n";

    // Create two threads that execute thread1 and thread2 functions
    std::thread t1(thread1);
    std::thread t2(thread2);

    // Wait for both threads to finish execution before continuing
    t1.join();
    t2.join();

    std::cout << "Main thread finished.\n";
    return 0;
}
