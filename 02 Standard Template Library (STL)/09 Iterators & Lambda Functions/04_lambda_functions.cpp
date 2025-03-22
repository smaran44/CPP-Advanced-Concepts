#include <iostream>
#include <vector>
#include <algorithm> // For `for_each`

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // Lambda function to print elements
    cout << "Using Lambda Function: ";
    for_each(vec.begin(), vec.end(), [](int num) { 
        cout << num << " ";
    });
    cout << endl;
    //The lambda function [](int num) { cout << num << " "; } takes an element (num) and prints it.

    // Lambda to modify elements (multiply each by 2)
    for_each(vec.begin(), vec.end(), [](int &num) {
        num *= 2;
    });

    cout << "Vector after modification: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
