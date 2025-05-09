#include <iostream>
#include <vector>
using namespace std;

#define N 9  // Size of the Sudoku board (9x9)

/*
    Program: Sudoku Solver using Backtracking
    -----------------------------------------
    What we are doing:
    - We solve a 9x9 Sudoku puzzle where empty cells are marked with '.'.
    - For each empty cell, we try placing digits from 1 to 9.
    - We place a digit only if it does not violate Sudoku rules:
        1. Each row must have digits 1 to 9 without repetition.
        2. Each column must have digits 1 to 9 without repetition.
        3. Each 3x3 subgrid must have digits 1 to 9 without repetition.
    - If a choice leads to a dead end, we backtrack and try another digit.

    Concept used: Recursion + Backtracking – try possibilities and backtrack if needed.
*/

// Utility to print the Sudoku board
void printBoard(vector<vector<char>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if it's valid to place digit 'ch' at board[row][col]
bool isValid(vector<vector<char>> &board, int row, int col, char ch) {
    for (int i = 0; i < N; i++) {
        // Check same row or same column
        if (board[row][i] == ch || board[i][col] == ch) return false;

        // Check 3x3 subgrid
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == ch) return false;
    }
    return true; // It's safe to place the digit
}

// Recursive function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == '.') { // If the cell is empty
                // Try placing digits from 1 to 9
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, row, col, ch)) {
                        board[row][col] = ch; // Place the digit

                        // Recur to fill the rest
                        if (solveSudoku(board)) return true;

                        board[row][col] = '.'; // Backtrack if needed
                    }
                }
                return false; // No valid digit can be placed here
            }
        }
    }
    return true; // Sudoku solved
}

int main() {
    // Initial Sudoku board ('.' means empty)
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // Solve and print the board
    if (solveSudoku(board)) {
        cout << "Sudoku solved successfully:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
