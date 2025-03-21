#include <iostream>     // For input and output operations
#include <unordered_map> // For using unordered_map

using namespace std;

int main() {
    // Hash collisions occur when multiple keys map to the same hash bucket.
    // unordered_map handles collisions using chaining (linked lists).

    unordered_map<int, string> students; // Declare an unordered_map with int keys and string values.

    // Inserting key-value pairs into the unordered_map
    students[1] = "Alice";
    students[2] = "Bob";
    students[3] = "Charlie";
    students[4] = "David";
    students[5] = "Eve";

    // Displaying the student data (unordered output)
    cout << "Students data:\n";
    for (auto &student : students) {
        cout << "ID: " << student.first << ", Name: " << student.second << endl;
    }

    // Checking the total number of buckets
    cout << "\nTotal Buckets: " << students.bucket_count() << endl;

    // Iterating through each bucket to check how elements are distributed
    for (int i = 0; i < students.bucket_count(); i++) {
        cout << "Bucket " << i << " has " << students.bucket_size(i) << " elements.\n";
    }
    
    // Important Notes:
    // 1. Elements in unordered_map are **not stored in any particular order**.
    // 2. The number of buckets **can change** dynamically as elements are inserted or removed.
    // 3. The **bucket count depends on the hash function and the load factor**.

    return 0;
}
