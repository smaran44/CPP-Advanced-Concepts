/*
    Program: Sort Students by Marks (Descending)
    ------------------------------------------------
    What it does:
    - Defines a custom data structure `Student` with name and marks.
    - Sorts a list of students based on their marks in descending order.
    - Prints the sorted list with names and marks.

    Logic used:
    - Uses `std::sort` from `<algorithm>` with a custom comparator function.
*/

#include <iostream>     // For input/output
#include <vector>       // For using vector container
#include <algorithm>    // For sort function

using namespace std;

// Custom structure to represent a student
struct Student {
    string name;  // Name of the student
    int marks;    // Marks of the student
};

// Comparator function to sort students by marks in descending order
bool compare(Student a, Student b) {
    return a.marks > b.marks;  // Returns true if a has more marks than b
}

int main() {
    // Initialize a vector of students with names and marks
    vector<Student> students = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    // Sort the vector using the custom comparator
    sort(students.begin(), students.end(), compare);

    // Print the sorted list of students
    for (auto s : students) {
        cout << s.name << ": " << s.marks << endl;
    }

    return 0;  // Successful execution
}
