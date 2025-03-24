#include <iostream>
#include <utility>  
#include <vector> 

using namespace std;

int main() {
    // Nested Pairs: A pair inside another pair

    pair<int, pair<string, double>> student;

    // Assigning values
    student.first = 101;  // Roll number
    student.second.first = "Alice";  // Name
    student.second.second = 9.5;  // GPA

    // Accessing values
    cout << "Roll Number: " << student.first << endl;
    cout << "Name: " << student.second.first << endl;
    cout << "GPA: " << student.second.second << endl;

    vector<pair<int, pair<string, double>>> students;
    students.push_back(make_pair(102, make_pair("Bob", 8.5)));
    students.push_back(make_pair(103, make_pair("Charlie", 9.0)));
    students.push_back(make_pair(104, make_pair("David", 7.5)));

    // Displaying all students
    cout << "All Students:" << endl;
    for (auto& s : students) {
        cout << "Roll Number: " << s.first << ", Name: " << s.second.first << ", GPA: " << s.second.second << endl;
    }

    return 0;
}
