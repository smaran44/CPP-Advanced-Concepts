#include <iostream>
#include <vector>

using namespace std;

/*
 * Difference between push_back() and emplace_back()
 * -------------------------------------------------
 * - push_back(value): Creates a temporary object and then copies/moves it into the vector.
 * - emplace_back(args...): Constructs the object directly in the vector (avoids unnecessary copies).
 *
 * Why use emplace_back()?
 * - It is more efficient for complex objects because it avoids extra copies.
 * - Directly constructs the object inside the container.
 */

class Demo {
public:
    int x;
    Demo(int a) {
        x = a;
        cout << "Constructor called for " << x << endl;
    }
};

int main() {
    vector<Demo> v;

    cout << "Using push_back():" << endl;
    v.push_back(Demo(10)); // Temporary object created, then copied

    cout << "\nUsing emplace_back():" << endl;
    v.emplace_back(20); // Directly constructs object in place

    return 0;
}
