#include <bits/stdc++.h>
using namespace std;

/*
Problem:
---------
Given an n x m binary matrix (only 0s and 1s),
count the total number of square submatrices that consist entirely of 1s.

Approach:
---------
We use Dynamic Programming (DP) to solve this efficiently.

Step 1: Understanding dp[i][j]
--------------------------------
dp[i][j] = the number of square submatrices whose bottom-right corner is at (i, j).

For example:
If dp[i][j] = 3, it means there is:
  - one 1x1 square ending at (i, j)
  - one 2x2 square ending at (i, j)
  - one 3x3 square ending at (i, j)

Step 2: Base cases
-------------------
- For the first row (i == 0) or first column (j == 0):
    If matrix[i][j] == 1, then dp[i][j] = 1 (only the single cell itself forms a square).
    If matrix[i][j] == 0, then dp[i][j] = 0 (cannot form any square).

Step 3: Recurrence Relation
----------------------------
For any cell (i, j) where i > 0 and j > 0:
If matrix[i][j] == 0:
    dp[i][j] = 0 (no square possible)
If matrix[i][j] == 1:
    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

Why min?
--------
To form a square of size k ending at (i, j):
  - The cell above must support at least size k-1 square
  - The cell to the left must support at least size k-1 square
  - The diagonal top-left cell must support at least size k-1 square
The limiting factor is the smallest of these three.

Step 4: Counting all squares
-----------------------------
Once dp is filled, sum up all dp[i][j] values.
This works because dp[i][j] counts all squares ending at (i, j) individually.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Create dp array of same size as matrix
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int totalCount = 0; // Will store the total number of square submatrices

    // Fill dp array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    // Base case: first row or first column
                    dp[i][j] = 1;
                } else {
                    // Apply recurrence relation
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                totalCount += dp[i][j]; // Add to total count
            }
        }
    }

    return totalCount;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    cout << "Total number of square submatrices with all 1s: "
         << countSquares(matrix) << endl;

    return 0;
}

/*
Example Dry Run:
----------------
matrix =
0 1 1 1
1 1 1 1
0 1 1 1

dp =
0 1 1 1
1 1 2 2
0 1 2 3

How to read dp:
---------------
- dp[1][2] = 2 → means there is:
    1 square of size 1x1
    1 square of size 2x2
- dp[2][3] = 3 → means there is:
    1 square of size 1x1
    1 square of size 2x2
    1 square of size 3x3

Sum of dp = total squares = 15
*/
