/*
 * Problem Statement: Nth Root of an Integer
 *
 * You are given two integers 'M' and 'n'. The task is to find and return the integer Nth root of M.
 * That is, find an integer x such that x^n = M.
 * If such an integer exists, return x; otherwise, return -1.
 *
 * Core Concept:
 * - Brute-force: iterate from 1 to M and check i^n == M (O(M*n)), but not optimal for large M.
 * - Optimized solution uses binary search on answers:
 *   - Define search space from 1 to M.
 *   - Use a helper function to check mid^n vs M without causing integer overflow.
 *   - If mid^n == M, return mid.
 *   - If mid^n < M, search right half.
 *   - If mid^n > M, search left half.
 * - Time Complexity: O(log M * n)
 * - Space Complexity: O(1)
 *
 * Examples:
 * M = 27, n = 3
 * Answer = 3
 * M = 69, n = 4
 * Answer = -1
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// HELPER FUNCTION TO COMPARE mid^n WITH M
// ---------------------------
int check(long long mid, int n, long long M) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= mid;
        if (result > M) return 2; // mid^n > M
    }
    if (result == M) return 1;    // mid^n == M
    return 0;                      // mid^n < M
}

// ---------------------------
// FIND NTH ROOT USING BINARY SEARCH
// ---------------------------
int nthRoot(int M, int n) {
    if (M == 0 || M == 1) return M;

    long long low = 1, high = M;
    int answer = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        int res = check(mid, n, M);

        if (res == 1) {
            return mid;       // exact Nth root found
        } else if (res == 0) {
            low = mid + 1;    // mid is too small
        } else {
            high = mid - 1;   // mid is too large
        }
    }

    return -1; // Nth root does not exist
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<pair<int,int>> testCases = {{27, 3}, {69, 4}, {16, 4}, {81, 4}, {1, 5}};

    for (auto &[M, n] : testCases) {
        int root = nthRoot(M, n);
        cout << "Nth root of " << M << " with n = " << n << " is " << root << endl;
    }

    return 0;
}
