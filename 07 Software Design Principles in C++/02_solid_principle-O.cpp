//Open/Closed Principle (OCP)
//A class should be open for extension but closed for modification.
//Use polymorphism to extend functionality without modifying existing code.

#include <iostream> // Required for input-output operations
using namespace std;

// Abstract base class representing a generic shape
class Shape {
public:
    // Pure virtual function to calculate the area (makes this an abstract class)
    virtual double area() const = 0; // Open for extension (OCP - Open/Closed Principle)

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class representing a Circle, extending Shape
class Circle : public Shape {
private:
    double radius; // Radius of the circle

public:
    // Constructor to initialize the radius
    Circle(double r) : radius(r) {}

    // Overriding the virtual function to compute the area of a circle
    double area() const override {
        return 3.14159 * radius * radius; // π * r^2 formula
    }
};

// Derived class representing a Rectangle, extending Shape
class Rectangle : public Shape {
private:
    double width, height; // Dimensions of the rectangle

public:
    // Constructor to initialize width and height
    Rectangle(double w, double h) : width(w), height(h) {}

    // Overriding the virtual function to compute the area of a rectangle
    double area() const override {
        return width * height; // Formula: width * height
    }
};

// Function that works with any shape using polymorphism
void printArea(const Shape& shape) {
    cout << "Area: " << shape.area() << endl;
}

int main() {
    // Creating objects of Circle and Rectangle
    Circle circle(5);         // Circle with radius 5
    Rectangle rectangle(4, 6); // Rectangle with width 4 and height 6
    
    // Using polymorphism to compute and print areas
    printArea(circle);
    printArea(rectangle);

    return 0;
}
