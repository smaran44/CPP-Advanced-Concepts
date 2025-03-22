#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Vectors store elements in a contiguous memory
    vector<int> vec = {10, 20, 30, 40, 50};

    // Using an iterator to traverse the vector
    vector<int>::iterator it;
    cout << "Vector elements using iterator: ";
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";  // Dereferencing the iterator
    }
    cout << endl;
    //an iterator in C++ stores an address (a memory location), but it behaves differently from a regular pointer.

    return 0;
}
