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

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtxA, mtxB; // Two mutexes

void thread1() {
    std::cout << "Thread 1: Trying to lock Mutex A and B\n";
    std::lock(mtxA, mtxB); // Lock both at the same time
    
    std::unique_lock<std::mutex> lockA(mtxA, std::adopt_lock);
    std::unique_lock<std::mutex> lockB(mtxB, std::adopt_lock);
    
    std::cout << "Thread 1: Acquired both Mutex A and B\n";
}

void thread2() {
    std::cout << "Thread 2: Trying to lock Mutex A and B\n";
    std::lock(mtxA, mtxB); // Lock both at the same time
    
    std::unique_lock<std::mutex> lockA(mtxA, std::adopt_lock);
    std::unique_lock<std::mutex> lockB(mtxB, std::adopt_lock);
    
    std::cout << "Thread 2: Acquired both Mutex A and B\n";
}

int main() {
    std::cout << "Main thread started.\n";
    
    std::thread t1(thread1);
    std::thread t2(thread2);
    
    t1.join();
    t2.join();
    
    std::cout << "Main thread finished.\n";
    return 0;
}
