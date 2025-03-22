#include <iostream>

using namespace std;

/*
 * Fenwick Tree (BIT) Operations - Update & Query
 * ----------------------------------------------
 * - `update(index, value)`: Adds `value` to `index` and propagates changes.
 * - `query(index)`: Returns the prefix sum up to `index`.
 *
 * BIT follows **LSB (Least Significant Bit) method**:
 *   - Update moves forward using `index += (index & -index)`
 *   - Query moves backward using `index -= (index & -index)`
 */

// Function to update the Binary Indexed Tree (BIT)
// BIT[]  -> The Binary Indexed Tree array
// n      -> Size of the BIT array
// index  -> Position to update (1-based index)
// value  -> Value to be added at 'index'
void updateBIT(int BIT[], int n, int index, int value) {
    // Traverse all the indices affected by this update
    while (index <= n) {
        BIT[index] += value;  // Update the current index in BIT

        // Move to the next index that needs to be updated
        // Using Least Significant Bit (LSB) to find the next responsible index
        index += (index & -index);
    }
}


// Function to compute prefix sum from index 1 to 'index' in BIT
// BIT[]  -> The Binary Indexed Tree array
// index  -> Position up to which the sum is required (1-based index)
int queryBIT(int BIT[], int index) {
    int sum = 0;  // Initialize sum to store the result

    // Traverse all contributing indices to compute the sum
    while (index > 0) {
        sum += BIT[index];  // Add the current index's value to sum

        // Move to the parent index (removing the last set bit)
        index -= (index & -index);
    }
    
    return sum;  // Return the computed prefix sum
}

int main() {
    cout << "Fenwick Trees use LSB (Least Significant Bit) for fast updates & queries!" << endl;
    return 0;
}
