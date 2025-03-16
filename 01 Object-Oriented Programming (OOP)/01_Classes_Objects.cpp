#include <iostream>
using namespace std;

// Defining a Class
class Car {
public:  
    // Data Members (Attributes)
    string brand;
    int year;

    // Member Function
    void displayCar() {
        cout << "Car Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    // Creating an Object of Class Car
    Car car1;
    // Car - class name, car1 - object name

    // Assigning values to Object's Attributes
    car1.brand = "Toyota";
    car1.year = 2022;

    // Calling the Member Function
    car1.displayCar();

    return 0;
}
