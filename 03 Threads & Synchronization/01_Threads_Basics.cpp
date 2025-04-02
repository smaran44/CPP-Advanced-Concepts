/*
 * Multithreading in C++ - Basics
 * --------------------------------
 * Threads allow concurrent execution of code, optimizing CPU usage and reducing execution time.
 * The C++ Standard Library provides "std::thread" for creating and managing threads.
 * 
 * Key Concepts:
 * 1. Creating a Thread
 * 2. Joining a Thread (Waiting for completion)
 * 3. Detaching a Thread (Running independently)
 * 4. Passing Arguments to a Thread
 * 5. Using Lambda Functions with Threads
 */

 #include <iostream>
 #include <thread>  // Include thread library
 using namespace std;
 
 // Function to be executed by a thread
 void printMessage() {
     cout << "Hello from a thread!\n";
 }
 
 // Function that takes an argument
 void printNumber(int num) {
     cout << "Number: " << num << "\n";
 }
 
 int main() {
     // 1. Creating a thread
     thread t1(printMessage);
     
     // 2. Joining the thread (Ensuring it completes execution before main exits)
     t1.join();
     
     cout << "Main thread execution continues...\n";
     
     // 3. Passing an argument to a thread
     thread t2(printNumber, 42);
     t2.join();
     
     // 4. Using a lambda function in a thread
     thread t3([](){ cout << "Hello from a lambda thread!\n"; });
     t3.join();
     
     return 0;
 }
 