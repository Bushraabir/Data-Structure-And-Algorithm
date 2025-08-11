/*
Problem Statement:
- You are given two strings: s1 (length N) and s2 (length M).
- Task: Find the minimum number of operations required to convert s1 into s2.
- Allowed Operations:
    1. Insert a character.
    2. Delete a character.
    3. Replace a character.

Why This is a DP Problem:
- The decision at each step depends on comparing the last characters of the current prefixes.
- If characters match, we move diagonally without any cost.
- If characters don’t match, we try all three operations and pick the minimum cost.
- Overlapping subproblems exist (same i, j pairs get recomputed), so DP is ideal.

Recursive Definition (0-based indexing):
Let F(i, j) = minimum operations to convert s1[0..i] to s2[0..j].

Base Cases:
- If i < 0: We have exhausted s1, so we must insert (j + 1) remaining characters of s2.
- If j < 0: We have exhausted s2, so we must delete (i + 1) remaining characters of s1.

Recurrence:
If (s1[i] == s2[j]):
    F(i, j) = F(i-1, j-1)
Else:
    F(i, j) = 1 + min(
        F(i, j-1),     // Insert
        F(i-1, j),     // Delete
        F(i-1, j-1)    // Replace
    )

Tabulation (1-based indexing):
dp[i][j] = min operations to convert s1[0..i-1] to s2[0..j-1].

Initialization:
- dp[0][j] = j   (convert empty s1 to s2 → insert j characters)
- dp[i][0] = i   (convert s1 to empty s2 → delete i characters)

Transition:
If (s1[i-1] == s2[j-1]):
    dp[i][j] = dp[i-1][j-1]
Else:
    dp[i][j] = 1 + min(
        dp[i][j-1],   // Insert
        dp[i-1][j],   // Delete
        dp[i-1][j-1]  // Replace
    )

Space Optimization:
- We only need the previous row and the current row → O(M) space.

Time Complexity:
- O(N * M)

Space Complexity:
- O(M) using 1D array optimization
*/

#include <bits/stdc++.h>
using namespace std;

int minDistance(string s1, string s2) {
    int N = s1.size();
    int M = s2.size();
    
    vector<int> prev(M + 1, 0), curr(M + 1, 0);

    // Base case: converting empty s1 to s2[0..j-1]
    for (int j = 0; j <= M; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= N; i++) {
        curr[0] = i; // Base case: delete i chars to match empty s2
        for (int j = 1; j <= M; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1]; // no cost
            } else {
                curr[j] = 1 + min({curr[j - 1],  // Insert
                                   prev[j],      // Delete
                                   prev[j - 1]}); // Replace
            }
        }
        prev = curr;
    }

    return prev[M];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";
    cout << "Minimum Edit Distance: " << minDistance(s1, s2) << "\n";

    s1 = "intention";
    s2 = "execution";
    cout << "Minimum Edit Distance: " << minDistance(s1, s2) << "\n";

    return 0;
}
