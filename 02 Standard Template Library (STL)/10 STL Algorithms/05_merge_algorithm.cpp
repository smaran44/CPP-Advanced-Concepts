#include <iostream>
#include <vector>
#include <algorithm> // For merge()

using namespace std;

int main() {
    vector<int> vec1 = {1, 3, 5};
    vector<int> vec2 = {2, 4, 6};
    vector<int> merged(6);

    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin());

    cout << "Merged sorted vector: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
