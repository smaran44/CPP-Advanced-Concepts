#include <iostream>
#include <map>

using namespace std;

int main() {
    // Definition: A multimap allows duplicate keys.

    multimap<int, string> students;

    // Inserting values (duplicate keys allowed)
    students.insert({101, "Alice"});
    students.insert({102, "Bob"});
    students.insert({101, "Alex"});  // Duplicate key

    // Displaying all values
    cout << "All Students:\n";
    for (auto &student : students) {
        cout << "Roll No: " << student.first << ", Name: " << student.second << endl;
    }

    return 0;
}
