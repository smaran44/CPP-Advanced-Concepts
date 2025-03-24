#include <iostream>
#include <map>  // Required for std::map

using namespace std;

int main() {
    // Definition: A map is a sorted key-value pair data structure.
    // the specialty of map is that it stores unique keys and each key is associated with a value.
    // that means in this map, the int is the key which is unique and string is the value.

    // it provides O(log N) time complexity for insert, delete, and search operations.

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

    // the sorted order of the map is based on the key.
    // if string is used as key, then the map will be sorted in alphabetical order.
    // if int is used as key, then the map will be sorted in ascending order.

    //count is the number of elements with a specific key
    // In this case, since keys are unique, it will return 1 if the key exists and 0 if it doesn't.
    cout << "Count of student with roll number 101: " << students.count(101) << endl;
    cout << "Count of student with roll number 104: " << students.count(104) << endl;

    // Erasing an element
    students.erase(102);  // Erase student with roll number 102
    cout << "After erasing student 102:\n";
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << "Roll No: " << it->first << ", Name: " << it->second << endl;
    }

    // Finding an element
    auto it = students.find(103);
    if (it != students.end()) {
        cout << "Found student with roll number 103: " << it->second << endl;
    } else {
        cout << "Student with roll number 103 not found." << endl;
    }

    // Size of the map
    cout << "Total number of students: " << students.size() << endl;
    
    // Clearing the map
    students.clear();
    cout << "After clearing, total number of students: " << students.size() << endl;

    return 0;
}
