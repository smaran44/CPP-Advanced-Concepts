#include <iostream>
using namespace std;

// 🔹 Base Class
class Animal {
protected:
    string species = "Unknown Animal";
public:
    void showSpecies() {
        cout << "Species: " << species << endl;
    }
};

// ✅ Public Inheritance
class Dog : public Animal {
public:
    Dog() { species = "Dog"; }
};

// ✅ Private Inheritance
class Cat : private Animal {
public:
    Cat() { species = "Cat"; }
    void display() {
        showSpecies();  // Allowed inside class
    }
};

// ✅ Protected Inheritance
class Lion : protected Animal {
public:
    Lion() { species = "Lion"; }
    void show() {
        showSpecies();  // Allowed inside class
    }
};

int main() {
    // 🔹 Public Inheritance
    Dog d;
    d.showSpecies();  // ✅ Allowed because public inheritance keeps public members public

    cout << "-------------------------------\n";

    // 🔹 Private Inheritance
    Cat c;
    c.display();  // ✅ Allowed inside class
    // c.showSpecies();  // ❌ Error: showSpecies() is private in Cat

    cout << "-------------------------------\n";

    // 🔹 Protected Inheritance
    Lion l;
    l.show();  // ✅ Allowed inside class
    // l.showSpecies();  // ❌ Error: showSpecies() is protected in Lion

    return 0;
}
/*
| Inheritance Mode   | Effect on Public & Protected Members of Base Class | Access in Derived Class                       | Access in main()                |
|--------------------|----------------------------------------------------|----------------------------------------------|---------------------------------|
| Public Inheritance | Members retain their access levels.                | Public remains public, protected remains protected. | ✅ Can access public members.    |
| Private Inheritance| Public & protected members become private.         | Accessible only inside the class.            | ❌ Cannot access directly.       |
| Protected Inheritance | Public & protected members become protected.    | Accessible in derived classes but not outside. | ❌ Cannot access directly.       |
*/