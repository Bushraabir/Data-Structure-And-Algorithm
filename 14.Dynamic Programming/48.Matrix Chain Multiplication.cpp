#include <bits/stdc++.h>
using namespace std;

/*
    MATRIX CHAIN MULTIPLICATION (Bottom-Up / Tabulation)

    Problem:
    Given an array 'arr[]' of size N, where arr[i] represents the dimensions of the matrices:
    Matrix i has dimensions arr[i-1] x arr[i].

    We want to find the minimum number of scalar multiplications needed to multiply the chain.

    Example:
    arr = {40, 20, 30, 10, 30}
    Matrix 1: 40x20
    Matrix 2: 20x30
    Matrix 3: 30x10
    Matrix 4: 10x30
    Answer = 26000
*/

int matrixMultiplication(int N, vector<int> &arr) {
    // Step 1: Create the DP table
    // dp[i][j] = minimum cost to multiply matrices from i to j
    vector<vector<int>> dp(N, vector<int>(N, 0));

    /*
        Step 2: Base Case (Rule 1)
        - Multiplying one matrix alone has no cost, so dp[i][i] = 0
        - This is already initialized to 0 by default.
    */

    /*
        Step 3: Loop order (Rule 2)
        - We must fill dp in such a way that smaller problems are solved first.
        - i should go from N-1 down to 1.
        - j should go from i+1 up to N-1.
    */
    for (int i = N - 1; i >= 1; i--) { // i starts from last matrix index
        for (int j = i + 1; j < N; j++) { // j is always ahead of i
            int mini = INT_MAX; // Store minimum cost for this subproblem

            /*
                Step 4: Copy recurrence relation (Rule 3)
                - Try all possible partitions (k)
                - Cost formula:
                    cost = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j])
                - dp[i][k] = cost of multiplying left half
                - dp[k+1][j] = cost of multiplying right half
                - (arr[i-1] * arr[k] * arr[j]) = cost of multiplying two resulting matrices
            */
            for (int k = i; k <= j - 1; k++) {
                int steps = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                mini = min(mini, steps);
            }

            dp[i][j] = mini; // Store result in dp table
        }
    }

    /*
        Step 5: Final Answer
        - Minimum cost to multiply matrices 1 to N-1 is stored in dp[1][N-1]
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
    EXPLANATION OF LOOPS:

    i = starting index of chain
    j = ending index of chain
    k = partition point (where we split the chain into two subchains)

    Example trace:
    arr = {40, 20, 30, 10, 30}
    N = 5 (4 matrices)

    We first solve smallest chains (length 2), then length 3, etc.
    dp table is filled diagonally from bottom-left to top-right.

    Time Complexity: O(N^3) (loops over i, j, k)
    Space Complexity: O(N^2) (dp table)
*/
