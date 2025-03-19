#include <iostream>
using namespace std;

// Class representing a Point in 2D space
class Point {
private:
    int x, y; // Private member variables to store coordinates

public:
    // Constructor with default values (if no arguments are provided, x = 0, y = 0)
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the '+' operator to add two Point objects
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y); // Returns a new Point with summed coordinates
    }

    // Overloading the '-' operator to subtract two Point objects
    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y); // Returns a new Point with subtracted coordinates
    }

    // Overloading the '==' operator to compare two Point objects
    bool operator==(const Point& p) {
        return (x == p.x && y == p.y); // Returns true if both x and y are equal
    }

    // Overloading the '<<' operator for printing (without 'friend' keyword)
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Creating two Point objects with given coordinates
    Point p1(3, 4), p2(1, 2);

    // Adding two Point objects using overloaded '+' operator
    Point p3 = p1 + p2;
    cout << "p1 + p2 = ";
    p3.print();  // Calls the print function
    cout << endl;

    // Subtracting two Point objects using overloaded '-' operator
    Point p4 = p1 - p2;
    cout << "p1 - p2 = ";
    p4.print();  // Calls the print function
    cout << endl;

    // Checking equality using overloaded '==' operator
    if (p1 == p2)
        cout << "p1 and p2 are equal." << endl;
    else
        cout << "p1 and p2 are not equal." << endl;

    return 0;
}
