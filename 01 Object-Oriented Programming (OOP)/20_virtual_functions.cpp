//Run time polymorphism
// Virtual functions
//A virtual function is a member function that you expect to be redefined in derived classes.

#include <iostream>
using namespace std;

// 🔹 Base class
class Animal {
public:
    // Virtual function to allow overriding
    virtual void makeSound() {
        cout << "Animal makes a sound!" << endl;
    }
};

// 🔹 Derived class (Child)
class Dog : public Animal {
public:
    // Overriding the makeSound() function
    void makeSound() override {
        cout << "Dog barks!" << endl;
    }
};

int main() {
    Animal a;   // Base class object
    Dog d;      // Derived class object

    cout << " Calling functions directly:\n";
    a.makeSound();  // Calls base class function
    d.makeSound();  // Calls overridden function in Dog class

    cout << " Demonstrating priority of child class (Runtime Polymorphism):\n";
    
    // Base class pointer pointing to derived class object
    Animal* ptr = &d;  
    ptr->makeSound();  // Calls Dog's makeSound() due to function overriding

    return 0;
}
