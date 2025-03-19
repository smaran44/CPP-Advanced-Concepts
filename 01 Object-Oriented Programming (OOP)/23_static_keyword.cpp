//static variables
// variables declared as static in a function are created & initialised once for the lifetime of the program. //in function scope
// static variables in a class are created & initialised once. they are shared by all the objects of the class.//in class scope

//static objects
// static objects are created & initialised once for the lifetime of the program. they are shared by all the objects of the class.

#include <iostream>
using namespace std;

void function() {
    static int count = 0; // Static variable (initialized only once)
    count++;
    cout << "Function called " << count << " times." << endl;
}

class Counter {
public:
    static int count; // Static data member (shared across all objects)
    
    // Constructor
    Counter() {
        count++; // Increment count whenever an object is created
    }

    // Static member function (can access only static data members)
    static void showCount() {
        cout << "Total Objects Created: " << count << endl;
    }
};

// Initialize static data member (must be defined outside the class)
int Counter::count = 0;

int main() {

    cout << "Static Variable Example:\n";
    function(); // Call function (count = 1)
    function(); // Call function (count = 2)
    function(); // Call function (count = 3)

    cout << "\nStatic Data Member Example:\n";
    cout << "Creating Object 1...\n";
    Counter obj1;
    Counter::showCount(); // Accessing static function without object

    cout << "\nCreating Object 2...\n";
    Counter obj2;
    Counter::showCount();

    cout << "\nCreating Object 3...\n";
    Counter obj3;
    Counter::showCount();

    return 0;
}
