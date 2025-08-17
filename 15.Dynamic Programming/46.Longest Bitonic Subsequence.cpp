#include <bits/stdc++.h>
using namespace std;

/*
    Function: checkPossible
    -----------------------
    This function checks whether the longer string (s1) can be formed
    by adding exactly ONE character to the shorter string (s2).

    Steps:
    1. Check that s1's length is exactly one more than s2's length.
    2. Use two pointers to compare characters:
       - If characters match → move both pointers forward.
       - If characters don't match → move only pointer in s1 (skip the extra char).
    3. If we successfully match all characters of s2, return true.
*/
bool checkPossible(string &s1, string &s2) {
    // s1 should be the "bigger" string, s2 the "smaller" string
    if (s1.size() != s2.size() + 1) return false;

    int first = 0;  // pointer for s1
    int second = 0; // pointer for s2

    while (first < s1.size()) {
        if (second < s2.size() && s1[first] == s2[second]) {
            // Characters match → move both pointers
            first++;
            second++;
        } else {
            // Characters don't match → move only s1's pointer
            first++;
        }
    }

    // If we matched all chars of s2, then s1 is valid
    return (second == s2.size());
}

/*
    Function: longestStrChain
    -------------------------
    Main logic for finding the length of the longest string chain.

    Approach:
    1. Sort the words by length in ascending order.
    2. Initialize a dp array → dp[i] = length of longest chain ending at words[i].
    3. Nested loops (similar to LIS):
        For each words[i], check all words[j] before it.
        If words[j] can be transformed into words[i] by adding one character
        → update dp[i] accordingly.
    4. Keep track of the maximum chain length.
*/
int longestStrChain(vector<string> &words) {
    // Step 1: Sort words by length
    sort(words.begin(), words.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });

    int n = words.size();
    vector<int> dp(n, 1); // Each word is at least a chain of length 1
    int maxLen = 1;       // Track the maximum length found

    // Step 2: Apply LIS-style nested loops
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Check if words[j] can be predecessor of words[i]
            if (checkPossible(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        // Update maximum length after each i
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    /*
        Explanation for the above input:
        One possible longest chain is:
        "a" → "ba" → "bda" → "bdca"
        This has length = 4.
    */

    cout << "Length of Longest String Chain: " << longestStrChain(words) << endl;

    return 0;
}

/*
    Time Complexity:
        Sorting → O(N log N)
        DP Nested Loops → O(N^2 * L) where L = max length of a word
        Overall: O(N^2 * L)

    Space Complexity:
        O(N) for the dp array.

    Key Idea:
        The trick is sorting by word length, so any valid predecessor
        of words[i] will always appear before it in the array.
        This turns the problem into an LIS-like DP where
        "increasing" → "one character insertion".
*/
