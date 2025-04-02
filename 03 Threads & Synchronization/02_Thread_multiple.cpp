/*
===============================================
   Creating and Managing Multiple Threads
===============================================

Why Use Multiple Threads?
-------------------------
- Increases CPU utilization by running tasks concurrently.
- Speeds up execution by dividing work across multiple threads.
- Essential for real-time systems where multiple tasks must be executed in parallel.

Key Concepts:
-------------
- We can create multiple threads by instantiating multiple std::thread objects.
- Each thread executes a different function or the same function with different parameters.
- Threads must be joined or detached to avoid program termination issues.
*/

#include <iostream>
#include <thread>

// Function executed by each thread
void printTask(int id) {
    std::cout << "Thread " << id << " is running.\n";
}

int main() {
    std::cout << "Main thread started.\n";
    
    // Creating multiple threads
    std::thread t1(printTask, 1);
    std::thread t2(printTask, 2);
    std::thread t3(printTask, 3);
    
    /*
    Joining the threads:
    - Ensures main() waits for all threads to finish before exiting.
    - Prevents undefined behavior due to premature program termination.
    */
    t1.join();
    t2.join();
    t3.join();
    
    std::cout << "Main thread finished.\n";
    return 0;
}
