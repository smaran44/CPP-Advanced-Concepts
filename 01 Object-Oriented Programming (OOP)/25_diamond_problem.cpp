// The Diamond Problem occurs in multiple inheritance when a derived class inherits from two base classes that both inherit from a common base class. This leads to ambiguity because the derived class gets multiple copies of the common base class.

// Solution
// To solve this problem, we use virtual inheritance, ensuring that only one instance of the common base class exists.

#include <iostream>
using namespace std;

// Base class (using virtual inheritance to prevent duplication)
class Animal {
public:
    string name;
    
    // Constructor of Animal class
    Animal(string n) : name(n) {
        cout << "Animal Constructor called for " << name << endl;
    }

    // Function to make a sound
    void makeSound() {
        cout << name << " makes a sound!" << endl;
    }

    // Destructor of Animal class
    ~Animal() {
        cout << "Animal Destructor called for " << name << endl;
    }
};

// Intermediate class Mammal, inherited virtually from Animal
class Mammal : virtual public Animal {
public:
    // Mammal constructor, calling Animal constructor indirectly
    Mammal(string n) : Animal(n) {
        cout << "Mammal Constructor called for " << name << endl;
    }

    // Destructor of Mammal class
    ~Mammal() {
        cout << "Mammal Destructor called for " << name << endl;
    }
};

// Intermediate class Bird, also inherited virtually from Animal
class Bird : virtual public Animal {
public:
    // Bird constructor, calling Animal constructor indirectly
    Bird(string n) : Animal(n) {
        cout << "Bird Constructor called for " << name << endl;
    }

    // Destructor of Bird class
    ~Bird() {
        cout << "Bird Destructor called for " << name << endl;
    }
};

// Derived class Bat, inheriting from both Mammal and Bird
class Bat : public Mammal, public Bird {
public:
    // Constructor of Bat class
    // Since Mammal and Bird inherit Animal virtually, Animal is initialized here in Bat
    Bat(string n) : Mammal(n), Bird(n), Animal(n) {
        cout << "Bat Constructor called for " << name << endl;
    }

    // Function to display Bat information
    void showInfo() {
        cout << name << " is a Bat, which is both a Mammal and a Bird." << endl;
    }

    // Destructor of Bat class
    ~Bat() {
        cout << "Bat Destructor called for " << name << endl;
    }
};

int main() {
    // Creating a Bat object
    Bat b("BatMan");

    // Calling functions of the Bat object
    b.makeSound(); // Calls makeSound() from Animal class (no ambiguity due to virtual inheritance)
    b.showInfo();  // Calls showInfo() from Bat class

    return 0;
}
