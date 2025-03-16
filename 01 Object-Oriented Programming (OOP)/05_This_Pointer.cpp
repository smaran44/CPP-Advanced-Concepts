// this is a special pointer in C++ that points to the object itself. 
//It is used to access the object's own memory locations.

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor using this pointer
    Person(string name, int age) {
        this->name = name;  // 'this' is used to distinguish between parameter and data member
        this->age = age;    // left side is data member, right side is parameter
        // parameter is a local variable, data member is a class variable
    }

    // Method to display details
    void showDetails() {
        cout << "Name: " << this->name << ", Age: " << this->age << endl;
    }

    // Method returning current object using this pointer (Method Chaining)
    Person& setAge(int age) {
        this->age = age;
        return *this;  // Returning current object reference
    }
};

int main() {
    // Creating an object
    Person p1("Alice", 22);
    p1.showDetails();

    // Updating age using method chaining
    p1.setAge(25).showDetails();  // Method chaining using this pointer

    return 0;
}
