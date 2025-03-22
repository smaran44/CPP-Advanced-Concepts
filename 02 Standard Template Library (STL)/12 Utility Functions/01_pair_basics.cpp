#include <iostream>
#include <utility> // For using the pair class

using namespace std;

int main() {
    // Creating a pair using direct initialization
    pair<int, string> p1 = {1, "Alice"};

    // Accessing and printing elements of the pair
    cout << "First: " << p1.first << ", Second: " << p1.second << endl;

    // Another way to create a pair using make_pair()
    pair<int, string> p2;
    p2 = make_pair(2, "Bob");  // Assigning values using make_pair()

    // Printing elements of the second pair
    cout << "First: " << p2.first << ", Second: " << p2.second << endl;

    // Swapping values of two pairs
    swap(p1, p2);  // p1 and p2 are swapped

    // Printing values after swapping
    cout << "After Swap -> First: " << p1.first << ", Second: " << p1.second << endl;

    return 0;
}
