/*
 * Problem Statement: Longest Substring Without Repeating Characters
 *
 * You are given a string s (which may contain lowercase, uppercase, special characters, 
 * or any of the 256 ASCII characters). 
 * The task is to find the length of the longest substring that does not contain 
 * any repeating characters.
 *
 * Core Concept:
 * - Use a Sliding Window with two pointers (L and R).
 * - Maintain a hash array (size 256) to store the last seen index of each character.
 * - Expand the window by moving R, and shrink it by moving L when a repetition is found.
 *
 * Steps:
 * 1. Initialize:
 *    - L = 0 (left pointer), max_length = 0
 *    - hash array of size 256, filled with -1 (means character not seen yet).
 * 2. Traverse string with R from 0 to n-1:
 *    - For current character s[R], check its last seen index = hash[s[R]].
 *    - If last seen index >= L, it means s[R] repeats inside the current window:
 *         → Move L = last_seen_index + 1 (shrink window).
 *    - Update hash[s[R]] = R (mark last seen position).
 *    - Compute current window length = R - L + 1.
 *    - Update max_length = max(max_length, current window length).
 * 3. Return max_length after traversal.
 *
 * Example:
 * s = "cadbza"
 *
 * - R=0, 'c': no repeat, length=1 → max=1
 * - R=1, 'a': no repeat, length=2 → max=2
 * - R=2, 'd': no repeat, length=3 → max=3
 * - R=3, 'b': no repeat, length=4 → max=4
 * - R=4, 'z': no repeat, length=5 → max=5
 * - R=5, 'a': repeat found ('a' last seen at 1 ≥ L=0), move L=2 → window="dbza", length=4 → max=5
 *
 * Final answer = 5
 *
 * Time Complexity:
 * - O(N): Each character is processed at most twice (once by R, once by L).
 *
 * Space Complexity:
 * - O(1): Hash array of size 256 (constant).
 */

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> last_seen(256, -1);
    int n = s.size();
    int L = 0, max_length = 0;

    for (int R = 0; R < n; R++) {
        if (last_seen[s[R]] >= L) {
            L = last_seen[s[R]] + 1; // shrink window
        }
        last_seen[s[R]] = R; // update last seen index
        max_length = max(max_length, R - L + 1);
    }

    return max_length;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    string s = "cadbza";
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
