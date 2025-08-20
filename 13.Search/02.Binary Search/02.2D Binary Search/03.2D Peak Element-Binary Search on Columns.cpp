// 1. Problem Introduction
// -----------------------
//
// Goal: Find **any peak element** in a 2D matrix and return its coordinates.
// A peak element is greater than its top, bottom, left, and right neighbors.
//
// Matrix Properties:
// - N x M matrix
// - Outer boundaries are considered -1
// - No two adjacent cells are equal
//
// Example:
// matrix = {
//   {10, 20, 15},
//   {21, 30, 14},
//   {7, 16, 32}
// }
// Possible peak elements: 20, 30, 32 → return coordinates of any one
//
// Constraints:
// - 1 ≤ N, M ≤ 10^3
// - -10^6 ≤ matrix[i][j] ≤ 10^6
//
// Equivalent Problems:
// - 1D Peak Element (generalized to 2D)
// - Binary search on columns

#include <bits/stdc++.h>
using namespace std;

// Helper: Find the row index of maximum element in a given column
int findMaxInColumn(vector<vector<int>>& matrix, int col) {
    int maxRow = 0;
    int N = matrix.size();
    for (int i = 1; i < N; i++) {
        if (matrix[i][col] > matrix[maxRow][col]) {
            maxRow = i;
        }
    }
    return maxRow;
}

// 2. Brute Force (Linear Search)
// ------------------------------
//
// Idea:
// - Check each element to see if it is a peak (compare all 4 neighbors)
//
// Time Complexity: O(N*M)
// Space Complexity: O(1)
pair<int,int> findPeakBrute(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int left = (j-1 >= 0) ? matrix[i][j-1] : -1;
            int right = (j+1 < M) ? matrix[i][j+1] : -1;
            int top = (i-1 >= 0) ? matrix[i-1][j] : -1;
            int bottom = (i+1 < N) ? matrix[i+1][j] : -1;

            if(matrix[i][j] > left && matrix[i][j] > right &&
               matrix[i][j] > top && matrix[i][j] > bottom){
                   return {i, j};
            }
        }
    }
    return {-1, -1};
}

// 3. Most Optimized (Column-wise Binary Search)
// ---------------------------------------------
//
// Idea:
// - Apply binary search on columns
// - In mid column, find row with maximum element
// - Check its left and right neighbors
//     - If greater than neighbors → peak
//     - If left neighbor is greater → search left half
//     - If right neighbor is greater → search right half
//
// Time Complexity: O(N * log M)
// Space Complexity: O(1)
pair<int,int> findPeakBinarySearch(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    int low = 0, high = M-1;

    while(low <= high){
        int midCol = low + (high - low)/2;
        int maxRow = findMaxInColumn(matrix, midCol);

        int leftVal = (midCol-1 >= 0) ? matrix[maxRow][midCol-1] : -1;
        int rightVal = (midCol+1 < M) ? matrix[maxRow][midCol+1] : -1;
        int curr = matrix[maxRow][midCol];

        if(curr > leftVal && curr > rightVal){
            return {maxRow, midCol}; // Peak found
        } else if(curr < leftVal){
            high = midCol - 1; // Move left
        } else {
            low = midCol + 1;  // Move right
        }
    }
    return {-1,-1};
}

// 4. Example Usage
// ----------------
int main(){
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    pair<int,int> peak1 = findPeakBrute(matrix);
    cout << "Brute Force Peak at: (" << peak1.first << "," << peak1.second << ")\n";

    pair<int,int> peak2 = findPeakBinarySearch(matrix);
    cout << "Binary Search Peak at: (" << peak2.first << "," << peak2.second << ")\n";

    return 0;
}
