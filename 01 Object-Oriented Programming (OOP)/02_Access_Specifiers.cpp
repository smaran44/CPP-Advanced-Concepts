#include <iostream>
using namespace std;

// Defining a Class
class Person {
public:  
    string name;  // Public: Can be accessed from anywhere

private:  
    int age;  // Private: Can be accessed only inside the class

protected:  
    string secret;  // Protected: Can be accessed inside the class & derived classes

public:
    // Function to set private members
    void setAge(int a) {
        age = a;
    }

    // Function to get private members
    int getAge() {
        return age;
    }

    // Function to set protected members
    void setSecret(string s) {
        secret = s;
    }

    // Function to get protected members
    string getSecret() {
        return secret;
    }
};

int main() {
    Person p1;

    // Public member access
    p1.name = "Alice";  
    cout << "Name: " << p1.name << endl;

   // p1.age = 22;  // Error: 'int Person::age' is private within this context

    // Private member access (Through Getter & Setter)
    p1.setAge(25);  
    cout << "Age: " << p1.getAge() << endl;

    // Protected member access (Through Getter & Setter)
    p1.setSecret("I love coding!");
    cout << "Secret: " << p1.getSecret() << endl;

    return 0;
}
/*
Specifier	Accessibility
public	    Accessible from anywhere.
private	    Accessible only within the class (default).
protected	Accessible within the class and its derived classes (used in inheritance).
*/