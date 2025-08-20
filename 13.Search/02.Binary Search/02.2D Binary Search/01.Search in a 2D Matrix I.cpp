// 1. Problem Introduction
// -----------------------
//
// Goal: Determine if a **target integer** exists in a 2D matrix.
// The matrix has the following properties:
// - Every row is sorted in ascending order
// - Flattening the matrix into a 1D array gives a sorted array
//
// Examples:
// matrix = {
//   {1, 3, 5, 7},
//   {10, 11, 16, 20},
//   {23, 30, 34, 50}
// }
// target = 3 → true
// target = 13 → false
//
// Constraints:
// - 1 ≤ N, M ≤ 10^3
// - -10^6 ≤ matrix[i][j], target ≤ 10^6
//
// Equivalent Problems:
// - Search in sorted 2D matrix
// - Flattened sorted array binary search


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


// 4. Most Optimized (Conceptual Flattening Binary Search)
// --------------------------------------------------------
//
// Key Insight:
// - Treat the matrix as a **flattened sorted 1D array** of size N*M
// - Map 1D index to 2D coordinates: row = index / M, col = index % M
// - Perform standard binary search in this conceptual array
//
// Time Complexity: O(log(N*M))
// Space Complexity: O(1)

bool searchMatrixBinarySearch(vector<vector<int>>& matrix, int target) {
    int N = matrix.size();
    int M = matrix[0].size();
    int low = 0, high = N * M - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int row = mid / M;
        int col = mid % M;
        int element = matrix[row][col];

        if(element == target) return true;
        else if(element < target) low = mid + 1;
        else high = mid - 1;
    }

    return false;
}


// 5. Example Usage
// ----------------
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target1 = 3, target2 = 13;

    cout << "Brute Force: " << searchMatrixBrute(matrix, target1) << endl;           // 1 (true)
    cout << "Row Binary Search: " << searchMatrixRowBinarySearch(matrix, target1) << endl; // 1 (true)
    cout << "Flattened Binary Search: " << searchMatrixBinarySearch(matrix, target1) << endl; // 1 (true)

    cout << "Brute Force: " << searchMatrixBrute(matrix, target2) << endl;           // 0 (false)
    cout << "Row Binary Search: " << searchMatrixRowBinarySearch(matrix, target2) << endl; // 0 (false)
    cout << "Flattened Binary Search: " << searchMatrixBinarySearch(matrix, target2) << endl; // 0 (false)

    return 0;
}
