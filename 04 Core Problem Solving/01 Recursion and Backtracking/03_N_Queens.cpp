#include <iostream>
#include <vector>
using namespace std;

/*
    Program: N-Queens Problem using Backtracking
    --------------------------------------------
    What we are doing:
    - We are placing N queens on an N x N chessboard so that no two queens attack each other.
    - A queen can attack vertically, and diagonally (both left and right).
    - We use recursion to try placing a queen row by row, and backtrack if a placement leads to a conflict.

    Concept used: Backtracking – try a solution, and if it leads to failure, backtrack and try another.
*/

// Function to print the current board configuration
void printBoard(vector<string> &board) {
    for (string row : board) {
        cout << row << endl;
    }
    cout << "------------" << endl;  // separator for different solutions
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, vector<string> &board, int n) {
    // Check vertically upwards
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;  // Safe to place the queen
}

// Recursive function to solve the N-Queens problem
void solve(int row, vector<string> &board, int n) {
    // Base case: If we've placed queens in all rows, print solution
    if (row == n) {
        printBoard(board);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Place queen only if it's safe
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';       // Place the queen
            solve(row + 1, board, n);    // Move to the next row
            board[row][col] = '.';       // Backtrack: remove the queen
        }
    }
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    // Create an empty N x N board filled with '.'
    vector<string> board(n, string(n, '.'));

    // Start solving from the 0th row
    solve(0, board, n);

    return 0;
}
