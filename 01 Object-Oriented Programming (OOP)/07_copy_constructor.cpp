#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // ✅ Default Constructor
    Person() {  
        name = "Unknown";  
        age = 0;
        cout << "Default Constructor Called\n";
    }

    // ✅ Parameterized Constructor
    Person(string n, int a) {  
        name = n;  
        age = a;
        cout << "Parameterized Constructor Called\n";
    }

    // ✅ Copy Constructor
    Person(const Person &p) {  // pass by reference
        name = p.name;  
        age = p.age;
        cout << "Copy Constructor Called\n";
    }

    // ✅ Method to display details
    void showDetails() {  
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Default Constructor
    Person p1;  
    p1.showDetails();

    // Parameterized Constructor
    Person p2("Alice", 22);
    p2.showDetails();

    // Copy Constructor (Creating p3 as a copy of p2)
    Person p3 = p2;
    p3.showDetails();

    // Copy Constructor (Creating p4 using direct initialization)
    Person p4(p2);// default copy constructor is called
    p4.showDetails();

    return 0;
}
