// using abstraction classes
// Abstract classes are used to provide a base class from which other classes can be derived.
// they cannot be instantiated and are meant to be inherited
// abstract classes are typically used to define an interface for derived classes.

#include <iostream>
using namespace std;

// 🔹 Abstract class (contains at least one pure virtual function)
class Animal {
public:
    string name;

    // 🔹 Constructor
    Animal(string n) {
        name = n;
        cout << "Animal Constructor: " << name << " created!" << endl;
    }

    // 🔹 Pure virtual function (must be overridden in derived classes)
    virtual void makeSound() = 0;

    // 🔹 Regular function (not abstract)
    void showName() {
        cout << "Animal Name: " << name << endl;
    }

    // 🔹 Virtual Destructor (ensures proper cleanup in derived classes)
    virtual ~Animal() {
        cout << "Animal Destructor: " << name << " destroyed!" << endl;
    }
};

// 🔹 Derived class: Dog
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {
        cout << "Dog Constructor: " << name << " created!" << endl;
    }

    // 🔹 Overriding the pure virtual function
    void makeSound() override {
        cout << name << " says: Woof Woof!" << endl;
    }

    ~Dog() {
        cout << "Dog Destructor: " << name << " destroyed!" << endl;
    }
};

// 🔹 Derived class: Cat
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {
        cout << "Cat Constructor: " << name << " created!" << endl;
    }

    // 🔹 Overriding the pure virtual function
    void makeSound() override {
        cout << name << " says: Meow Meow!" << endl;
    }

    ~Cat() {
        cout << "Cat Destructor: " << name << " destroyed!" << endl;
    }
};

int main() {
    //  Animal a("Generic");  // Error! Cannot instantiate an abstract class

    cout << "Creating Dog object:\n";
    Animal* animal1 = new Dog("Buddy");
    animal1->showName();   // Calls showName() from Animal class
    animal1->makeSound();  // Calls overridden function from Dog class
    delete animal1;        // Proper cleanup (calls destructors in order)

    cout << "\nCreating Cat object:\n";
    Animal* animal2 = new Cat("Whiskers");
    animal2->showName();   // Calls showName() from Animal class
    animal2->makeSound();  // Calls overridden function from Cat class
    delete animal2;        // Proper cleanup (calls destructors in order)

    return 0;
}
