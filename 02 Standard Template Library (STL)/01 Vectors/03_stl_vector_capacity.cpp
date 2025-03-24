#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;

    cout << "Initial capacity: " << numbers.capacity() << endl;

    //SIZE : size is the number of elements in the vector.
    //CAPACITY : capacity is the total number of elements that the vector can hold without needing to reallocate memory.
    // The capacity is always greater than or equal to the size.

    // Adding elements and checking capacity
    for (int i = 1; i <= 10; i++) {
        numbers.push_back(i);
        cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << endl;
    }

    //Doubling Strategy: When elements are added, the vector follows an exponential growth pattern—usually doubling its previous capacity to minimize the number of memory reallocations.

    // Reserve capacity to avoid frequent reallocations
    numbers.reserve(20);
    cout << "Capacity after reserving space: " << numbers.capacity() << endl;

    return 0;
}
