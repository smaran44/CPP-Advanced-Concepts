#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Definition: An unordered_map uses hashing for faster access.

    unordered_map<string, int> wordCount;

    // Inserting values
    wordCount["apple"] = 5;
    wordCount["banana"] = 3;
    wordCount["cherry"] = 7;

    // Accessing values
    cout << "Apple count: " << wordCount["apple"] << endl;
    cout << "Banana count: " << wordCount["banana"] << endl;

    return 0;
}
