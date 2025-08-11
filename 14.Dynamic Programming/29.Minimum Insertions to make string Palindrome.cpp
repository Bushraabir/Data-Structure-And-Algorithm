/*
Problem Statement:
- You are given a string s (length N).
- Task: Find the minimum number of insertions required to make s a palindrome.
- You may insert any characters at any position in the string.
- A palindrome reads the same forwards and backwards.

Why This is a DP Problem:
- The key idea is to keep the largest palindromic portion of the string intact to minimize insertions.
- This leads to finding the Longest Palindromic Subsequence (LPS) in s.
- Once LPS is known, the remaining characters (not in LPS) need to be mirrored via insertions.
- Formula:
    Minimum Insertions = N - LPS_length
- LPS itself can be found using the Longest Common Subsequence (LCS) between s and reverse(s).

Recurrence for LCS (used to find LPS):
If (i == 0 or j == 0):
    dp[i][j] = 0
Else if (s1[i-1] == s2[j-1]):
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Finding the Answer:
- Compute LPS_length = LCS(s, reverse(s))
- Answer = N - LPS_length

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

int minInsertionsToPalindrome(string s) {
    int N = s.size();
    int lps = longestPalindromicSubsequence(s);
    return N - lps;
}

int main() {
    string s = "abcaa";
    cout << "Minimum insertions to make palindrome: "
         << minInsertionsToPalindrome(s) << "\n";
    return 0;
}
