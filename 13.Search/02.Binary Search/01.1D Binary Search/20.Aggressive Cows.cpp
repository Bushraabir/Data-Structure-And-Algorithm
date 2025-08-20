// 1. Problem Introduction
// -----------------------
//
// Goal: Place k cows in n stalls such that the **minimum distance between any two cows**
//       is maximized.
//
// Examples:
// - stalls = [0, 3, 4, 7, 10], k = 4
//   * Place at [0, 4, 7, 10] → distances = {4, 3, 3}, min = 3
//   * Place at [0, 3, 4, 7]  → distances = {3, 1, 3}, min = 1
//   → Answer = 3
//
// Constraints:
// - 2 ≤ k ≤ n
// - Stall positions are integers, possibly unsorted
// - Must place **exactly k cows**
// - Need to maximize the minimum distance between any two cows


// 2. Brute Force (Linear Search on Distance)
// ------------------------------------------
//
// Idea:
// - Sort stalls
// - Try all possible minimum distances `dist` from 1 up to (max(stalls) - min(stalls))
// - For each `dist`, check if we can place all k cows with at least `dist` apart
//   using a helper function `canWePlace`.
// - Store the last valid distance.
//
// Helper Function: canWePlace(stalls, dist, k)
// - Place first cow at stalls[0]
// - For each next stall, if stalls[i] - lastCow >= dist, place a cow
// - If cowsPlaced == k → return true
// - Else return false
//
// Example: stalls = [0,3,4,7,10], k=4
// - Try dist = 1 → possible
// - Try dist = 2 → possible
// - Try dist = 3 → possible
// - Try dist = 4 → not possible
// - Answer = 3
//
// Time Complexity: O(N * MaxDist)
// Space Complexity: O(1)


// 3. Optimized Solution (Binary Search on Distance)
// -------------------------------------------------
//
// Key Insight:
// - If we can place cows at distance = X,
//   then we can also place them at distance < X (monotonic property).
// - If we cannot place cows at distance = X,
//   then we also cannot place them at distance > X.
// → Use binary search on answer.
//
// Steps:
// 1. Sort stalls
// 2. low = 1, high = stalls[n-1] - stalls[0]
// 3. while(low <= high):
//      mid = (low + high) / 2
//      if canWePlace(stalls, mid, k) == true:
//          ans = mid   // possible, try larger distance
//          low = mid + 1
//      else:
//          high = mid - 1
// 4. Return ans (or high)
//
// Time Complexity: O(N log(MaxDist))
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

// Helper: Can we place k cows with at least `dist` apart?
bool canWePlace(vector<int>& stalls, int dist, int k) {
    int cows = 1; // first cow at first stall
    int lastPos = stalls[0];

    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - lastPos >= dist) {
            cows++;
            lastPos = stalls[i];
            if(cows >= k) return true;
        }
    }
    return false;
}

// Brute Force: O(N * MaxDist)
int aggressiveCowsBrute(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int maxDist = stalls[n-1] - stalls[0];
    int ans = 0;

    for(int dist = 1; dist <= maxDist; dist++) {
        if(canWePlace(stalls, dist, k)) ans = dist;
        else break;
    }
    return ans;
}

// Optimized Binary Search: O(N log(MaxDist))
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canWePlace(stalls, mid, k)) {
            ans = mid;
            low = mid + 1; // try for larger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }
    return ans;
}


// 4. Example Usage
// ----------------
int main() {
    vector<int> stalls = {0, 3, 4, 7, 10};
    int k = 4;

    cout << "Brute: " << aggressiveCowsBrute(stalls, k) << endl;   // 3
    cout << "Binary Search: " << aggressiveCows(stalls, k) << endl; // 3

    return 0;
}
