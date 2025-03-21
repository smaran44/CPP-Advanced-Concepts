#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Definition: An unordered_map is a hash table-based key-value storage.

    unordered_map<string, int> wordCount;

    // Inserting values (key-value pairs)
    wordCount["apple"] = 5;
    wordCount["banana"] = 3;
    wordCount["cherry"] = 7;

    // Accessing values using keys
    cout << "Apple count: " << wordCount["apple"] << endl;
    cout << "Banana count: " << wordCount["banana"] << endl;

    // Iterating through unordered_map (Order is not guaranteed)
    cout << "All word counts:\n";
    for (auto &pair : wordCount) {
        cout << "Word: " << pair.first << ", Count: " << pair.second << endl;
    }

    return 0;
}
