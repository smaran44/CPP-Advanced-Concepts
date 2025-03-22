#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Using a reverse iterator to print elements in reverse order
    cout << "Vector elements in reverse order: ";
    for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
