#include <bits/stdc++.h>
using namespace std;

/*
========================================================
PALINDROME PARTITIONING - II  (Front Partition DP)
========================================================

Problem:
--------
Given a string `s`, partition it into substrings such that
every substring is a palindrome. Return the **minimum number
of cuts** needed to make such a partition.

Example:
--------
Input:  "aab"
Possible partitions:
    a | a | b    -> 2 cuts
    aa | b       -> 1 cut  minimum
Output: 1

Key Points:
-----------
- We count "cuts", not partitions.
- Worst case: n-1 cuts (each character separate).
- Always possible because single chars are palindromes.

Approach:
---------
We use the **Front Partition** technique:
  1. Start at index `i = 0`.
  2. Try all possible end indices `j` for the first substring.
  3. If s[i...j] is a palindrome:
       cost = 1 + f(j+1)    // 1 cut for this piece + rest
  4. Take the minimum over all valid `j`.

Why subtract 1 at the end?
--------------------------
We add `1` for the last palindrome segment, but the last
segment doesn't need a "cut" after it. So final answer = result - 1.
*/

// ----------------------------
// Helper: Check palindrome
// ----------------------------
bool isPalindrome(int start, int end, const string &s) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

/*
========================================
  MEMOIZATION (Top-Down DP)
========================================
- dp[i] = minimum cuts needed for substring starting at i.
- If already computed, return dp[i].
- Recurrence:
      dp[i] = min( 1 + dp[j+1] ) for all j from i..n-1
               where s[i..j] is palindrome
*/
int solveMemo(int i, int n, const string &s, vector<int> &dp) {
    if (i == n) return 0; // no more cuts needed at the end

    if (dp[i] != -1) return dp[i];

    int minCost = INT_MAX;

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            int cost = 1 + solveMemo(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int minCutMemo(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    // subtract 1 because last segment doesn't require a cut
    return solveMemo(0, n, s, dp) - 1;
}

/*
========================================
  TABULATION (Bottom-Up DP)
========================================
Steps:
 1. Base case: dp[n] = 0 (at the end, no cuts needed)
 2. Fill dp[i] from i = n-1 down to 0
 3. For each i, try all j >= i
 4. If s[i..j] is palindrome, cost = 1 + dp[j+1]
 5. dp[i] = min of all such costs
*/
int minCutTab(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0); // dp[n] = 0

    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1; // subtract 1 for last segment
}

/*
----------------------------------------
 Complexity Analysis
----------------------------------------
Time:
- O(N^3) naive because isPalindrome(i,j) = O(N) and we do it
  for each (i,j) pair.
- Can be reduced to O(N^2) if palindrome checks are precomputed.

Space:
- O(N) for dp array in both memo and tabulation.
- Memo uses O(N) stack space, tabulation uses O(1) extra stack.

----------------------------------------
*/

// ----------------------------
// Driver
// ----------------------------
int main() {
    string s = "aab";
    cout << "Using Memoization: " << minCutMemo(s) << "\n";
    cout << "Using Tabulation : " << minCutTab(s) << "\n";
    return 0;
}
