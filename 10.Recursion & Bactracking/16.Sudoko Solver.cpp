/*
 * Solve the Sudoku puzzle: fill a 9×9 board so that each row, column,
 * and each 3×3 sub-box contains all digits from '1' to '9' exactly once.
 *
 * Example:
 * Input board ('.' denotes empty):
 *   {{'5','3','.','.','7','.','.','.','.'},
 *    {'6','.','.','1','9','5','.','.','.'},
 *    {'.','9','8','.','.','.','.','6','.'},
 *    {'8','.','.','.','6','.','.','.','3'},
 *    {'4','.','.','8','.','3','.','.','1'},
 *    {'7','.','.','.','2','.','.','.','6'},
 *    {'.','6','.','.','.','.','2','8','.'},
 *    {'.','.','.','4','1','9','.','.','5'},
 *    {'.','.','.','.','8','.','.','7','9'}}
 *
 * After solving, the board is filled with digits '1'–'9'.
 */

#include <iostream>
#include <vector>
using namespace std;

// Check if placing digit c at (row, col) is valid:
//   • Row rule
//   • Column rule
//   • 3×3 box rule

/*
 * Solve the Sudoku puzzle by filling a 9×9 board so that:
 *  1. Each row contains digits '1'–'9' exactly once.
 *  2. Each column contains digits '1'–'9' exactly once.
 *  3. Each of the nine 3×3 sub-boxes contains digits '1'–'9' exactly once.
 *
 * We use backtracking:
 *  - Find an empty cell (marked '.').
 *  - Try placing digits '1'–'9' one by one.
 *  - For each digit, check if it's valid in that position.
 *    • If valid, place it and recurse to solve the rest of the board.
 *    • If recursion succeeds, we're done.
 *    • Otherwise, remove the digit (backtrack) and try the next one.
 *  - If no digit fits, return false to backtrack further.
 *  - If no empty cell remains, the board is solved.
 */



// Check whether it's legal to place digit 'c' at board[row][col]
bool isValid(const vector<vector<char>>& board, int row, int col, char c) {
    // Check the row and column in one loop
    for (int i = 0; i < 9; ++i) {

        // Row check: same row, different column
        if (board[row][i] == c) return false;
        // Column check: same column, different row
        if (board[i][col] == c) return false;

        // 3×3 box check:
        // Compute top-left corner of the 3×3 box:
        //   boxStartRow = (row/3)*3, boxStartCol = (col/3)*3
        // Then iterate i from 0..8 to cover all 9 cells in that box

        int boxRow = (row / 3) * 3 + i / 3;
        int boxCol = (col / 3) * 3 + i % 3;
        if (board[boxRow][boxCol] == c) return false;
    }
    // No conflicts found
    return true;
}

// Recursive backtracking function to fill the board
bool solveSudoku_Helper(vector<vector<char>>& board) {
    // Scan all cells to find the first empty one
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                // Try each digit from '1' to '9'
                for (char d = '1'; d <= '9'; ++d) {
                    // If placing d here is valid
                    if (isValid(board, r, c, d)) {
                        board[r][c] = d;                 // Place digit
                        if (solveSudoku_Helper(board))   // Recurse
                            return true;                 // Puzzle solved!
                        board[r][c] = '.';               // Backtrack
                    }
                }
                // If no digit 1–9 fits here, need to backtrack
                return false;
            }
        }
    }
    // No empty cell found → board is completely filled and valid
    return true;
}

// Public API to solve the Sudoku in-place
void solveSudoku(vector<vector<char>>& board) {
    solveSudoku_Helper(board);
}

int main() {
    // Example starting board ('.' denotes empty)
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

    // Solve the puzzle
    solveSudoku(board);

    // Print the solved board
    cout << "Solved Sudoku:\n";
    for (auto& row : board) {
        for (char ch : row) {
            cout << ch << ' ';
        }
        cout << '\n';
    }
    return 0;
}