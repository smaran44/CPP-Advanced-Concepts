#include <iostream>
#include <map>

using namespace std;

// Custom comparator for descending order sorting
struct DescendingOrder {
    bool operator()(int a, int b) const {
        return a > b;  // Sort keys in descending order
    }
};

int main() {
    // Map with a custom comparator for descending order sorting
    map<int, string, DescendingOrder> students;

    students[101] = "Alice";
    students[102] = "Bob";
    students[103] = "Charlie";

    cout << "Students in descending order of roll number:\n";
    for (auto &student : students) {//auto is used to automatically deduce the type of the variable
        cout << "Roll No: " << student.first << ", Name: " << student.second << endl;
    }

    return 0;
}
