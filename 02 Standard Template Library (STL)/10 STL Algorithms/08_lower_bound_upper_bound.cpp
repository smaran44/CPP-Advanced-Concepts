#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * lower_bound() and upper_bound()
 * --------------------------------
 * - lower_bound(start, end, value): Returns an iterator to the **first element >= value**.
 * - upper_bound(start, end, value): Returns an iterator to the **first element > value**.
 *
 * Important Notes:
 * - Works only on **sorted arrays/vectors**.
 * - Uses **binary search**, so runs in **O(log N) time**.
 */

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    int x = 25;
    int y = 44;
    int z = 40;
    
    auto lb = lower_bound(v.begin(), v.end(), x);
    auto ub = upper_bound(v.begin(), v.end(), x);

    cout << "Vector: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    cout << "Lower bound of " << x << " is at index: " << (lb - v.begin()) << endl;
    cout << "Upper bound of " << x << " is at index: " << (ub - v.begin()) << endl;

    cout << "Lower bound of " << y << " is at index: " << (lower_bound(v.begin(), v.end(), y) - v.begin()) << endl;
    cout << "Upper bound of " << y << " is at index: " << (upper_bound(v.begin(), v.end(), y) - v.begin()) << endl;

    cout << "Lower bound of " << z << " is at index: " << (lower_bound(v.begin(), v.end(), z) - v.begin()) << endl;
    cout << "Upper bound of " << z << " is at index: " << (upper_bound(v.begin(), v.end(), z) - v.begin()) << endl;
    
    return 0;
}
