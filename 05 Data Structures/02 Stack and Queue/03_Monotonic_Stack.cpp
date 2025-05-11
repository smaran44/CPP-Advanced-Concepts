#include <iostream>   // For input/output operations
#include <stack>      // For using the stack data structure
#include <vector>     // For using the vector container

using namespace std;

// Function to find the Next Greater Element for each element in the array
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();                   // Size of the input array
    vector<int> result(n, -1);             // Result vector initialized with -1
    stack<int> st;                         // Stack to store indices

    // Iterate through the array from left to right
    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the current number is greater than
        // the number at the index stored at the top of the stack
        while (!st.empty() && nums[i] > nums[st.top()]) {
            // Set the current number as the next greater element for the top index
            result[st.top()] = nums[i];
            st.pop(); // Remove the index since its NGE has been found
        }
        // Push the current index onto the stack
        st.push(i);
    }

    // Elements left in the stack do not have a next greater element
    // They remain -1 as initialized
    return result;
}

// Function to print elements of a vector
void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

// Main function - entry point of the program
int main() {
    vector<int> nums = {4, 5, 2, 25, 7, 8}; // Input array
    cout << "Original Array:\n";
    printVector(nums);

    // Call the function to compute next greater elements
    vector<int> nge = nextGreaterElement(nums);
    cout << "Next Greater Elements:\n";
    printVector(nge);

    return 0;
}
