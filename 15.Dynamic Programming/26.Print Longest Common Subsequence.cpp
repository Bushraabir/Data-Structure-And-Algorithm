/*
Problem Statement:
- You are given two strings s1 (length N) and s2 (length M).
- Task: Print the Longest Common Subsequence (LCS) string that appears in both strings.
- A subsequence is formed by deleting zero or more characters from a string without changing the order of the remaining characters.
- The subsequence need not be contiguous.
- If multiple LCS strings exist, printing any one valid answer is acceptable.

Why This is a DP Problem:
- The length of the LCS can be computed using a bottom-up DP table (Tabulation).
- Printing the actual sequence requires backtracking through this table to reconstruct the path taken to get the final LCS length.
- At each step, you decide whether to move diagonally (when characters match) or move up/left (when characters differ).
- Overlapping subproblems: LCS(i, j) is solved repeatedly.
- Optimal substructure: The LCS for s1[0...i] and s2[0...j] is built from solutions of smaller subproblems.

Recurrence for LCS length:
If (i == 0 or j == 0):
    dp[i][j] = 0
Else if (s1[i-1] == s2[j-1]):
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Backtracking to Print LCS:
- Start from dp[N][M].
- If s1[i-1] == s2[j-1], this char is part of LCS → append it to result (in reverse order) and move diagonally.
- Else, move to the cell with the larger value (up or left).
- Continue until i == 0 or j == 0.
- Reverse the collected result to get the final LCS string.

Time Complexity:
- Building the DP table: O(N * M)
- Backtracking to print LCS: O(N + M)
- Total: O(N * M)

Space Complexity:
- O(N * M) for DP table (cannot space-optimize here because full table is needed for backtracking).
*/

#include <bits/stdc++.h>
using namespace std;

string printLCS(string s1, string s2) {
    int N = s1.size(), M = s2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    // Step 1: Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Backtrack to find the LCS string
    int i = N, j = M;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1]; // add character
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Reverse to get correct order
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s1 = "ABCDE";
    string s2 = "BDGEK";

    string lcs = printLCS(s1, s2);
    cout << "LCS Length: " << lcs.size() << "\n";
    cout << "LCS String: " << lcs << "\n";

    return 0;
}
