#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor without using 'this' pointer
    Person(string n, int a) {  
        name = n;   // Directly assigning values without 'this'
        age = a;
    }

    // Method to display details
    void showDetails() {  
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Method to set age without using 'this' (No method chaining)
    void setAge(int a) {  
        age = a;  
    }

    void setName(string n) {
        name = n;
    }
};

int main() {
    // Creating an object
    Person p1("Alice", 22);
    p1.showDetails();

    // Updating age
    p1.setAge(25);
    p1.setName("Bob");
    p1.showDetails();

    return 0;
}
