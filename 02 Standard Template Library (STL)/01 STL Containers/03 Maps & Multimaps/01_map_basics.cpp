#include <iostream>
#include <map>  // Required for std::map

using namespace std;

int main() {
    // Definition: A map is a sorted key-value pair data structure.

    map<int, string> students;  // Map with integer keys and string values

    // Inserting values
    students[101] = "Alice";
    students[102] = "Bob";
    students[103] = "Charlie";

    // Accessing values
    cout << "Student 101: " << students[101] << endl;
    cout << "Student 102: " << students[102] << endl;

    // Using an iterator to traverse the map
    cout << "All Students:\n";
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << "Roll No: " << it->first << ", Name: " << it->second << endl;
    }

    return 0;
}
