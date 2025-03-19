//abstraction - hiding all unnecessary details & showing only the important parts

#include <iostream>
using namespace std;

// 🔹 Abstract class (contains at least one pure virtual function)
class Shape {
public:
    // 🔹 Pure virtual function (makes this class abstract)
    virtual void draw() = 0; 

    // 🔹 Normal function inside the abstract class (allowed)
    void showMessage() {
        cout << "This is a shape!" << endl;
    }
};

// 🔹 Derived class: Circle (inherits from Shape)
class Circle : public Shape {
public:
    // 🔹 Implementing the pure virtual function from Shape
    void draw() override { 
        cout << "Drawing a Circle!" << endl;
    }
};

// 🔹 Derived class: Rectangle (inherits from Shape)
class Rectangle : public Shape {
public:
    // 🔹 Implementing the pure virtual function from Shape
    void draw() override { 
        cout << "Drawing a Rectangle!" << endl;
    }
};

int main() {
    //  Shape s; // Error! Cannot instantiate an abstract class
    
    // 🔹 Pointer of base class type (Shape) can hold derived class objects
    Shape* shape1;
    Circle c;
    Rectangle r;

    cout << "Using abstraction to draw shapes:" << endl;

    // 🔹 Assign Circle object to Shape pointer
    shape1 = &c;
    shape1->draw();  // Calls Circle's draw() function

    // creating without pointer
    r.draw();  // Calls Rectangle's draw() function

    return 0;
}
