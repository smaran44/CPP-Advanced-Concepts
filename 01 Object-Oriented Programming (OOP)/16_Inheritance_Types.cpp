#include <iostream>
using namespace std;

// 🔹 Base Class (Parent)
class Animal {
protected:
    string name; // Protected member so derived classes can access it
public:
    Animal(string n) : name(n) {}  // Constructor to initialize name
    void showName() {
        cout << "Animal Name: " << name << endl;
    }
};

// ✅ 1️⃣ Single Inheritance: One class inherits from another.
class Dog : virtual public Animal {  // Virtual inheritance to avoid duplication issues in hybrid inheritance
public:
    Dog(string n) : Animal(n) {} // Constructor to initialize base class
    void bark() {
        cout << name << " is barking!" << endl;
    }
};

// ✅ 2️⃣ Multiple Inheritance: A class inherits from multiple classes.
class Domestic {
public:
    void showType() {
        cout << "This is a domestic animal." << endl;
    }
};

class Cat : virtual public Animal, public Domestic {  // Virtual inheritance to resolve ambiguity
public:
    Cat(string n) : Animal(n) {} // Constructor to initialize base class
    void meow() {
        cout << name << " is meowing!" << endl;
    }
};

// ✅ 3️⃣ Multilevel Inheritance: One class inherits from another, forming a chain.
class Mammal : public Animal {
public:
    Mammal(string n) : Animal(n) {} // Constructor to initialize base class
    void showMammal() {
        cout << name << " is a mammal." << endl;
    }
};

class Lion : public Mammal {
public:
    Lion(string n) : Mammal(n) {} // Constructor to initialize base class
    void roar() {
        cout << name << " is roaring!" << endl;
    }
};

// ✅ 4️⃣ Hierarchical Inheritance: Multiple classes inherit from a single class.
class Cow : public Animal {
public:
    Cow(string n) : Animal(n) {} // Constructor to initialize base class
    void moo() {
        cout << name << " is mooing!" << endl;
    }
};

// ✅ 5️⃣ Hybrid Inheritance: Combination of two or more types of inheritance.
class HybridAnimal : public Dog, public Cat {
public:
    HybridAnimal(string n) : Animal(n), Dog(n), Cat(n) {}  // Explicitly calling Animal once to avoid ambiguity
    void hybridSound() {
        cout << name << " can both bark and meow!" << endl;
    }
};

int main() {
    // 🔹 Single Inheritance
    Dog d("Bruno");
    d.showName(); // Calls function from Animal class
    d.bark();     // Calls function from Dog class
    
    cout << "-------------------------------\n";
    
    // 🔹 Multiple Inheritance
    Cat c("Whiskers");
    c.showName();  // Calls function from Animal class
    c.meow();      // Calls function from Cat class
    c.showType();  // Calls function from Domestic class

    cout << "-------------------------------\n";

    // 🔹 Multilevel Inheritance
    Lion l("Simba");
    l.showName();  // Calls function from Animal class
    l.showMammal(); // Calls function from Mammal class
    l.roar();      // Calls function from Lion class

    cout << "-------------------------------\n";

    // 🔹 Hierarchical Inheritance
    Cow cow("Bessie");
    cow.showName(); // Calls function from Animal class
    cow.moo();      // Calls function from Cow class

    cout << "-------------------------------\n";

    // 🔹 Hybrid Inheritance
    HybridAnimal ha("Leo");
    ha.showName();  // Calls function from Animal class (no ambiguity due to virtual inheritance)
    ha.bark();      // Calls function from Dog class
    ha.meow();      // Calls function from Cat class
    ha.hybridSound(); // Calls function from HybridAnimal class

    return 0;
}
