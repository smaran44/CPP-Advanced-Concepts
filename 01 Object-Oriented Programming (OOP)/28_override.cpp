#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function allows derived classes to override it
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class Dog, inheriting from Animal
class Dog : public Animal {
public:
    // Overriding the base class method
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class Cat, inheriting from Animal
class Cat : public Animal {
public:
    // Overriding the base class method
    void makeSound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Creating pointers to base class but assigning derived class objects
    Animal* a1 = new Dog(); // a1 points to Dog object
    Animal* a2 = new Cat(); // a2 points to Cat object
    
    // Calling overridden methods using base class pointers
    a1->makeSound(); // Calls Dog's makeSound() due to polymorphism
    a2->makeSound(); // Calls Cat's makeSound() due to polymorphism
    
    // Freeing dynamically allocated memory
    delete a1;
    delete a2;
    
    return 0;
}
