/*
Problem Statement:
- You are given two strings s1 (length N) and s2 (length M).
- Task: Find the length of the longest subsequence that appears in both strings.
- A subsequence is formed by deleting zero or more characters from a string without changing the order of the remaining characters.
- The subsequence need not be contiguous.

Why This is a DP Problem:
- At each step, you compare the current characters of both strings.
- If they match, you take them and move diagonally in the problem space (both indices decrease).
- If they don't match, you try skipping a character from either string and take the maximum.
- Overlapping subproblems: The same (index1, index2) pairs are solved multiple times in recursion.
- Optimal substructure: The LCS of s1[0...i] and s2[0...j] depends on smaller subproblems like s1[0...i-1], s2[0...j], and s1[0...i], s2[0...j-1].

Recurrence:
If (i < 0 or j < 0):
    return 0
Else if (s1[i] == s2[j]):
    return 1 + f(i-1, j-1)
Else:
    return max(f(i-1, j), f(i, j-1))

Initial Call:
f(N-1, M-1)

Time Complexity:
- Pure recursion: Exponential
- Memoization/Tabulation: O(N * M)
- Space optimized: O(M) or O(N) (whichever is smaller)

Space Complexity:
- Memoization: O(N * M) + recursion stack O(N + M)
- Tabulation: O(N * M)
- Space optimized: O(M) or O(N)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
int lcsMemoHelper(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsMemoHelper(i - 1, j - 1, s1, s2, dp);
    else
        return dp[i][j] = max(lcsMemoHelper(i - 1, j, s1, s2, dp),
                              lcsMemoHelper(i, j - 1, s1, s2, dp));
}

int lcsMemo(string s1, string s2) {
    int N = s1.size(), M = s2.size();
    vector<vector<int>> dp(N, vector<int>(M, -1));
    return lcsMemoHelper(N - 1, M - 1, s1, s2, dp);
}

/* -------------------- TABULATION -------------------- */
int lcsTab(string s1, string s2) {
    int N = s1.size(), M = s2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[N][M];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
int lcsSpaceOpt(string s1, string s2) {
    int N = s1.size(), M = s2.size();
    vector<int> prev(M + 1, 0), curr(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[M];
}

/* -------------------- MAIN -------------------- */
int main() {
    string s1 = "ACD";
    string s2 = "CED";

    cout << "LCS (Memoization): " << lcsMemo(s1, s2) << "\n";
    cout << "LCS (Tabulation): " << lcsTab(s1, s2) << "\n";
    cout << "LCS (Space Optimized): " << lcsSpaceOpt(s1, s2) << "\n";

    return 0;
}
