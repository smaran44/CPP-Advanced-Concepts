#include <iostream>
#include <vector>  // Include the vector library

using namespace std;

int main() {
    // Definition: A vector is a dynamic array that can grow and shrink in size.
    
    // Declaring a vector of integers
    vector<int> numbers;

    // Adding elements using push_back()
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Accessing elements using indexing
    cout << "First element: " << numbers[0] << endl;
    cout << "Second element: " << numbers[1] << endl;
    cout << "Third element: " << numbers[2] << endl;

    // Accessing elements using the at() method (safe access)
    cout << "Element at index 1 using at(): " << numbers.at(1) << endl;

    // front and back
    cout << "First element using front(): " << numbers.front() << endl;
    cout << "Last element using back(): " << numbers.back() << endl;

    // Using a loop to iterate over the vector
    cout << "Vector elements: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Using a range-based for loop
    cout << "Using range-based for loop: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // vector with size and same element
    vector<int> vec(3,10);

    for (int vec : vec) {
        cout << vec << " ";
    }
    cout << endl;

    //copy
    vector <int> vec2(numbers);

    for (int vec : vec2) {
        cout << vec << " ";
    }
    cout << endl;

    return 0;
}
