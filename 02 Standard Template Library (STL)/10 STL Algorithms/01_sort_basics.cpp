#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

int main() {
    vector<int> vec = {5, 2, 9, 1, 5, 6};

    // Sorting in ascending order
    sort(vec.begin(), vec.end());

    cout << "Sorted in ascending order: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Sorting in descending order using a lambda function
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b; // Sorting in descending order
    });

    cout << "Sorted in descending order: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
