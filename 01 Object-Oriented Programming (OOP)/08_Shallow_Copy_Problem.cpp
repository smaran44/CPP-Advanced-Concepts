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

    // ❌ Shallow Copy Constructor (Default)
    Person(const Person &p) {
        name = p.name; // Copies the same memory address (shallow copy)
        age = p.age;   // Both objects now share the same memory

        cout << "Shallow Copy Constructor Called\n";
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

    // Copying object using Shallow Copy
    Person p2 = p1; // Both share the same memory (BAD)
    p2.showDetails();

    // ❌ Modifying p2's age affects p1
    p2.setAge(30);

    cout << "After modifying p2's age:\n";
    p1.showDetails(); // ❌ p1's age also changed (BAD)
    p2.showDetails();

    return 0; // This may cause double deletion crash.
}
