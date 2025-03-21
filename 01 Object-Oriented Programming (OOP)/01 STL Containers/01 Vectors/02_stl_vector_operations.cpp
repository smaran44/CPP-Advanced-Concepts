#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50};

    // Removing the last element
    numbers.pop_back();
    printVector(numbers);

    // Inserting at a specific position (Insert 25 at index 1)
    numbers.insert(numbers.begin() + 1, 25);
    printVector(numbers);

    // Erasing an element (Remove element at index 2)
    numbers.erase(numbers.begin() + 2);
    printVector(numbers);

    // Clearing all elements from the vector
    numbers.clear();
    printVector(numbers);

    // Checking if vector is empty
    if (numbers.empty()) {
        cout << "Vector is empty after clearing elements." << endl;
    }

    return 0;
}
