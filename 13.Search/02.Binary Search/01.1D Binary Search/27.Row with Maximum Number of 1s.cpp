// 1. Problem Introduction
// -----------------------
//
// Goal: Find the **row index** with the **maximum number of 1s** in a binary matrix.
// Each row of the matrix is **sorted** (0s followed by 1s).
//
// Examples:
// matrix = {
//   {0, 0, 1, 1},
//   {0, 1, 1, 1},
//   {0, 0, 0, 1}
// }
// Row with maximum 1s = 1 (second row, 3 ones)
//
// Constraints:
// - 1 ≤ N, M ≤ 10^3
// - matrix[i][j] ∈ {0, 1}
// - Rows are sorted in non-decreasing order
//
// Equivalent Problems:
// - First occurrence of 1 in sorted array
// - Maximum 1s in a row of a binary matrix


// 2. Brute Force (Count Ones Row by Row)
// --------------------------------------
//
// Idea:
// - Iterate through each row and count the number of 1s
// - Keep track of the row with maximum ones
//
// Steps:
// - Initialize max_count = -1 and index = -1
// - For each row i:
//     - Count ones (sum of row elements or iterate through each column)
//     - If count > max_count, update max_count and index
// - Return index
//
// Time Complexity: O(N*M)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int rowWithMaxOnesBrute(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    int max_count = -1, index = -1;

    for(int i = 0; i < N; i++) {
        int count = 0;
        for(int j = 0; j < M; j++) {
            if(matrix[i][j] == 1) count++;
        }
        if(count > max_count) {
            max_count = count;
            index = i;
        }
    }
    return index;
}


// 3. Optimized (Binary Search in Each Row)
// ----------------------------------------
//
// Key Insight:
// - Each row is sorted → 0s followed by 1s
// - Use binary search to find first occurrence of 1
// - Number of ones = M - first_one_index
//
// Steps:
// - Initialize max_count = 0, index = -1
// - For each row i:
//     - Perform binary search to find first 1
//     - Calculate count = M - first_one_index
//     - If count > max_count, update max_count and index
// - Return index
//
// Time Complexity: O(N * log M)
// Space Complexity: O(1)

int rowWithMaxOnesBinarySearch(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    int max_count = 0, index = -1;

    for(int i = 0; i < N; i++) {
        int low = 0, high = M - 1;
        int first_one_index = M;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(matrix[i][mid] == 1) {
                first_one_index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int count = M - first_one_index;
        if(count > max_count) {
            max_count = count;
            index = i;
        }
    }
    return index;
}


// 4. Example Usage
// ----------------
int main() {
    vector<vector<int>> matrix = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };

    cout << "Brute Force Row: " << rowWithMaxOnesBrute(matrix) << endl;         // 1
    cout << "Binary Search Row: " << rowWithMaxOnesBinarySearch(matrix) << endl; // 1

    return 0;
}
