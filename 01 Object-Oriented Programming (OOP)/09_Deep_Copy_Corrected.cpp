#include <iostream>
#include <cstring> // For strcpy

using namespace std;

class Person {
private:
    char *name; // Dynamically allocated memory
    int *age;   // Dynamically allocated memory for age

public:
    // ✅ Constructor
    Person(const char *n, int a) {
        name = new char[strlen(n) + 1]; // Allocate memory for name
        strcpy(name, n); // Copy the string

        age = new int; // Allocate memory for age
        *age = a;      // Assign value

        cout << "Constructor Called\n";
    }

    // ✅ Corrected Deep Copy Constructor
    Person(const Person &p) {
        name = new char[strlen(p.name) + 1]; // Allocate new memory for name
        strcpy(name, p.name); // Copy the actual content

        age = new int; // Allocate new memory for age
        *age = *(p.age); // Copy the value of age
        // *(p.age) is the value at the address pointed by p.age

        cout << "Deep Copy Constructor Called\n";
    }

    // ✅ Setter Method to Modify Age
    void setAge(int a) {
        *age = a;
    }

    // ✅ Display Details
    void showDetails() {
        cout << "Name: " << name << ", Age: " << *age << endl;
    }

    // ✅ Destructor
    ~Person() {
        delete[] name; // Free dynamically allocated memory
        delete age;    // Free dynamically allocated memory
        cout << "Destructor Called\n";
    }
};

int main() {
    // Creating object
    Person p1("Alice", 25);
    p1.showDetails();

    // Copying object using deep copy constructor
    Person p2 = p1;
    p2.showDetails();

    // ✅ Correct way to modify p2's age
    p2.setAge(30);

    cout << "After modifying p2's age:\n";
    p1.showDetails(); // ✅ p1's age remains unchanged
    p2.showDetails();

    return 0; // No crash, as each object has its own memory.
}
