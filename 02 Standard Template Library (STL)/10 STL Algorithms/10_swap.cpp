#include <iostream>
#include <algorithm> // For std::swap()

using namespace std;

/*
 * Swap Two Numbers using STL
 * --------------------------
 * - Uses std::swap() from <algorithm>.
 * - Simple, efficient, and avoids manual swapping logic.
 */

int main() {
    int a = 10, b = 20;

    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    // Using STL swap function
    swap(a, b);

    cout << "After swapping (Using std::swap): a = " << a << ", b = " << b << endl;

    return 0;
}
