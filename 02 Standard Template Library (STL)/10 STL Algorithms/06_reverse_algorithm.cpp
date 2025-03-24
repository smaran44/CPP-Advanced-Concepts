#include <iostream>
#include <vector>
#include <algorithm> // For reverse()

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    reverse(vec.begin(), vec.end());

    cout << "Reversed vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // reverse of some part of the vector
    vector<int> vec2 = {10, 20, 30, 40, 50};
    reverse(vec2.begin() + 1, vec2.end() - 1);
    cout << "Reversed part of vector: ";
    for (int num : vec2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
