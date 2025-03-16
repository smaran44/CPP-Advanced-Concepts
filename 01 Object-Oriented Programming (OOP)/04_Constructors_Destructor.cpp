#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int modelYear;

public:
    // Default Constructor (No arguments)
    Car() {
        brand = "Unknown";
        modelYear = 0;
        cout << "Default Constructor Called!" << endl;
    }

    // Parameterized Constructor
    Car(string b, int y) {
        brand = b;
        modelYear = y;
        cout << "Parameterized Constructor Called!" << endl;
    }

    // Copy Constructor
    Car(const Car &other) {
        brand = other.brand;
        modelYear = other.modelYear;
        cout << "Copy Constructor Called!" << endl;
    }

    // Display car details
    void showDetails() {
        cout << "Car Brand: " << brand << ", Model Year: " << modelYear << endl;
    }

    // Destructor
    ~Car() {
        cout << "Destructor Called for " << brand << "!" << endl;
    }
};

int main() {
    cout << "Creating Car1 using Default Constructor..." << endl;
    Car car1;  // Default constructor is called
    car1.showDetails();

    cout << "\nCreating Car2 using Parameterized Constructor..." << endl;
    Car car2("Toyota", 2023);  // Parameterized constructor is called
    car2.showDetails();

    cout << "\nCreating Car3 using Copy Constructor from Car2..." << endl;
    Car car3 = car2;  // Copy constructor is called
    car3.showDetails();

    cout << "\nEnd of main function. Objects will be destroyed now...\n";

    return 0; // Destructor will be called automatically for car1, car2, and car3
}
/*
A constructor is a special member function in a class that is automatically called when an object is created. It is used to initialize objects.

🔹 Key Features of Constructors:
✔ Same name as the class
✔ No return type (not even void)
✔ Automatically invoked when an object is created
✔ Can be overloaded (multiple constructors with different parameters)

📌 Types of Constructors
Default Constructor – No parameters, initializes default values.
Parameterized Constructor – Accepts parameters to initialize object with user-defined values.
Copy Constructor – Copies data from an existing object to a new one.

📌 What is a Destructor?
A destructor is a special function that destroys objects when they go out of scope.

Syntax: ~ClassName() {}
It is automatically called when an object is deleted.
Used for clean-up operations like closing files or freeing memory.
Cannot be overloaded (only one destructor per class).

*/