#include <iostream>
#include <cstring> // For strcpy

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // ✅ Default Constructor
    Person() : name("Unknown"), age(0) {
        cout << "Default Constructor Called\n";
    }

    // ✅ Parameterized Constructor
    Person(string n, int a) : name(n), age(a) {
        cout << "Parameterized Constructor Called\n";
    }

    // ✅ Constructor with Only Name
    Person(string n) : name(n), age(18) { // Default age assigned
        cout << "Constructor with Only Name Called\n";
    }

    // ✅ Constructor with Only Age
    Person(int a) : name("Unnamed"), age(a) { // Default name assigned
        cout << "Constructor with Only Age Called\n";
    }

    // ✅ Copy Constructor (Deep Copy)
    Person(const Person &p) : name(p.name), age(p.age) {
        cout << "Copy Constructor Called\n";
    }

    // ✅ Display Function
    void showDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

     // ✅ Destructor
     ~Person() {
        cout << "Destructor Called for " << name << "\n";
    }
};

int main() {
    Person p1;                 // Default Constructor
    Person p2("Alice", 25);     // Parameterized Constructor
    Person p3("Bob");          // Constructor with Only Name
    Person p4(22);             // Constructor with Only Age
    Person p5(p2);             // Copy Constructor

    cout << "\nDisplaying Details:\n";
    p1.showDetails();
    p2.showDetails();
    p3.showDetails();
    p4.showDetails();
    p5.showDetails();

    cout << "\nExiting Program, Destructors Will be Called Automatically..." << endl;
    
    return 0;
}
