#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Using a const iterator (cannot modify elements)
    cout << "Vector elements using const iterator: ";
    for (vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        cout << *cit << " ";
        // *cit = 100; // ❌ ERROR: Cannot modify elements using const_iterator
    }
    cout << endl;

    return 0;
}
