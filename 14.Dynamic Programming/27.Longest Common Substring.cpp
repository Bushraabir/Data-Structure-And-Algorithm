/*
Problem Statement:
- You are given two strings s1 (length N) and s2 (length M).
- Task: Print the length of the Longest Common Substring (LCSUBSTR) that appears in both strings.
- A substring is a contiguous block of characters within a string.
- The substring must maintain order and contiguity (no skipping characters).
- Only the length is required, but the actual substring can also be reconstructed with additional steps.

Why This is a DP Problem:
- We can use a bottom-up DP table (Tabulation) where dp[i][j] stores the length of the longest common substring 
  ending at s1[i-1] and s2[j-1].
- If characters match, we extend the substring length from the diagonal cell (dp[i-1][j-1] + 1).
- If characters don't match, we reset the length to 0 (breaking the contiguous requirement).
- Overlapping subproblems: dp[i][j] depends on dp[i-1][j-1].
- Optimal substructure: The solution for (i, j) builds upon solutions of smaller indices.

Recurrence for LCSUBSTR length:
If (i == 0 or j == 0):
    dp[i][j] = 0
Else if (s1[i-1] == s2[j-1]):
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = 0   // Reset because substring continuity is broken

Finding the Answer:
- Unlike LCS where dp[N][M] is the answer, here the answer is the maximum value in the entire dp table.

Time Complexity:
- Filling DP table: O(N * M)
- Scanning for maximum value: O(N * M) (done within filling loop)
- Total: O(N * M)

Space Complexity:
- O(N * M) for full DP table
- Can be optimized to O(M) using two 1D arrays for previous and current row.
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int N = s1.size(), M = s2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    int maxLen = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0; // reset because substring broken
            }
        }
    }

    return maxLen;
}

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    cout << "Length of Longest Common Substring: " 
         << longestCommonSubstring(s1, s2) << "\n";

    return 0;
}
