#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order.
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Already sorted
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    bubbleSort(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}
