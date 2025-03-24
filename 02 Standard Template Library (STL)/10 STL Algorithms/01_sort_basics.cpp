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

    //for arrays
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Sorting the array in ascending order
    sort(arr, arr + n);
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting the array in descending order
    sort(arr, arr + n, [](int a, int b) {
        return a > b; // Sorting in descending order
    });
    cout << "Sorted array in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // using comparitor like greater<int>
    int arr2[] = {5, 2, 9, 1, 5, 6};
    n = sizeof(arr2) / sizeof(arr2[0]);
    sort(arr2, arr2 + n, greater<int>());
    cout << "Sorted array in descending order using greater<int>: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // in ascending order using less<int>
    int arr3[] = {5, 2, 9, 1, 5, 6};
    n = sizeof(arr3) / sizeof(arr3[0]);
    sort(arr3, arr3 + n, less<int>());
    cout << "Sorted array in ascending order using less<int>: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    // for pairs
    vector<pair<int, string>> vec2 = {{5, "apple"}, {2, "banana"}, {9, "cherry"}, {5, "banana"}};

    // Sorting based on the first element of the pair
    sort(vec2.begin(), vec2.end());
    cout << "Sorted pairs based on first element: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sorting based on the first element of the pair in descending order
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first; // Sorting based on the first element (int)
    });
    cout << "Sorted pairs based on first element in descending order: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sorting based on the second element of the pair
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second < b.second; // Sorting based on the second element (string)
    });
    cout << "Sorted pairs based on second element: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sorting based on the second element of the pair in descending order
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second > b.second; // Sorting based on the second element (string)
    });
    cout << "Sorted pairs based on second element in descending order: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // sorting based on the first element of the pair in ascending order
    // if first element is same then sort based on the second element of the pair in ascending order
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second; // Sorting based on the second element (string)
        }
        return a.first < b.first; // Sorting based on the first element (int)
    });
    cout << "Sorted pairs based on first element in ascending order and second element in ascending order: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // sorting based on the first element of the pair in descending order
    // if first element is same then sort based on the second element of the pair in descending order
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // Sorting based on the second element (string)
        }
        return a.first > b.first; // Sorting based on the first element (int)
    });
    cout << "Sorted pairs based on first element in descending order and second element in descending order: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sorting based on the second element of the pair in ascending order
    // if second element is same then sort based on the first element of the pair in ascending order
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.second == b.second) {
            return a.first < b.first; // Sorting based on the first element (int)
        }
        return a.second < b.second; // Sorting based on the second element (string)
    });
    cout << "Sorted pairs based on second element in ascending order and first element in ascending order: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sorting based on the second element of the pair in descending order
    // if second element is same then sort based on the first element of the pair in descending order
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.second == b.second) {
            return a.first > b.first; // Sorting based on the first element (int)
        }
        return a.second > b.second; // Sorting based on the second element (string)
    });
    cout << "Sorted pairs based on second element in descending order and first element in descending order: ";
    for (const auto& p : vec2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // sorting some part of the vector
    vector<int> vec3 = {5, 2, 9, 1, 5, 6};
    sort(vec3.begin() + 1, vec3.end() - 1); // Sort from index 1 to the second last element
    cout << "Partially sorted vector: ";
    for (int num : vec3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
