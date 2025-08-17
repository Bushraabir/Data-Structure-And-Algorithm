#include <bits/stdc++.h>
using namespace std;

/*
=====================================================
Problem: Minimum Cost to Cut the Stick
-----------------------------------------------------
You are given:
- Length of a stick: n
- Positions where you can cut: cuts[] array

Goal:
- Cut at all given positions in ANY order
- Cost of each cut = length of the stick at that moment
- Find MINIMUM total cost possible
=====================================================
*/

int minCost(int n, vector<int> &cuts) {
    // STEP 1: Modify cuts array
    // Add boundaries 0 and n to the cuts list
    cuts.push_back(0);
    cuts.push_back(n);

    // Sort cuts so that segments are in correct order
    sort(cuts.begin(), cuts.end());

    int m = cuts.size(); // Now contains original cuts + 2 extra boundaries

    /*
    dp[i][j] = minimum cost to cut the stick segment between cuts[i] and cuts[j]
    IMPORTANT:
    - i and j here are indices in the "cuts" array, NOT actual positions
    - i < j always because we consider segments from cuts[i] to cuts[j]
    */

    vector<vector<int>> dp(m, vector<int>(m, 0));

    /*
    STEP 2: Tabulation approach
    -------------------------------------------------
    Recursion was like:
        f(i, j) = min over k in [i+1, j-1] of:
                  (cuts[j] - cuts[i]) + f(i, k) + f(k, j)

    Base case:
        If there are no cuts between i and j (j = i+1), cost = 0
        → already handled since dp is initialized with 0

    Build from smaller segments to larger segments.
    */

    // length = number of cuts between i and j
    // Start from small segments and go up
    for (int len = 2; len < m; len++) { 
        // len = distance between i and j in terms of indices
        for (int i = 0; i + len < m; i++) {
            int j = i + len; // segment from cuts[i] to cuts[j]

            dp[i][j] = INT_MAX;

            // Try cutting at every possible k between i and j
            for (int k = i + 1; k < j; k++) {
                int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // Answer: minimum cost to cut the whole stick from 0 to n
    return dp[0][m - 1];
}

int main() {
    int n = 7; // Length of the stick
    vector<int> cuts = {1, 3, 4, 5}; // Positions where we must cut

    cout << "Minimum Cost to Cut the Stick: " << minCost(n, cuts) << endl;

    /*
    Example:
        Stick length = 7, cuts = {1, 3, 4, 5}
        Optimal order of cuts yields cost = 16
    */

    return 0;
}

/*
=====================================================
EXPLANATION OF TABULATION:
-----------------------------------------------------
We consider the stick as segments between "cuts" points:
Example: n = 7, cuts = {1, 3, 4, 5}
After adding boundaries: cuts = {0, 1, 3, 4, 5, 7}

dp[i][j] represents min cost for stick from cuts[i] to cuts[j]
- If j = i+1 → No cuts inside → cost = 0
- Otherwise:
    Try every possible cut k between (i, j):
        Cost = length of current stick (cuts[j] - cuts[i])
               + min cost of left segment (dp[i][k])
               + min cost of right segment (dp[k][j])
    Take the minimum over all possible k.

We fill dp table for increasing segment lengths:
    len = 2 means distance between i and j = 2 → one cut in between
    len = 3 → two cuts in between, and so on.

Finally:
    dp[0][m-1] = min cost to cut entire stick from 0 to n.

-----------------------------------------------------
Complexity:
- Time: O(M^3) where M = cuts.size()
- Space: O(M^2)
-----------------------------------------------------
*/
