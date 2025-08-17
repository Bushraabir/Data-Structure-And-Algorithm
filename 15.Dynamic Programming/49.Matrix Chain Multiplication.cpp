#include <bits/stdc++.h>
using namespace std;

/*
    MATRIX CHAIN MULTIPLICATION (MCM) – Bottom-Up Tabulation

    Problem:
    --------
    Given an array `arr[]` of size N, where arr[i] represents the dimensions
    of the matrices in the chain. Matrix `i` has dimensions:
        arr[i-1] x arr[i]

    Goal:
    -----
    Find the minimum number of scalar multiplications needed to multiply
    the whole chain of matrices.

    Example:
    --------
    arr = {40, 20, 30, 10, 30}
    Matrix 1: 40x20
    Matrix 2: 20x30
    Matrix 3: 30x10
    Matrix 4: 10x30
    Output: 26000
*/


int matrixMultiplication(int N, vector<int> &arr) {
    /*
        Step 1: Create the DP table
        --------------------------
        dp[i][j] = minimum cost to multiply matrices from index i to index j.
        Note: We'll use 1-based indexing for clarity with the MCM definition.
    */
    vector<vector<int>> dp(N, vector<int>(N, 0));

    /*
        Step 2: Base Case (Rule 1)
        --------------------------
        If we have only ONE matrix (i == j), the cost is 0 because no multiplication is needed.
        This corresponds to the diagonal elements of the dp table.
        By default, dp[i][i] is already initialized to 0.
    */

    /*
        Step 3: Loop directions (Rule 2)
        ---------------------------------
        - We solve smaller problems first (shorter chains of matrices) and
          build up to the bigger one.
        - i = start index of chain → goes from N-1 down to 1.
        - j = end index of chain   → goes from i+1 up to N-1.

        This ensures that when we calculate dp[i][j], all the subproblems
        dp[i][k] and dp[k+1][j] are already solved.
    */
    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int mini = INT_MAX; // store minimum cost for multiplying matrices from i to j

            /*
                Step 4: Recurrence Relation (Rule 3)
                ------------------------------------
                Partition the chain between i and j at every possible point k:
                    Cost = dp[i][k]   (left half multiplication cost)
                         + dp[k+1][j] (right half multiplication cost)
                         + arr[i-1] * arr[k] * arr[j] (cost of multiplying the two resulting matrices)

                We take the minimum over all k.
            */
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                mini = min(mini, cost);
            }

            // store the result for this subproblem
            dp[i][j] = mini;
        }
    }

    /*
        Step 5: Final Result
        --------------------
        The answer for multiplying the full chain (from 1 to N-1) is dp[1][N-1].
    */
    return dp[1][N-1];
}


int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int N = arr.size();

    cout << "Minimum number of multiplications: "
         << matrixMultiplication(N, arr) << endl;

    return 0;
}


/*
    Time Complexity:
    ----------------
    O(N^3) → three nested loops over i, j, and k.

    Space Complexity:
    -----------------
    O(N^2) → for storing the dp table.

    Why Bottom-Up is Better Here:
    -----------------------------
    - No recursion → no auxiliary stack space.
    - Fully iterative, so no "partial acceptance" problem from stack limits.
    - Solves subproblems in a controlled order ensuring dependencies are met.

    Example dp table filling order:
    --------------------------------
    For arr = {40, 20, 30, 10, 30}:
    - First fill length = 2 chains → dp[1][2], dp[2][3], dp[3][4]
    - Then length = 3 chains → dp[1][3], dp[2][4]
    - Finally length = 4 chain → dp[1][4] → final answer.
*/
