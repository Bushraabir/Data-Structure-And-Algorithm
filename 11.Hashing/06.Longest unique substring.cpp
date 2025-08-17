/*
    ▪ Problem: Find the length of the longest substring without repeating characters.
      You are given a string S. You need to find the maximum length of any
      contiguous substring of S in which no character repeats.

    ▪ Approach (Sliding Window with right++):
        1. Use two pointers: 'left' and 'right' to represent the current window.
        2. Maintain an unordered_map<char, int> to store the frequency of characters
           inside the current window.
        3. Move 'right' forward step-by-step (right++) to expand the window.
        4. If the new character causes a duplicate (frequency > 1),
           shrink the window from the left until the duplicate is removed.
        5. At each step, update the maximum length of the window.

    ▪ Why unordered_map:
        • Faster average-case O(1) for insert, find, and erase compared to map's O(log n).
        • We don't need characters in sorted order, so unordered_map is ideal.

    ▪ Time Complexity:
        • O(N) average case:
            - Each character is visited at most twice (once by 'right', once by 'left').
        • Hash operations are O(1) on average.
        
    ▪ Space Complexity:
        • O(min(N, C)) where C is the character set size (e.g., 256 for ASCII).
          This comes from storing frequency counts for the characters in the window.

    ▪ Example:
        Input:  "abcabcbb"
        Process:
            right=0: window="a" → maxLen=1
            right=1: window="ab" → maxLen=2
            right=2: window="abc" → maxLen=3
            right=3: 'a' repeats → move left to remove old 'a'
            ...
        Output: 3 ("abc")
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Returns the length of the longest substring without repeating characters
int lengthOfLongestUniqueSubstr(const string& s) {
    unordered_map<char, int> freq; // Stores frequency of each character in the window
    int n = s.size();
    int left = 0, right = 0;       // Sliding window boundaries
    int maxLen = 0;                // Track the maximum length found

    // Expand the window by moving 'right' forward
    while (right < n) {
        char c = s[right];
        freq[c]++; // Include current character in the window

        // If 'c' now appears more than once, shrink window from the left
        while (freq[c] > 1) {
            freq[s[left]]--; // Remove leftmost character from window
            left++;          // Move left pointer to the right
        }

        // Update maximum length after fixing duplicates
        maxLen = max(maxLen, right - left + 1);

        // Move right pointer forward to expand the window
        right++;
    }

    return maxLen;
}

int main() {
    string S;
    cout << "Enter the string: ";
    getline(cin, S);

    int result = lengthOfLongestUniqueSubstr(S);
    cout << "Length of the longest substring without repeating characters: "
         << result << "\n";
    return 0;
}
