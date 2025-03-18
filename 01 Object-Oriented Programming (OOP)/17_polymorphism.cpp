/*Polymorphism allows functions to behave differently based on the object that calls them.

polymorphism is the ability of objects to take on different forms or behave in different ways depending
on the context in which they are used

👉 It is of two types:

Compile-time Polymorphism (Function Overloading)
Runtime Polymorphism (Function Overriding using Virtual Functions)*/

#include <iostream>
using namespace std;

// 🔹 Class representing a student
class Student {
public:
    string name;  // Member variable to store the student's name

    // ✅ Non-parameterized (default) constructor
    Student() {
        cout << "Non-parameterized constructor\n";
    }

    // ✅ Parameterized constructor
    Student(string name) {
        this->name = name; // Assigns the passed argument to the member variable
        cout << "Parameterized constructor\n";
    }
};

int main() {
    // 🔹 Creating an object without arguments
    //    ➝ Calls the non-parameterized constructor
    Student s1;  

    // 🔹 Creating an object with a name argument
    //    ➝ Calls the parameterized constructor
    Student s2("Tony Stark");

    return 0;
}

