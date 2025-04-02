/*
    Class Templates in C++ (Generic Classes)
    --------------------------------------
    - Class templates allow creating flexible and reusable classes.
    - They enable defining classes with generic types, making them adaptable for different data types.
    - Useful for implementing data structures like stacks, queues, and linked lists.
*/

#include <iostream>

using namespace std;

// Class template for a simple Box
template <typename T> // 'T' is a placeholder for any data type
class Box {
private:
    T value; // Member variable to store data of type 'T'

public:
    // Constructor: Initializes the value
    Box(T val) : value(val) {}

    // Function to display the stored value
    void show() { 
        cout << "Box contains: " << value << endl; 
    }
};

int main() {
    // Creating Box objects with different data types
    Box<int> intBox(100);       // Box storing an integer
    Box<double> doubleBox(5.75); // Box storing a double
    Box<string> strBox("Hello"); // Box storing a string

    // Displaying the stored values
    intBox.show();   
    doubleBox.show();
    strBox.show();
    
    return 0;
}

