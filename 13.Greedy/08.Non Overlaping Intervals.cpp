/*
Greedy Algorithm – Non Overlapping Intervals (Minimum Removals to Avoid Overlaps)

Intuition & Logic:
- Given N intervals with start and end times.
- Overlap defined strictly: intervals overlap if they intersect except at end = start points.
- Goal: remove minimum intervals so remaining intervals have no overlaps.
- Equivalent to maximizing the number of non-overlapping intervals (like "N Meetings in One Room").
- Greedy choice:
    - Sort intervals by their earliest finishing time (end time).
    - Select intervals that start strictly greater than last selected interval’s end.
    - Maximize count of non-overlapping intervals.
- Minimum removals = total intervals - max count of non-overlapping intervals.

Problem Example:
Intervals (sorted by end time):
[1, 2], [2, 3], [2, 3], [3, 4]

Select non-overlapping intervals:
- [1, 2] (count = 1)
- Skip [2, 3] because start 2 is not > 2
- Skip second [2, 3] same reason
- [3, 4] start 3 > 2, select (count = 2)

Minimum removals = 4 (total) - 2 (max non-overlapping) = 2

Algorithm:
- Create interval objects with start, end.
- Sort intervals by ascending end time.
- Initialize count = 1 (pick first interval).
- Set lastEnd = end time of first interval.
- For each subsequent interval:
    - If interval.start > lastEnd:
        - count++, lastEnd = interval.end.
    - Else skip interval.
- Return total intervals - count as minimum removals.

TIME & SPACE COMPLEXITY:
- Time: O(N log N) due to sorting.
- Space: O(N) for interval storage.

*/

/* -------------------- NON OVERLAPPING INTERVALS IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
};

// Comparator to sort intervals by end time ascending
bool cmp(Interval a, Interval b) {
    return a.end < b.end;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = (int)intervals.size();
    if (n == 0) return 0;

    vector<Interval> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {intervals[i][0], intervals[i][1]};
    }

    // Sort by end time
    sort(arr.begin(), arr.end(), cmp);

    int count = 1;  // count of non-overlapping intervals
    int lastEnd = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start > lastEnd) {  // strictly greater to avoid overlap
            count++;
            lastEnd = arr[i].end;
        }
    }

    // Minimum removals = total intervals - max non-overlapping intervals
    return n - count;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {2, 3}, {3, 4}};

    int minRemovals = eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: " << minRemovals << "\n";  // Output: 2

    return 0;
}
