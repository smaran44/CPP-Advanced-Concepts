#include <iostream>
#include <utility>  // Required for std::pair

using namespace std;

int main() {
    // Definition: A pair is a container that holds two values of possibly different types.
    
    // Creating a pair of an integer and a string
    pair<int, string> student;
    
    // Assigning values
    student.first = 101;
    student.second = "Alice";

    // Accessing elements
    cout << "Roll Number: " << student.first << endl;
    cout << "Name: " << student.second << endl;

    // Another way to initialize a pair using make_pair()
    pair<double, char> data = make_pair(3.14, 'A');

    cout << "Double value: " << data.first << ", Character: " << data.second << endl;

    return 0;
}
