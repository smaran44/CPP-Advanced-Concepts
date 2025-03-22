#include <iostream>
#include <vector>
#include <algorithm> // For binary_search()

using namespace std;

int main() {
    vector<int> vec = {1, 3, 5, 7, 9, 11};

    // Binary search requires a sorted array
    if (binary_search(vec.begin(), vec.end(), 5)) {
        cout << "Element 5 is found in the vector." << endl;
    } else {
        cout << "Element 5 is not found." << endl;
    }

    return 0;
}
