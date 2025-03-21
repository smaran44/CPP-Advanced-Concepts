#include <iostream>   // For input and output
#include <vector>     // For using the vector container
#include <chrono>     // For measuring execution time

using namespace std;
using namespace chrono;  // Allows us to use time-related functions easily

int main() {
    vector<int> numbers;  // Declare an empty vector of integers

    auto start = high_resolution_clock::now();  // Record the start time
    //auto is used to automatically deduce the type of the variable

    // Insert 1 million elements into the vector
    for (int i = 0; i < 1000000; i++) {
        numbers.push_back(i);  // Push elements one by one
    }

    auto end = high_resolution_clock::now();  // Record the end time

    // Calculate the time taken for the insertion
    auto duration = duration_cast<milliseconds>(end - start);
    
    // Print the execution time in milliseconds
    cout << "Time taken to insert 1 million elements: " << duration.count() << " ms" << endl;

    return 0;
}

