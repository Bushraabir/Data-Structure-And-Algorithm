/*
Problem Statement:
- You are given two strings: string1 (length N) and string2 (length M).
- Task: Find the Shortest Common Supersequence (SCS) of the two strings.
- The SCS is the shortest possible string that contains both string1 and string2 as subsequences.

Why This is a DP Problem:
- If two characters match in both strings, we can take them only once in the SCS.
- The characters common to both strings form the Longest Common Subsequence (LCS).
- Using LCS helps avoid duplicating characters and ensures minimal length.

Formula for SCS Length:
Length(SCS) = N + M - LCS_length

Recurrence for LCS:
If (i == 0 or j == 0):
    dp[i][j] = 0
Else if (s1[i-1] == s2[j-1]):
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Printing the SCS:
- Build the LCS DP table.
- Start from dp[N][M] and backtrack:
    1. If characters match: add the character to result and move diagonally (i--, j--).
    2. If not matching: 
       - If dp[i-1][j] > dp[i][j-1], take s1[i-1] and move up (i--).
       - Else take s2[j-1] and move left (j--).
- After loop, append remaining characters from s1 or s2 (if any).
- Reverse the result (because we built it backwards).

Time Complexity:
- O(N * M) for filling the DP table and backtracking.

Space Complexity:
- O(N * M) for the DP table.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildLCS(string &s1, string &s2) {
    int N = s1.size();
    int M = s2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp;
}

string shortestCommonSupersequence(string s1, string s2) {
    int N = s1.size();
    int M = s2.size();
    auto dp = buildLCS(s1, s2);

    int i = N, j = M;
    string result = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result.push_back(s1[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            result.push_back(s1[i - 1]);
            i--;
        } else {
            result.push_back(s2[j - 1]);
            j--;
        }
    }
    while (i > 0) {
        result.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0) {
        result.push_back(s2[j - 1]);
        j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s1 = "brute";
    string s2 = "groot";
    string scs = shortestCommonSupersequence(s1, s2);
    cout << "Shortest Common Supersequence: " << scs << "\n";
    cout << "Length of SCS: " << scs.size() << "\n";
    return 0;
}
