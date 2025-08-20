// 1. Problem Introduction
// -----------------------
//
// Goal: Determine if a **target integer** exists in a 2D matrix.
// The matrix has the following properties:
// - Every row is sorted in ascending order (left to right)
// - Every column is sorted in ascending order (top to bottom)
// - The entire matrix is NOT sorted if flattened
//
// Examples:
// matrix = {
//   {1, 4, 7, 11, 15},
//   {2, 5, 8, 12, 19},
//   {3, 6, 9, 16, 22},
//   {10, 13, 14, 17, 24},
//   {18, 21, 23, 26, 30}
// }
// target = 5 → true
// target = 20 → false
//
// Constraints:
// - 1 ≤ N, M ≤ 10^3
// - -10^6 ≤ matrix[i][j], target ≤ 10^6
//
// Equivalent Problems:
// - Search in row-wise and column-wise sorted 2D matrix
// - Staircase search problem


// 2. Brute Force (Linear Search)
// ------------------------------
//
// Idea:
// - Traverse every element in the matrix and compare with target
//
// Steps:
// - Iterate over each row i and column j
// - If matrix[i][j] == target, return true
// - If loop ends, return false
//
// Time Complexity: O(N*M)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
    int N = matrix.size();
    int M = matrix[0].size();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}


// 3. Optimized (Row-wise Binary Search)
// -------------------------------------
//
// Key Insight:
// - Each row is sorted → apply binary search on rows where target may exist
//
// Steps:
// - For each row i:
//     - Pre-check: if target >= first element && target <= last element
//     - Perform binary search on row i
//     - If found, return true
// - Return false if not found in any row
//
// Time Complexity: O(N * log M)
// Space Complexity: O(1)

bool searchMatrixRowBinarySearch(vector<vector<int>>& matrix, int target) {
    int N = matrix.size();
    int M = matrix[0].size();

    for(int i = 0; i < N; i++) {
        if(target >= matrix[i][0] && target <= matrix[i][M-1]) {
            int low = 0, high = M - 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
    }
    return false;
}


// 4. Most Optimized (Staircase Search / Elimination Tactic)
// --------------------------------------------------------
//
// Key Insight:
// - Start from top-right (row = 0, col = M-1) or bottom-left
// - Compare current element with target
//     - If equal → found
//     - If element < target → move down (eliminate current row)
//     - If element > target → move left (eliminate current column)
// - Eliminates one row or column at each step
//
// Time Complexity: O(N + M)
// Space Complexity: O(1)

bool searchMatrixStaircase(vector<vector<int>>& matrix, int target) {
    int N = matrix.size();
    int M = matrix[0].size();
    int row = 0, col = M - 1;

    while(row < N && col >= 0) {
        int element = matrix[row][col];
        if(element == target) return true;
        else if(element < target) row++;   // move down
        else col--;                        // move left
    }

    return false;
}


// 5. Example Usage
// ----------------
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5, target2 = 20;

    cout << "Brute Force: " << searchMatrixBrute(matrix, target1) << endl;           // 1 (true)
    cout << "Row Binary Search: " << searchMatrixRowBinarySearch(matrix, target1) << endl; // 1 (true)
    cout << "Staircase Search: " << searchMatrixStaircase(matrix, target1) << endl;       // 1 (true)

    cout << "Brute Force: " << searchMatrixBrute(matrix, target2) << endl;           // 0 (false)
    cout << "Row Binary Search: " << searchMatrixRowBinarySearch(matrix, target2) << endl; // 0 (false)
    cout << "Staircase Search: " << searchMatrixStaircase(matrix, target2) << endl;       // 0 (false)

    return 0;
}
