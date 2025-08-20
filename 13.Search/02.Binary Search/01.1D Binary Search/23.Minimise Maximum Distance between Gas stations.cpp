// 1. Problem Introduction
// -----------------------
//
// Goal: Place `k` new gas stations along a road (with existing stations)
//       such that the **maximum distance between any two consecutive stations
//       is minimized**.
//
// Equivalent Problems:
// - Minimize Maximum Distance to Gas Stations
//
// Rules:
// - Existing stations are fixed, given in sorted order
// - New stations can be placed at decimal positions
// - Stations must be between the first and last existing stations
//
// Example:
// stations = [1, 5], k = 2
// - Place at 2.5 and 3.5
// - Final stations = [1, 2.5, 3.5, 5]
// - Gaps = [1.5, 1, 1.5] → max = 1.5
// → Answer = 1.5
//
// Constraints:
// - 2 ≤ n ≤ 10^5
// - 1 ≤ stations[i] ≤ 10^9
// - 1 ≤ k ≤ 10^5
// - Answer within 1e-6 precision


// 2. Brute Force (Greedy O(k * n))
// ---------------------------------
//
// Idea:
// - Always break the **largest gap** by adding a station
// - Track for each segment how many new stations are already placed
// - Effective gap = original_length / (parts = newStations+1)
// - Repeat k times, placing in the worst segment
//
// Time Complexity: O(k * n)
// Space Complexity: O(n)


#include <bits/stdc++.h>
using namespace std;

// Brute force
long double minimizeMaxDistanceBrute(vector<int>& stations, int k) {
    int n = stations.size();
    vector<int> howMany(n - 1, 0);

    for(int gas = 0; gas < k; gas++) {
        long double maxLen = -1;
        int idx = -1;

        for(int i = 0; i < n - 1; i++) {
            long double length = (long double)(stations[i+1] - stations[i]) / (howMany[i] + 1);
            if(length > maxLen) {
                maxLen = length;
                idx = i;
            }
        }
        howMany[idx]++;
    }

    long double ans = -1;
    for(int i = 0; i < n - 1; i++) {
        long double length = (long double)(stations[i+1] - stations[i]) / (howMany[i] + 1);
        ans = max(ans, length);
    }
    return ans;
}


// 3. Optimized Solution (Priority Queue O(k log n))
// -------------------------------------------------
//
// Key Insight:
// - Use a max-heap to avoid scanning all segments each time
// - Each time, pop the current largest gap, place a station, and push back
//
// Time Complexity: O((n + k) log n)
// Space Complexity: O(n)


struct Segment {
    long double length;
    int index;
    bool operator<(const Segment& other) const {
        return length < other.length; // max-heap
    }
};

long double minimizeMaxDistancePQ(vector<int>& stations, int k) {
    int n = stations.size();
    priority_queue<Segment> pq;
    vector<int> howMany(n - 1, 0);

    for(int i = 0; i < n - 1; i++) {
        pq.push({(long double)(stations[i+1] - stations[i]), i});
    }

    for(int gas = 0; gas < k; gas++) {
        Segment seg = pq.top(); pq.pop();
        int idx = seg.index;
        howMany[idx]++;
        long double newLen = (long double)(stations[idx+1] - stations[idx]) / (howMany[idx] + 1);
        pq.push({newLen, idx});
    }
    return pq.top().length;
}


// 4. Most Optimal (Binary Search on Answer)
// ------------------------------------------
//
// Key Insight:
// - The answer lies between 0 and max initial gap
// - Monotonic property:
//   * If distance X works, any > X also works
//   * If distance X doesn’t work, any < X also doesn’t work
// - Use binary search on floating point range
//
// Helper: isPossible(mid)
// - For each gap, compute required stations = ceil(gap/mid) - 1
// - Sum them → if ≤ k, then feasible
//
// Time Complexity: O(n log(maxGap/precision))
// Space Complexity: O(1)


bool isPossible(vector<int>& stations, int k, long double dist) {
    int n = stations.size();
    int needed = 0;

    for(int i = 0; i < n - 1; i++) {
        long double gap = stations[i+1] - stations[i];
        int count = (int)ceil(gap / dist) - 1;
        needed += count;
        if(needed > k) return false;
    }
    return true;
}

long double minimizeMaxDistanceBS(vector<int>& stations, int k) {
    int n = stations.size();
    long double low = 0, high = 0;
    for(int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(stations[i+1] - stations[i]));
    }

    while(high - low > 1e-7) {
        long double mid = (low + high) / 2.0;
        if(isPossible(stations, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}


// 5. Example Usage
// ----------------
int main() {
    vector<int> stations = {1, 5};
    int k = 2;

    cout << fixed << setprecision(6);
    cout << "Brute: " << minimizeMaxDistanceBrute(stations, k) << endl;   // 1.500000
    cout << "Heap: " << minimizeMaxDistancePQ(stations, k) << endl;      // 1.500000
    cout << "Binary Search: " << minimizeMaxDistanceBS(stations, k) << endl; // 1.500000

    return 0;
}
