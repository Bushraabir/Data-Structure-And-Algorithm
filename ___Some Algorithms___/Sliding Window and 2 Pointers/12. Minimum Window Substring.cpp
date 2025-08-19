/*
 * Problem Statement: Minimum Window Substring
 *
 * You are given two strings s (the larger string) and t (the target string).
 * The task is to find the minimum-length substring in s that contains all 
 * characters of t with their required frequencies. Return the substring itself.
 *
 * Core Concept:
 * - Substrings are contiguous portions of s.
 * - The substring is valid if it contains all characters of t (including duplicates).
 * - Sliding window with two pointers (L and R) is ideal for this type of "minimum window" problem.
 *
 * Brute Force Solution (O(N^3)):
 * 1. Iterate over all possible substring starts (i).
 * 2. Extend end pointer (j) for substring s[i...j].
 * 3. For each substring, check if it contains all characters of t with required frequencies.
 * 4. Update minimum length if valid substring found.
 *
 * Time Complexity: O(N^3) in worst case.
 * Space Complexity: O(256) for character frequency map.
 *
 * Optimal Solution (Sliding Window, O(N + M)):
 * 1. Pre-populate a hash array (size 256 for ASCII) with frequencies of characters in t.
 * 2. Initialize pointers L = 0, R = 0, count = 0, min_length = large value, start_index = -1.
 * 3. Expand R:
 *      - Decrement hash[s[R]].
 *      - If s[R] was needed (hash[s[R]] >= 0 after decrement), increment count.
 * 4. While count == t.size():
 *      - Update min_length and start_index if current window is smaller.
 *      - Increment hash[s[L]].
 *      - If hash[s[L]] > 0 after increment, decrement count.
 *      - Move L forward.
 * 5. Move R forward until end of s.
 * 6. Return empty string if no valid window found; otherwise return substring starting at start_index with min_length.
 *
 * Key Insight:
 * - Use sliding window to expand until valid, then shrink to minimize length.
 * - Hash map tracks required characters and frequencies efficiently.
 *
 * Example:
 * s = "ADOBECODEBANC", t = "ABC"
 * Answer = "BANC"
 *
 * Time Complexity: O(N + M)
 * Space Complexity: O(256) for hash map
 */

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    vector<int> hash(256, 0);
    for (char c : t) hash[c]++;
    
    int L = 0, R = 0, count = 0;
    int min_len = INT_MAX, start_index = 0;
    int t_len = t.size();
    
    while (R < s.size()) {
        // include s[R] in window
        if (hash[s[R]] > 0) count++;
        hash[s[R]]--;
        R++;
        
        // shrink window from left while valid
        while (count == t_len) {
            if (R - L < min_len) {
                min_len = R - L;
                start_index = L;
            }
            hash[s[L]]++;
            if (hash[s[L]] > 0) count--;
            L++;
        }
    }
    
    return (min_len == INT_MAX) ? "" : s.substr(start_index, min_len);
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring containing all characters of t: "
         << minWindow(s, t) << endl;
    return 0;
}
