/*
 * Problem Statement: Minimum Days to Make M Bouquets
 *
 * You are given an array 'bloomDay' where bloomDay[i] is the day the ith flower blooms,
 * and two integers M and K. The task is to find the minimum number of days required to
 * make M bouquets, where each bouquet requires K adjacent bloomed flowers.
 * If it is impossible to make M bouquets, return -1.
 *
 * Core Concept:
 * - Brute-force: Check each day from min(bloomDay) to max(bloomDay) and see if M bouquets can be formed (O((max-min)*n)), inefficient.
 * - Optimized solution uses binary search on the "day" answer:
 *   - Define search space from min(bloomDay) to max(bloomDay).
 *   - Use a helper function checkPossible(day) to see if M bouquets can be formed by that day.
 *   - If possible, search left half to minimize the day.
 *   - If not possible, search right half to wait more days.
 * - Time Complexity: O(n * log(max(bloomDay) - min(bloomDay)))
 * - Space Complexity: O(1)
 *
 * Examples:
 * bloomDay = [1,10,3,10,2], M = 3, K = 1
 * Answer = 3
 * bloomDay = [1,10,3,10,2], M = 3, K = 2
 * Answer = -1
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// HELPER FUNCTION TO CHECK IF M BOUQUETS CAN BE MADE BY 'day'
// ---------------------------
bool checkPossible(const vector<int>& bloomDay, int day, int M, int K) {
    int bouquets = 0, flowers = 0;
    for (int b : bloomDay) {
        if (b <= day) {
            flowers++;
            if (flowers == K) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0; // adjacency broken
        }
    }
    return bouquets >= M;
}

// ---------------------------
// FIND MINIMUM DAYS USING BINARY SEARCH
// ---------------------------
int minDays(vector<int>& bloomDay, int M, int K) {
    long long totalNeeded = (long long)M * K;
    if (totalNeeded > bloomDay.size()) return -1; // impossible case

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (checkPossible(bloomDay, mid, M, K)) {
            answer = mid;      // possible, try to find smaller day
            high = mid - 1;
        } else {
            low = mid + 1;     // not possible, need more days
        }
    }

    return answer;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<pair<vector<int>, pair<int,int>>> testCases = {
        {{1,10,3,10,2}, {3,1}},
        {{1,10,3,10,2}, {3,2}},
        {{7,7,7,7,12,7,7}, {2,3}}
    };

    for (auto &[bloomDay, params] : testCases) {
        int M = params.first;
        int K = params.second;
        int days = minDays(bloomDay, M, K);
        cout << "Minimum days to make " << M << " bouquets with " << K << " adjacent flowers: " << days << endl;
    }

    return 0;
}
