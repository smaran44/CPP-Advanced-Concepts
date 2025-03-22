#include <iostream>
#include <vector>
#include <numeric> // For accumulate()

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    int sum = accumulate(vec.begin(), vec.end(), 0);

    cout << "Sum of elements: " << sum << endl;

    return 0;
}
