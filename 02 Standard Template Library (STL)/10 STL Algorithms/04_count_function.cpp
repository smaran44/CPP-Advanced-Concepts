#include <iostream>
#include <vector>
#include <algorithm> // For count()

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 2, 4, 2, 5};

    int count_2 = count(vec.begin(), vec.end(), 2);

    cout << "Number 2 appears " << count_2 << " times in the vector." << endl;

    return 0;
}
