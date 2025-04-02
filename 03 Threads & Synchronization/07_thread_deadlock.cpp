/*
==================================================
   Deadlocks in Multithreading
==================================================

What is a Deadlock?
-------------------
- A deadlock occurs when two or more threads are waiting for each other to release a resource, leading to an infinite wait.
- It happens when multiple locks are acquired in different orders by different threads.

Example Scenario:
-----------------
- Thread 1 locks Mutex A and waits for Mutex B.
- Thread 2 locks Mutex B and waits for Mutex A.
- Both threads are stuck forever!

How to Avoid Deadlocks?
------------------------
- Always acquire locks in the same order in all threads.
- Use std::lock() to lock multiple mutexes at once.
- Use std::unique_lock for more flexible locking mechanisms.
*/

#include <iostream>   // For input and output operations
#include <thread>     // For multithreading support
#include <mutex>      // For mutex locks to handle synchronization
#include <chrono>     // For sleep operations

// Define two mutexes for thread synchronization
std::mutex mtxA, mtxB;

void thread1() {
    std::cout << "Thread 1: Locking Mutex A\n";
    
    // Lock Mutex A first
    mtxA.lock();
    
    // Simulate some work to create a delay
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    std::cout << "Thread 1: Waiting for Mutex B\n";
    
    // Lock Mutex B after some delay
    mtxB.lock();
    
    // At this point, Thread 1 has acquired both Mutex A and B
    std::cout << "Thread 1: Acquired both Mutex A and B\n";
    
    // Unlock mutexes after the critical section is done
    mtxB.unlock();
    mtxA.unlock();
}

void thread2() {
    std::cout << "Thread 2: Locking Mutex B\n";
    
    // Lock Mutex B first
    mtxB.lock();
    
    // Simulate some work to create a delay
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    std::cout << "Thread 2: Waiting for Mutex A\n";
    
    // Lock Mutex A after some delay
    mtxA.lock();
    
    // At this point, Thread 2 has acquired both Mutex B and A
    std::cout << "Thread 2: Acquired both Mutex B and A\n";
    
    // Unlock mutexes after the critical section is done
    mtxA.unlock();
    mtxB.unlock();
}

int main() {
    std::cout << "Main thread started.\n";

    // Create two threads that execute thread1 and thread2 functions
    std::thread t1(thread1);
    std::thread t2(thread2);

    // Wait for both threads to complete execution
    t1.join();
    t2.join();

    std::cout << "Main thread finished.\n";
    return 0;
}

// Note: This code will likely cause a deadlock, as both threads are waiting for each other to release the mutexes.
// To avoid deadlocks, ensure that all threads acquire locks in the same order or use std::lock() to lock multiple mutexes at once.