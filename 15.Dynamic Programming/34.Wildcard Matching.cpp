/*
Problem Statement:
- You are given two strings: s1 (pattern, length N) and s2 (text, length M).
- Task: Determine if s1 matches s2, where:
    1. Lowercase letters match themselves.
    2. '?' matches exactly one character.
    3. '*' matches zero or more characters.

Why This is a DP Problem:
- Matching depends on comparing the current characters of s1 and s2.
- '?' can match any one character.
- '*' can match zero or more characters.
- Overlapping subproblems exist (same i, j states recomputed in recursion).

Recursive Definition (0-based indexing):
Let F(i, j) = true if s1[0..i] matches s2[0..j], else false.

Base Cases:
- If i < 0 and j < 0: return true (both strings empty).
- If i < 0 and j >= 0: return false (empty pattern can't match non-empty text).
- If j < 0 and i >= 0: return true only if all s1[0..i] are '*', else false.

Recurrence:
If (s1[i] == s2[j] or s1[i] == '?'):
    F(i, j) = F(i-1, j-1)
Else if (s1[i] == '*'):
    F(i, j) = F(i-1, j) OR F(i, j-1)
Else:
    F(i, j) = false

Tabulation (1-based indexing):
dp[i][j] = true if s1[0..i-1] matches s2[0..j-1].

Initialization:
- dp[0][0] = true
- dp[0][j] = false for j > 0
- dp[i][0] = true if all s1[0..i-1] are '*', else false

Transition:
If (s1[i-1] == s2[j-1] or s1[i-1] == '?'):
    dp[i][j] = dp[i-1][j-1]
Else if (s1[i-1] == '*'):
    dp[i][j] = dp[i-1][j] OR dp[i][j-1]
Else:
    dp[i][j] = false

Space Optimization:
- We only need previous and current rows → O(M) space.

Time Complexity:
- O(N * M)

Space Complexity:
- O(N*M) for tabulation, O(M) for optimized version
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- 1. Pure Recursion --------------------
bool solveRec(int i, int j, string &s1, string &s2) {
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0) {
        for (int k = 0; k <= i; k++) {
            if (s1[k] != '*') return false;
        }
        return true;
    }

    if (s1[i] == s2[j] || s1[i] == '?')
        return solveRec(i - 1, j - 1, s1, s2);
    else if (s1[i] == '*')
        return solveRec(i - 1, j, s1, s2) || solveRec(i, j - 1, s1, s2);
    else
        return false;
}

// -------------------- 2. Memoization --------------------
bool solveMemo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0) {
        for (int k = 0; k <= i; k++) {
            if (s1[k] != '*') return false;
        }
        return true;
    }
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j] || s1[i] == '?')
        return dp[i][j] = solveMemo(i - 1, j - 1, s1, s2, dp);
    else if (s1[i] == '*')
        return dp[i][j] = solveMemo(i - 1, j, s1, s2, dp) || solveMemo(i, j - 1, s1, s2, dp);
    else
        return dp[i][j] = false;
}

// -------------------- 3. Tabulation --------------------
bool solveTab(string &s1, string &s2) {
    int N = s1.size();
    int M = s2.size();
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));

    dp[0][0] = true;

    // Base case: pattern with only '*' can match empty string
    for (int i = 1; i <= N; i++) {
        bool allStar = true;
        for (int k = 0; k < i; k++) {
            if (s1[k] != '*') {
                allStar = false;
                break;
            }
        }
        dp[i][0] = allStar;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (s1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[N][M];
}

// -------------------- 4. Space Optimization --------------------
bool solveSpaceOpt(string &s1, string &s2) {
    int N = s1.size();
    int M = s2.size();
    vector<bool> prev(M + 1, false), curr(M + 1, false);

    prev[0] = true;

    for (int i = 1; i <= N; i++) {
        bool allStar = true;
        for (int k = 0; k < i; k++) {
            if (s1[k] != '*') {
                allStar = false;
                break;
            }
        }
        curr[0] = allStar;

        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                curr[j] = prev[j - 1];
            else if (s1[i - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[M];
}

// -------------------- Main --------------------
int main() {
    string pattern = "ab*cd";
    string text = "abdefcd";

    cout << "Recursion: " << (solveRec(pattern.size() - 1, text.size() - 1, pattern, text) ? "True" : "False") << "\n";

    vector<vector<int>> dp(pattern.size(), vector<int>(text.size(), -1));
    cout << "Memoization: " << (solveMemo(pattern.size() - 1, text.size() - 1, pattern, text, dp) ? "True" : "False") << "\n";

    cout << "Tabulation: " << (solveTab(pattern, text) ? "True" : "False") << "\n";

    cout << "Space Optimized: " << (solveSpaceOpt(pattern, text) ? "True" : "False") << "\n";

    return 0;
}
