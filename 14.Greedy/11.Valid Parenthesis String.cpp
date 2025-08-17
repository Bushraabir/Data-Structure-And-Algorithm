/*
Greedy Algorithm – Valid Parenthesis String with Asterisks

Intuition & Logic:
- Given a string with '(', ')', and '*'.
- '*' can represent '(', ')' or empty string.
- Need to check if there's any replacement of '*' that makes the string valid.
- Key idea:
    - Track a range [minOpen, maxOpen] of possible open parentheses count at each step.
    - '(' increments both minOpen and maxOpen.
    - ')' decrements both minOpen and maxOpen.
    - '*' decrements minOpen (treat as ')') and increments maxOpen (treat as '(').
    - Clamp minOpen to 0 since negative means invalid state.
    - If maxOpen < 0 at any time, return false immediately.
- At end, if minOpen == 0, the string can be validly balanced.

Problem Example:
Input: "(*))"
Process:
- '(' : minOpen=1, maxOpen=1
- '*' : minOpen=0, maxOpen=2
- ')' : minOpen=-1→clamped to 0, maxOpen=1
- ')' : minOpen=-1→clamped to 0, maxOpen=0
Result: minOpen=0 → valid

Algorithm:
- Initialize minOpen=0, maxOpen=0.
- Iterate characters:
    - If '(': minOpen++, maxOpen++.
    - If ')': minOpen--, maxOpen--.
    - If '*': minOpen--, maxOpen++.
    - Clamp minOpen = max(minOpen, 0).
    - If maxOpen < 0, return false.
- Return (minOpen == 0).

TIME & SPACE COMPLEXITY:
- Time: O(N), single pass through the string.
- Space: O(1), constant extra space.

*/

/* -------------------- VALID PARENTHESIS STRING IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

bool checkValidString(const string& s) {
    int minOpen = 0, maxOpen = 0;

    for (char c : s) {
        if (c == '(') {
            minOpen++;
            maxOpen++;
        } else if (c == ')') {
            minOpen--;
            maxOpen--;
        } else { // c == '*'
            minOpen--;   // treat '*' as ')'
            maxOpen++;   // treat '*' as '('
        }

        minOpen = max(minOpen, 0);
        if (maxOpen < 0) return false;
    }

    return minOpen == 0;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<string> tests = {"()", ")", "(*)", "((*)", "((("};

    for (auto &test : tests) {
        cout << "Input: " << test << " -> ";
        cout << (checkValidString(test) ? "Valid" : "Invalid") << "\n";
    }

    return 0;
}
