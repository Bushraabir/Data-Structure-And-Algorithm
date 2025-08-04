/*
 * Solve the N-Queens problem: place N queens on an N×N board so that no two
 * attack each other (no same row, column, or diagonal).
 *
 * Example:
 * N = 4
 * Solutions (as board-strings):
 *   [".Q..",  // Solution 1
 *    "...Q",
 *    "Q...",
 *    "..Q."]
 *
 *   ["..Q.",  // Solution 2
 *    "Q...",
 *    "...Q",
 *    ".Q.."]
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ---------------- Brute Force Approach ----------------
/*
 * Intuition:
 *   • We try to place one queen per column, scanning each row in that column.
 *   • Before placing at (r,c), we run an O(N) isSafe check:
 *       – no other queen in the same row to the left
 *       – no other queen on upper-left diagonal
 *       – no other queen on lower-left diagonal
 *   • If safe, place 'Q', recurse for next column, then remove 'Q' (backtrack).
 *   • Base case: column == N means all queens placed—record the board.
 */
bool isSafe_Brute(const vector<string>& board, int row, int col, int N) {
    // Check left in same row
    for (int c = 0; c < col; ++c)
        if (board[row][c] == 'Q') return false;
    // Check upper-left diagonal
    for (int r = row-1, c = col-1; r >= 0 && c >= 0; --r, --c)
        if (board[r][c] == 'Q') return false;
    // Check lower-left diagonal
    for (int r = row+1, c = col-1; r < N && c >= 0; ++r, --c)
        if (board[r][c] == 'Q') return false;
    return true;
}

void solveNQueens_Brute(int col,
                        vector<string>& board,
                        vector<vector<string>>& ans,
                        int N) {
    if (col == N) {
        ans.push_back(board);
        return;
    }
    for (int r = 0; r < N; ++r) {
        if (isSafe_Brute(board, r, col, N)) {
            board[r][col] = 'Q';
            solveNQueens_Brute(col + 1, board, ans, N);
            board[r][col] = '.';  // backtrack
        }
    }
}

vector<vector<string>> solveNQueens_Brute(int N) {
    vector<vector<string>> ans;
    vector<string> board(N, string(N, '.'));
    solveNQueens_Brute(0, board, ans, N);
    return ans;
}

// ---------------- Optimized Hashing Approach ----------------
/*
 * Intuition:
 *   • Replace the O(N) isSafe check with O(1) lookups using three boolean arrays:
 *       – rowUsed[r]      tracks if row r has a queen
 *       – diag1Used[r+c]  tracks \ diagonals (sum index)
 *       – diag2Used[r-c+N-1] tracks / diagonals (offset difference)
 *   • When placing at (r,c), mark all three; recurse; then unmark (backtrack).
 */
void solveNQueens_Opt(int col,
                      vector<string>& board,
                      vector<vector<string>>& ans,
                      vector<bool>& rowUsed,
                      vector<bool>& diag1Used,
                      vector<bool>& diag2Used,
                      int N) {
    if (col == N) {
        ans.push_back(board);
        return;
    }
    for (int r = 0; r < N; ++r) {
        int d1 = r + col;
        int d2 = r - col + (N - 1);
        // Check in O(1) if any conflict
        if (rowUsed[r] || diag1Used[d1] || diag2Used[d2]) 
            continue;
        // Place queen
        board[r][col] = 'Q';
        rowUsed[r] = diag1Used[d1] = diag2Used[d2] = true;

        solveNQueens_Opt(col + 1, board, ans, rowUsed, diag1Used, diag2Used, N);

        // Backtrack: remove queen and unmark
        board[r][col] = '.';
        rowUsed[r] = diag1Used[d1] = diag2Used[d2] = false;
    }
}

vector<vector<string>> solveNQueens_Optimized(int N) {
    vector<vector<string>> ans;
    vector<string> board(N, string(N, '.'));
    vector<bool> rowUsed(N, false), diag1Used(2*N-1, false), diag2Used(2*N-1, false);
    solveNQueens_Opt(0, board, ans, rowUsed, diag1Used, diag2Used, N);
    return ans;
}

// -------------------------- Main --------------------------
int main() {
    int N = 4;

    // Brute force solutions
    auto brute = solveNQueens_Brute(N);
    cout << "Brute Force N-Queens Solutions (" << brute.size() << "):\n";
    for (auto& sol : brute) {
        for (auto& row : sol) cout << row << "\n";
        cout << "\n";
    }

    // Optimized hashing solutions
    auto opt = solveNQueens_Optimized(N);
    cout << "Optimized N-Queens Solutions (" << opt.size() << "):\n";
    for (auto& sol : opt) {
        for (auto& row : sol) cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
