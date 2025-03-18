// Run time polymorphism
//Function overriding
// Parent & child both contain the same function with different implementation
// the parent class function is said to be overridden

#include <iostream>
using namespace std;

// 🔹 Base class
class Animal {
public:
    // Regular function (no virtual keyword)
    void makeSound() {
        cout << "Animal makes a sound!" << endl;
    }
};

// 🔹 Derived class (Child)
class Dog : public Animal {
public:
    // Overriding the makeSound() function
    void makeSound() {
        cout << "Dog barks!" << endl;
    }
};

int main() {
    Animal a;   // Base class object
    Dog d;      // Derived class object

    cout << " Calling functions directly:\n";
    a.makeSound();  // Calls base class function
    d.makeSound();  // Calls overridden function in Dog class

    cout << " Demonstrating priority of child class:\n";

    // Base class pointer pointing to derived class object
    Animal* ptr = &d;  
    ptr->makeSound();  // Calls Animal's makeSound() (not Dog's) due to missing virtual function

    return 0;
}
