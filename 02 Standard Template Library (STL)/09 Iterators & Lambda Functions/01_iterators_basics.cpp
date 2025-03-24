#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Vectors store elements in a contiguous memory
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << *(vec.begin()) << endl;
    cout << *(vec.end()) << endl;
    // vec.begin() returns an iterator pointing to the first element of the vector.
    // vec.end() returns an iterator pointing to one past the last element of the vector. which give a garbage value

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
