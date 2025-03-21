#include <iostream>
#include <tuple>  // Required for tuples

using namespace std;

int main() {
    // Definition: A tuple can store multiple values of different types.
    
    tuple<int, string, double> student(101, "Alice", 9.5);

    // Accessing elements using get<index>()
    cout << "Roll Number: " << get<0>(student) << endl;
    cout << "Name: " << get<1>(student) << endl;
    cout << "GPA: " << get<2>(student) << endl;

    // Modifying tuple values
    get<1>(student) = "Bob";  
    cout << "Updated Name: " << get<1>(student) << endl;

    return 0;
}
