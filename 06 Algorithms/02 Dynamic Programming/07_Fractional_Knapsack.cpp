#include <iostream>   // For input-output operations
#include <vector>     // For using the vector data structure
#include <algorithm>  // For sorting and using max() function
using namespace std;  // This allows us to use standard library names without prefixing them with 'std::'

// Struct to represent an item with its value, weight, and value-to-weight ratio
struct Item {
    int value;  // Value of the item
    int weight; // Weight of the item
    double ratio; // Value-to-weight ratio (value/weight)
};

// Comparator function to sort items based on their value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // Compare ratios, so we get higher ratios first
}

// Function to solve the Fractional Knapsack problem using Greedy approach
double fractionalKnapsack(int W, vector<Item>& items, int n) {
    // Sort items by their value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;  // To store the maximum value that can be carried
    for (int i = 0; i < n; i++) {
        // If the current item can fit in the remaining knapsack capacity
        if (items[i].weight <= W) {
            W -= items[i].weight; // Reduce the capacity of the knapsack by the item's weight
            maxValue += items[i].value; // Add the full value of the item to the maximum value
        } else {
            // If the current item cannot fit entirely, take the fraction of it
            maxValue += items[i].value * ((double)W / items[i].weight);  // Add the fraction of the item’s value
            break;  // The knapsack is now full, no need to check further items
        }
    }

    return maxValue;  // Return the total maximum value that can be obtained
}

int main() {
    int n, W;
    cout << "Enter number of items: ";  // Prompt to enter the number of items
    cin >> n;  // Read the number of items

    vector<Item> items(n);  // Create a vector to store items
    cout << "Enter values and weights of the items: ";  // Prompt for item values and weights
    for (int i = 0; i < n; i++) {  // Loop to enter value and weight for each item
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;  // Calculate value-to-weight ratio
    }

    cout << "Enter capacity of the knapsack: ";  // Prompt for the capacity of the knapsack
    cin >> W;  // Read the knapsack capacity

    // Output the maximum value that can be obtained in the Fractional Knapsack
    cout << "Maximum value in Fractional Knapsack = " << fractionalKnapsack(W, items, n) << endl;
    return 0;  // Return 0 to indicate successful execution
}
