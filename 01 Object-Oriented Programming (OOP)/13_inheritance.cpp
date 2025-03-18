// inheritance: A mechanism in which one class acquires the properties (methods and fields) of another class.

#include <iostream>
using namespace std;

// 🔹 Base Class (Parent)
class Person {
public:
    string name;
    int age;

    // Constructor of Parent Class
    Person(string n, int a) {
        cout << "Person Constructor Called" << endl;
        name = n;
        age = a;
    }

    // Destructor of Parent Class
    ~Person() {
        cout << "Person Destructor Called" << endl;
    }

    // Function to display person details
    void showPersonDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// 🔹 Derived Class (Child) inheriting from Person using `public` mode
class Student : public Person {
public:
    int rollNo;

    // Constructor of Child Class
    Student(string n, int a, int r) : Person(n, a) {  // Calling Parent Constructor
        cout << "Student Constructor Called" << endl;
        rollNo = r;
    }

    // Destructor of Child Class
    ~Student() {
        cout << "Student Destructor Called" << endl;
    }

    // Function to display student details
    void showStudentDetails() {
        showPersonDetails();  // Calling base class function
        cout << "Roll No: " << rollNo << endl;
    }
};

int main() {
    // Creating an object of Student
    cout << "Creating Student Object...\n";
    Student s1("John", 20, 101);

    cout << "\nDisplaying Student Details...\n";
    s1.showStudentDetails();

    cout << "\nEnd of Program. Object will be destroyed...\n";
    return 0;
}
