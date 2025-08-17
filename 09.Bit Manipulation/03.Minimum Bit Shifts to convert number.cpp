#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given two positive integers start and goal (goal can be 0),
find the minimum number of bit flips required to convert start into goal.

Core Idea:
- XOR the two numbers: diff = start ^ goal
- Every '1' in diff means a mismatch -> needs one flip.
- So, the problem reduces to counting set bits in diff.
*/

// ----------------------------
// Method 1: Check all 31 bits
// ----------------------------
int countFlips_BitCheck(int start, int goal) {
    int diff = start ^ goal;  // bits that differ
    int count = 0;
    for (int i = 0; i < 31; i++) {
        if (diff & (1 << i)) count++;
    }
    return count;
}

// ----------------------------
// Method 2: Divide by 2 method
// ----------------------------
// Time: O(log(diff))
int countFlips_Division(int start, int goal) {
    int diff = start ^ goal;
    int count = 0;
    while (diff > 0) {
        if (diff % 2 == 1) count++;
        diff /= 2;
    }
    return count;
}

// ----------------------------
// Method 3: Built-in popcount
// ----------------------------
// Uses CPU instruction for efficiency
int countFlips_Builtin(int start, int goal) {
    int diff = start ^ goal;
    return __builtin_popcount(diff);
}

// ----------------------------
// Driver
// ----------------------------
int main() {
    int start1 = 10, goal1 = 7;  // Example 1
    int start2 = 3, goal2 = 4;   // Example 2

    cout << "Example 1: start = " << start1 << ", goal = " << goal1 << "\n";
    cout << "BitCheck: " << countFlips_BitCheck(start1, goal1) << "\n";
    cout << "Division: " << countFlips_Division(start1, goal1) << "\n";
    cout << "Builtin:  " << countFlips_Builtin(start1, goal1) << "\n\n";

    cout << "Example 2: start = " << start2 << ", goal = " << goal2 << "\n";
    cout << "BitCheck: " << countFlips_BitCheck(start2, goal2) << "\n";
    cout << "Division: " << countFlips_Division(start2, goal2) << "\n";
    cout << "Builtin:  " << countFlips_Builtin(start2, goal2) << "\n";

    return 0;
}
