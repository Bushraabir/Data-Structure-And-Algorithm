/*
 * Problem Statement: Number of Substrings Containing All Three Characters
 *
 * You are given a string S consisting only of the characters 'a', 'b', and 'c'.
 * The task is to return the total number of substrings that contain 
 * at least one 'a', one 'b', and one 'c'.
 *
 * Core Concept:
 * - A valid substring must include all three characters: 'a', 'b', and 'c'.
 * - Use Sliding Window / Two Pointers with "last seen index" of each character.
 * - Count substrings ending at each index that are valid.
 *
 * Brute Force Solution (O(N^2)):
 * 1. Use two nested loops: I for the start, J for the end of substring.
 * 2. Maintain a frequency array of size 3 (for 'a','b','c').
 * 3. For each substring S[I...J], check if all three characters exist.
 * 4. If valid, increment count.
 *
 * Time Complexity: O(N^2) 
 * Space Complexity: O(1) (constant 3-element array).
 *
 * Slight Optimization (Still O(N^2) in worst case):
 * - If S[I...J] is valid, then all substrings S[I...J+1], ..., S[I...N-1] are valid.
 * - So instead of counting 1, directly add (N - J) and break inner loop.
 * - Saves time in many cases but not worst-case.
 *
 * Optimal Solution (Sliding Window, O(N)):
 * 1. Maintain an array lastSeen[3] = {-1, -1, -1}, to store last index of 'a','b','c'.
 * 2. Iterate R from 0 to n-1 (end of window):
 *    - Update lastSeen[S[R] - 'a'] = R.
 *    - Find minIndex = min(lastSeen[0], lastSeen[1], lastSeen[2]).
 *    - If all characters seen, substrings ending at R that are valid = minIndex + 1.
 *    - Add this value to count.
 * 3. Return total count.
 *
 * Key Insight:
 * - Every time we extend R, we check the leftmost valid start index for a valid substring.
 * - If minIndex = k, then substrings [0..R], [1..R], ..., [k..R] are all valid.
 *
 * Example:
 * S = "abcabc"
 * Answer = 9
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    vector<int> lastSeen(3, -1); // track last seen indices of 'a','b','c'
    int count = 0;

    for (int R = 0; R < n; R++) {
        lastSeen[s[R] - 'a'] = R;
        int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});

        if (minIndex != -1) { 
            count += (minIndex + 1);
        }
    }
    return count;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    string s = "abcabc";
    cout << "Number of substrings containing all three characters: "
         << numberOfSubstrings(s) << endl;
    return 0;
}
