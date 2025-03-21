#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Definition: unordered_map is a hash-based key-value data structure.
    // It provides O(1) average time complexity for insert, delete, and search operations.

    unordered_map<string, int> hashMap; // Creating an unordered_map

    // Inserting key-value pairs
    hashMap["apple"] = 5;
    hashMap["banana"] = 3;
    hashMap["orange"] = 8;

    // Displaying the elements
    cout << "HashMap contents:\n";
    for (const auto &pair : hashMap) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // Searching for an element
    string key = "banana";
    if (hashMap.find(key) != hashMap.end()) {//hashMap.end() means the end of the map
        cout << key << " is present with value: " << hashMap[key] << endl;
    } else {
        cout << key << " is not found in the map.\n";
    }

    // Deleting an element
    hashMap.erase("apple");

    // Checking if 'apple' is still in the map
    if (hashMap.find("apple") == hashMap.end()) {
        cout << "apple has been removed from the map.\n";
    }

    return 0;
}
