/*
===========================================
    Detached Threads in C++
===========================================

What is a Detached Thread?
---------------------------
- A detached thread runs independently and is not joined with the main thread.
- It continues execution even if the main thread finishes.
- Useful for background tasks that should run independently.

Key Considerations:
--------------------
- Once detached, a thread cannot be joined.
- The program must ensure the detached thread completes execution before main exits.
- Using `std::this_thread::sleep_for` can help demonstrate detached behavior.
*/

#include <iostream>
#include <thread>
#include <chrono> // For sleep functions

void backgroundTask() {
    for (int i = 1; i <= 5; i++) {
        std::cout << "Background thread running... " << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulating work
    }
    std::cout << "Background thread finished.\n";
}

int main() {
    std::cout << "Main thread started.\n";
    
    std::thread t(backgroundTask);
    
    // Detach the thread so it runs independently
    t.detach();
    
    std::cout << "Main thread finished. (Detached thread may still be running)\n";
    
    // Ensure the main thread doesn't exit immediately
    std::this_thread::sleep_for(std::chrono::seconds(6));
    return 0;
}
