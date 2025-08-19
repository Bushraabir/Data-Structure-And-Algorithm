/*
 * Problem Statement: Longest Substring With At Most K Distinct Characters
 *
 * You are given a string s and an integer k. 
 * The task is to return the length of the longest substring that contains at most k distinct characters.
 *
 * Core Concept:
 * - A substring is valid if it has <= k distinct characters.
 * - Use the Sliding Window technique with two pointers (L and R).
 * - Expand the window by moving R, and shrink it by moving L when the number of distinct characters exceeds k.
 *
 * Brute Force Solution (O(N^2)):
 * 1. Use two nested loops: I for the start, J for the end of substring.
 * 2. Maintain a frequency map for substring s[I...J].
 * 3. If map.size() <= k, update max_length = max(max_length, J - I + 1).
 * 4. If map.size() > k, break inner loop early (since extending won't help).
 * 
 * Time Complexity: O(N^2) 
 * Space Complexity: O(1) (map size is bounded by constant alphabet size).
 *
 * Optimal Solution 1 (Sliding Window with inner while loop):
 * 1. Initialize L=0, R=0, max_length=0, and an empty frequency map.
 * 2. Iterate R from 0 to n-1:
 *    - Add s[R] into map (increment frequency).
 *    - While map.size() > k (invalid window):
 *        - Decrement frequency of s[L].
 *        - If frequency of s[L] becomes 0, erase it from map.
 *        - Increment L (shrink window).
 *    - Update max_length = max(max_length, R - L + 1).
 *
 * Time Complexity: O(N), since L and R each move at most N steps.
 * Space Complexity: O(1), frequency map has at most constant distinct characters.
 *
 * Optimal Solution 2 (Sliding Window without inner loop, Most Optimal):
 * 1. Initialize L=0, max_length=0, and an empty frequency map.
 * 2. Iterate R from 0 to n-1:
 *    - Add s[R] into map (increment frequency).
 *    - If map.size() > k:
 *        - Decrement frequency of s[L].
 *        - If frequency of s[L] becomes 0, erase it from map.
 *        - Increment L by 1 (shrink window by one step).
 *    - Update max_length = max(max_length, R - L + 1).
 *
 * Key Insight:
 * - This avoids the inner while loop. The window shrinks by only one step when invalid.
 * - Clean and elegant O(N) solution.
 *
 * Example:
 * s = "aaabbcc", k = 2
 * - Longest substring with at most 2 distinct characters = "aaabb" (length 5).
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.size();
    if (k == 0) return 0;

    unordered_map<char, int> freq;
    int L = 0, max_length = 0;

    for (int R = 0; R < n; R++) {
        freq[s[R]]++;

        if (freq.size() > k) {
            freq[s[L]]--;
            if (freq[s[L]] == 0) freq.erase(s[L]);
            L++; // shrink window by one step
        }

        max_length = max(max_length, R - L + 1);
    }
    return max_length;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    string s = "aaabbcc";
    int k = 2;
    cout << "Longest substring with at most " << k 
         << " distinct characters: "
         << lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}
