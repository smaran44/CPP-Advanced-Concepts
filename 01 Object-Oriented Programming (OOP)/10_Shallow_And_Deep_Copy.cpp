#include <iostream>
#include <cstring>  // For strcpy and strdup

using namespace std;

class Person {
private:
    char *name; // Dynamically allocated memory
    int age;

public:
    // ✅ Constructor
    Person(const char *n, int a) {
        age = a;
        name = new char[strlen(n) + 1]; // Allocate memory for name
        strcpy(name, n); // Copy the string
        cout << "Constructor Called\n";
    }

    // ✅ Shallow Copy Constructor
    Person(const Person &p) {
        name = p.name;  // Just copying the pointer (Shallow Copy)
        age = p.age;
        cout << "Shallow Copy Constructor Called\n";
    }

    // ✅ Deep Copy Constructor
    Person(const Person &p, bool deepCopy) {
        age = p.age;
        name = new char[strlen(p.name) + 1]; // Allocate new memory
        strcpy(name, p.name); // Copy the actual content
        cout << "Deep Copy Constructor Called\n";
    }

    // ✅ Display Details
    void showDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // ✅ Destructor
    ~Person() {
        delete[] name; // Free dynamically allocated memory
        cout << "Destructor Called\n";
    }
};

int main() {
    // Creating object with Constructor
    Person p1("Alice", 22);
    p1.showDetails();

    // Shallow Copy - Only pointer is copied, not the actual data
    Person p2 = p1; // Calls shallow copy constructor
    p2.showDetails();

    // Deep Copy - New memory is allocated and content is copied
    Person p3(p1, true); // Calls deep copy constructor
    p3.showDetails();

    return 0;
}
