#include <iostream>
#include <utility>  

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

    return 0;
}
