/*
 * Problem Statement: Minimum Multiplications to Reach End
 *
 * You are given a start number, an end number, and an array of allowed multipliers.
 * At each step, you can multiply the current number by any number from the array
 * and then take modulo 10^5. The goal is to reach the end number using the
 * minimum number of multiplications.
 *
 * Key Observations:
 * - Each number modulo 10^5 can be treated as a node in a graph.
 * - An edge exists from current_node to (current_node * multiplier) % 10^5
 *   for each multiplier. Each edge has a cost of 1 (one multiplication).
 * - BFS ensures the shortest path in terms of number of multiplications.
 *
 * Intuition:
 * 1. Define MOD = 100000.
 * 2. Initialize a distance array 'min_steps' of size MOD with INF; set min_steps[start] = 0.
 * 3. Use a queue to store {current_number, steps_taken}.
 * 4. While the queue is not empty:
 *     a. Dequeue {current_number, steps_taken}.
 *     b. If current_number == end, return steps_taken.
 *     c. For each multiplier in arr:
 *         - Calculate new_number = (current_number * multiplier) % MOD.
 *         - new_steps = steps_taken + 1.
 *         - If new_steps < min_steps[new_number]:
 *             - Update min_steps[new_number] = new_steps.
 *             - Enqueue {new_number, new_steps}.
 * 5. If the end number is never reached, return -1.
 *
 * Time Complexity:
 * - O(MOD * N), where MOD = 10^5 and N is the size of arr.
 *
 * Space Complexity:
 * - O(MOD) for the min_steps array.
 * - O(MOD) for the queue in the worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Minimum Multiplications to Reach End
// ---------------------------
int minimumMultiplications(vector<int>& arr, int start, int end) {
    const int MOD = 100000;
    vector<int> min_steps(MOD, INT_MAX);
    queue<pair<int,int>> q; // {current_number, steps_taken}

    min_steps[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        auto [curr, steps] = q.front(); q.pop();

        if (curr == end) return steps;

        for (int multiplier : arr) {
            int next = (1LL * curr * multiplier) % MOD;
            if (steps + 1 < min_steps[next]) {
                min_steps[next] = steps + 1;
                q.push({next, steps + 1});
            }
        }
    }

    return -1; // unreachable
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;

    int minMultiplications = minimumMultiplications(arr, start, end);
    if (minMultiplications != -1)
        cout << "Minimum multiplications to reach " << end << ": " << minMultiplications << "\n";
    else
        cout << "Cannot reach " << end << " from " << start << "\n";

    return 0;
}
