#include <iostream>
using namespace std;

class Person {
private:
    string name;  // Private data member (Encapsulation - Data Hiding)
    int age;      // Private data member

public:
    // ✅ Default Constructor
    Person() : name("Unknown"), age(0) {}

    // ✅ Parameterized Constructor
    Person(string n, int a) : name(n), age(a) {}

    // ✅ Setter for Name
    void setName(string n) {
        name = n;
    }

    // ✅ Getter for Name
    string getName() {
        return name;
    }

    // ✅ Setter for Age (With Validation)
    void setAge(int a) {
        if (a < 0) {
            cout << "Age cannot be negative! Setting to 0.\n";
            age = 0;
        } else {
            age = a;
        }
    }

    // ✅ Getter for Age
    int getAge() {
        return age;
    }

    // ✅ Display Function
    void showDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Creating Object
    Person p1("Alice", 25);
    p1.showDetails();

    // Using Setters to Modify Private Members
    p1.setName("Bob");
    p1.setAge(30);

    cout << "Updated Name: " << p1.getName() << endl;
    cout << "Updated Age: " << p1.getAge() << endl;

    // Testing Validation
    p1.setAge(-5);  // Should print an error message and set age to 0

    cout << "Final Details: ";
    p1.showDetails();

    return 0;
}
