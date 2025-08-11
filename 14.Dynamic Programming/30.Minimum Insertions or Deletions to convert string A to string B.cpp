/*
Problem Statement:
- You are given two strings: string1 (length N) and string2 (length M).
- Task: Convert string1 into string2 using the fewest possible operations.
- Allowed operations:
    1. Delete any character from string1.
    2. Insert any character into string1.

Why This is a DP Problem:
- The key idea is to keep the largest common portion of the strings intact to minimize insertions and deletions.
- This "kept" portion is the Longest Common Subsequence (LCS) of string1 and string2.
- Characters in the LCS are already in the correct relative order and don't need changes.
- Everything else must be deleted from string1 or inserted to match string2.
- Formulas:
    Deletions = N - LCS_length
    Insertions = M - LCS_length
    Total Minimum Operations = (N - LCS_length) + (M - LCS_length)
                              = N + M - 2 * LCS_length

Recurrence for LCS:
If (i == 0 or j == 0):
    dp[i][j] = 0
Else if (s1[i-1] == s2[j-1]):
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Finding the Answer:
- Compute LCS_length = LCS(string1, string2)
- Deletions = N - LCS_length
- Insertions = M - LCS_length
- Total Operations = N + M - 2 * LCS_length

Time Complexity:
- Filling DP table: O(N * M)
- Total: O(N * M)

Space Complexity:
- O(N * M) for full DP table
- Can be optimized to O(min(N, M)) using two 1D arrays for previous and current row.
*/

#include <bits/stdc++.h>
using namespace std;

// Compute the length of the Longest Common Subsequence (LCS) using space-optimized DP
int longestCommonSubsequence(string s1, string s2) {
    int N = s1.size();
    int M = s2.size();
    
    // If either string is empty, LCS length is 0
    if (N == 0 || M == 0) return 0;
    
    // Use two 1D arrays to optimize space to O(min(N, M))
    if (N < M) {
        swap(s1, s2);
        swap(N, M); // Ensure s2 is the shorter string
    }
    
    vector<int> prev(M + 1, 0), curr(M + 1, 0);
    
    // Fill DP table using two rows
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        swap(prev, curr); // Move current row to previous
    }
    
    return prev[M];
}

// Compute minimum insertions and deletions to convert s1 to s2
pair<int, int> minInsertDelete(string s1, string s2) {
    int N = s1.size();
    int M = s2.size();
    int lcs = longestCommonSubsequence(s1, s2);
    int deletions = N - lcs;
    int insertions = M - lcs;
    return {insertions, deletions};
}

int main() {
    string s1 = "ABCD";
    string s2 = "ANC";
    
    // Handle empty input cases
    if (s1.empty() && s2.empty()) {
        cout << "Minimum Insertions: 0\n";
        cout << "Minimum Deletions: 0\n";
        cout << "Total Operations: 0\n";
        return 0;
    }
    
    auto [insertions, deletions] = minInsertDelete(s1, s2);
    cout << "Minimum Insertions: " << insertions << "\n";
    cout << "Minimum Deletions: " << deletions << "\n";
    cout << "Total Operations: " << insertions + deletions << "\n";
    
    return 0;
}
