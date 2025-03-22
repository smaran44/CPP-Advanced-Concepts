#include <iostream>
#include <tuple> // For using the tuple class

using namespace std;

int main() {
    // Creating a tuple using make_tuple()
    tuple<int, string, double> t1 = make_tuple(1, "Alice", 98.5);

    // Accessing elements using get<index>(tuple)
    cout << "ID: " << get<0>(t1) << ", Name: " << get<1>(t1) << ", Marks: " << get<2>(t1) << endl;

    // Modifying an element inside the tuple
    get<1>(t1) = "Bob";  // Changing name from "Alice" to "Bob"
    cout << "Updated Name: " << get<1>(t1) << endl;

    // Tuple unpacking using tie()
    int id;
    string name;
    double marks;
    tie(id, name, marks) = t1; // Unpacking values from tuple into variables

    // Displaying unpacked values
    cout << "Unpacked -> ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;

    return 0;
}
