/*
 * Problem Statement: Floor of Square Root of a Number
 *
 * You are given a non-negative integer 'n'. The task is to find and return the floor of its square root.
 * The floor of the square root is the largest integer x such that x*x <= n.
 *
 * Core Concept:
 * - Brute-force: iterate from 1 upwards and check i*i <= n (O(N)).
 * - Optimized solution uses binary search on answers:
 *   - Define search space from 0 to n.
 *   - If mid*mid <= n, store mid as possible answer and search right half.
 *   - If mid*mid > n, search left half.
 *   - Use long long for mid*mid to prevent integer overflow.
 * - Time Complexity: O(log N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * n = 25
 * Answer = 5
 * n = 30
 * Answer = 5
 * n = 36
 * Answer = 6
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// FIND FLOOR OF SQUARE ROOT USING BINARY SEARCH
// ---------------------------
int floorSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int low = 1, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            return mid;
        } else if (sq < n) {
            ans = mid;       // mid is a possible answer
            low = mid + 1;   // try to find a larger square root
        } else {
            high = mid - 1;  // mid*mid > n, look in left half
        }
    }

    return ans; // floor of sqrt(n)
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> testCases = {25, 30, 35, 36};

    for (int n : testCases) {
        int sqrtFloor = floorSqrt(n);
        cout << "Floor of sqrt(" << n << ") = " << sqrtFloor << endl;
    }

    return 0;
}
