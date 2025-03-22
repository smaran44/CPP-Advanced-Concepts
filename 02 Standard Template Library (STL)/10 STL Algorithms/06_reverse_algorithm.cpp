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

    return 0;
}
