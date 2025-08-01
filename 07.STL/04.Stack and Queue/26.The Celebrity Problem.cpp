/*
 * Problem 7: The Celebrity Problem
 *
 * Problem Statement:
 * -------------------
 * Given a group of N people numbered from 0 to N-1, and an N x N matrix 'Matrix' where:
 *   - Matrix[i][j] = 1 means person i knows person j.
 *   - Matrix[i][j] = 0 means person i does NOT know person j.
 *
 * A "celebrity" is defined as:
 *   - Everyone knows the celebrity.
 *   - The celebrity knows no one.
 *
 * Task: Find the celebrity's index if one exists, otherwise return -1.
 *
 * Example:
 * Matrix = [
 *   [0, 1, 0],
 *   [0, 0, 0],
 *   [0, 1, 0]
 * ]
 * Output: 1
 * Explanation: Person 1 knows no one, and persons 0 and 2 know person 1.
 *
 * Intuition:
 * ----------
 * Naive Approach:
 *   - Count how many people know each person and how many each person knows.
 *   - Find a person known by N-1 and who knows 0 people.
 *   - Time complexity O(N^2), space O(N).
 *
 * Optimized Approach (Two Pointers / Elimination):
 *   - Use two pointers 'top' and 'down'.
 *   - If top knows down, top can't be celebrity → top++.
 *   - Else down can't be celebrity → down--.
 *   - After this elimination, one candidate remains.
 *   - Verify candidate by checking if everyone knows them and they know no one.
 *   - Time complexity O(N), space O(1).
 */

#include <iostream>
#include <vector>
using namespace std;

// 7.1 Naive Approach
int findCelebrityNaive(const vector<vector<int>>& Matrix) {
    int N = Matrix.size();
    vector<int> know_me(N, 0);
    vector<int> i_know(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Matrix[i][j] == 1) {
                know_me[j]++;
                i_know[i]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (know_me[i] == N - 1 && i_know[i] == 0)
            return i;
    }

    return -1;
}
// Time Complexity: O(N^2)
// Space Complexity: O(N)


// 7.2 Optimized Two Pointers Approach
int findCelebrityOptimized(const vector<vector<int>>& Matrix) {
    int N = Matrix.size();
    int top = 0, down = N - 1;

    // Step 1: Find candidate
    while (top < down) {
        if (Matrix[top][down] == 1) {
            // top knows down → top can't be celebrity
            top++;
        } else {
            // top does NOT know down → down can't be celebrity
            down--;
        }
    }
    int candidate = top;

    // Step 2: Verify candidate
    for (int i = 0; i < N; i++) {
        if (i == candidate) continue;

        // Candidate should not know anyone
        if (Matrix[candidate][i] == 1) return -1;

        // Everyone should know candidate
        if (Matrix[i][candidate] == 0) return -1;
    }

    return candidate;
}
// Time Complexity: O(N)
// Space Complexity: O(1)


// 7.3 Example Usage
int main() {
    vector<vector<int>> Matrix = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    cout << "Naive Approach Celebrity Index: " << findCelebrityNaive(Matrix) << endl;
    cout << "Optimized Approach Celebrity Index: " << findCelebrityOptimized(Matrix) << endl;

    return 0;
}
