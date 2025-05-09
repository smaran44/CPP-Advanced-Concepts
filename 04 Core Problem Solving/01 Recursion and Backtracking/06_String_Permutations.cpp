#include <iostream>
#include <vector>
using namespace std;

/*
    Program: Generate all permutations of a string using backtracking
    ------------------------------------------------------------------
    What we are doing:
    - We generate all possible orderings (permutations) of characters in a string.
    - We use recursion and backtracking to explore all character positions.
    - At each index, we swap the current character with all possible characters ahead
      and recursively generate permutations for the rest of the string.

    Concept used: Recursion + Backtracking + Swapping characters in-place.
*/

// Recursive function to generate permutations
void permute(string &s, int index) {
    // Base case: If we've fixed all positions, print the permutation
    if (index == s.size()) {
        cout << s << endl;
        return;
    }

    // Try placing every character at the current index
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);       // Fix one character at current index
        permute(s, index + 1);      // Recurse to fix the next character
        swap(s[index], s[i]);       // Backtrack to original state
    }
}

int main() {
    string s = "ABC";

    cout << "Permutations of " << s << ":\n";
    permute(s, 0);  // Start permutation from index 0

    return 0;
}
