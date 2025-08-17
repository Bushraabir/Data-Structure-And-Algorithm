/*
Problem Statement:
- You are given a string s (length N).
- Task: Print the length of the Longest Palindromic Subsequence (LPS) in s.
- A subsequence does not require consecutive characters but must preserve their order.
- A palindrome reads the same forwards and backwards.
- Only the length is required, but the actual subsequence can also be reconstructed with additional steps.

Why This is a DP Problem:
- The LPS problem can be transformed into a Longest Common Subsequence (LCS) problem.
- Key Insight: If you reverse the given string s to get s2, the LCS of s and s2 will be the LPS of s.
- Why? Any sequence that is common between s and its reverse must be palindromic.
- Overlapping subproblems: The LCS computation involves repeated subproblems for smaller prefixes.
- Optimal substructure: The solution for (i, j) depends on optimal solutions for smaller indices.

Recurrence for LCS (used to find LPS):
If (i == 0 or j == 0):
    dp[i][j] = 0
Else if (s1[i-1] == s2[j-1]):
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Finding the Answer:
- The answer for LPS length is dp[N][N] after computing LCS(s, reverse(s)).

Time Complexity:
- Filling DP table: O(N * N)
- Total: O(N^2)

Space Complexity:
- O(N * N) for full DP table
- Can be optimized to O(N) using two 1D arrays for previous and current row.
*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (s[i - 1] == rev[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[N][N];
}

int main() {
    string s = "BBABCBCAB";
    cout << "Length of Longest Palindromic Subsequence: "
         << longestPalindromicSubsequence(s) << "\n";
    return 0;
}
