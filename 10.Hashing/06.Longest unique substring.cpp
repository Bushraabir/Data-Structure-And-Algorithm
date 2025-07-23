// File: longest_unique_substring.cpp
/*
Find the length of the longest substring without repeating characters.
You are given a string S. You need to find the maximum length of any
contiguous substring of S in which no character repeats.

Approach:
 1. Use a sliding window with two pointers (left, right).
 2. Maintain an unordered_map<char,int> that stores for each character
    its last index + 1 (to simplify window updates).
 3. As you move the right pointer forward, if S[right] was seen before
    inside the current window (i.e. map[S[right]] >= left), move left
    to map[S[right]].
 4. Update map[S[right]] = right + 1 and compute window length = right - left + 1.
 5. Track the maximum length seen.

Time Complexity: O(N) on average (each character is processed once, and map operations are O(1) average)  
Space Complexity: O(min(N, C)) where C is the size of the character set (e.g., 256 for ASCII)  
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Returns the length of the longest substring without repeating characters
int lengthOfLongestUniqueSubstr(const string& s) {
    unordered_map<char,int> lastPos;
    int maxLen = 0, left = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        char c = s[right];
        // If we've seen c before and it's inside current window, move left
        if (lastPos.find(c) != lastPos.end() && lastPos[c] > left) {
            left = lastPos[c];
        }
        // Update last position of c to right+1
        lastPos[c] = right + 1;
        // Update maximum window size
        maxLen = max(maxLen, right - left + 1);
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
// Time Complexity: O(N) on average (due to sliding window and hash map operations)
// Space Complexity: O(min(N, C)) where C is the character set size (e.g., 256 for ASCII)
