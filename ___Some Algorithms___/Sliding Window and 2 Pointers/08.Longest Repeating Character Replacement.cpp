/*
 * Problem Statement: Longest Repeating Character Replacement
 *
 * You are given a string S consisting of only uppercase English letters and an integer K.
 * The task is to return the length of the longest substring where we can replace at most K characters 
 * so that all characters in the substring become the same.
 *
 * Core Concept:
 * - For any substring, to minimize replacements, convert all characters to the most frequent one.
 * - Number of changes needed = (Window length) - (Max frequency in that window).
 * - Valid window condition: (Window length - maxFrequency) <= K
 * - Use Sliding Window / Two Pointers with a frequency map of size 26.
 *
 * Brute Force Solution (O(N^2)):
 * 1. Generate all substrings using two nested loops I (start) and J (end).
 * 2. Maintain a frequency array of size 26 for each substring.
 * 3. Find maxFrequency in that substring.
 * 4. If (len - maxFrequency) <= K, update maxLength.
 * 5. Else, break the loop (as extending further will only worsen).
 *
 * Time Complexity: O(N^2)
 * Space Complexity: O(1) (26-element array).
 *
 * Optimal Solution (Sliding Window, O(N)):
 * 1. Use two pointers L and R to represent the window.
 * 2. Expand R, update freq[S[R]] and update maxFrequency.
 * 3. If (windowSize - maxFrequency) > K, shrink by moving L and decrementing freq[S[L]].
 * 4. At each step, update maxLength = max(maxLength, windowSize).
 * 5. Return maxLength.
 *
 * Key Insight:
 * - maxFrequency is updated only when R moves right.
 * - We never decrease maxFrequency when L moves because it's safe to keep it 
 *   as the "historical maximum". It won't harm correctness.
 *
 * Example:
 * S = "AABABB", K = 2
 * Answer = 5  (substring "AABAB")
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int L = 0, maxFreq = 0, maxLength = 0;

    for (int R = 0; R < s.size(); R++) {
        freq[s[R] - 'A']++;
        maxFreq = max(maxFreq, freq[s[R] - 'A']);

        // if window invalid, shrink from left
        while ((R - L + 1) - maxFreq > k) {
            freq[s[L] - 'A']--;
            L++;
        }

        maxLength = max(maxLength, R - L + 1);
    }
    return maxLength;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    string s = "AABABB";
    int k = 2;
    cout << "Longest substring length after at most " << k
         << " replacements: " << characterReplacement(s, k) << endl;
    return 0;
}
