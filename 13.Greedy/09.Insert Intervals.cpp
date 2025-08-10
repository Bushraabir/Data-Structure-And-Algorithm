/*
Greedy Algorithm – Insert Interval (Merge Intervals After Insertion)

Intuition & Logic:
- Given a sorted, non-overlapping array of intervals and a new interval.
- Insert the new interval into the array while maintaining order and no overlaps.
- Overlapping intervals (including the new one) are merged into a single interval.
- Approach:
    - Iterate through intervals and add all intervals that end before newInterval starts (left part).
    - Merge all intervals overlapping with newInterval by expanding newInterval’s boundaries.
    - Add the merged newInterval.
    - Add all remaining intervals that start after newInterval ends (right part).
- This preserves sorting and ensures no overlaps.

Problem Example:
Intervals: [1,2], [3,4], [5,8], [8,10], [12,16]
New Interval: [6,8]

Process:
- Left: [1,2], [3,4] (end < 6)
- Overlap & Merge: [5,8], [8,10] overlap with [6,8] → merge into [5,10]
- Right: [12,16] (start > 10)
Result: [1,2], [3,4], [5,10], [12,16]

Algorithm:
- Initialize result list.
- Iterate intervals:
    - Add intervals ending before newInterval.start to result.
    - Merge overlapping intervals with newInterval.
    - Add merged newInterval.
    - Add remaining intervals.
- Return result.

TIME & SPACE COMPLEXITY:
- Time: O(N), as each interval is processed once.
- Space: O(N), for the resulting merged intervals list.

*/

/* -------------------- INSERT INTERVAL IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
};

vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    int i = 0, n = (int)intervals.size();

    // Left section: intervals ending before newInterval starts
    while (i < n && intervals[i].end < newInterval.start) {
        result.push_back(intervals[i]);
        i++;
    }

    // Middle section: merge overlapping intervals with newInterval
    while (i < n && intervals[i].start <= newInterval.end) {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }
    // Add merged interval
    result.push_back(newInterval);

    // Right section: intervals starting after newInterval ends
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<Interval> intervals = {{1, 2}, {3, 4}, {5, 8}, {8, 10}, {12, 16}};
    Interval newInterval = {6, 8};

    vector<Interval> merged = insertInterval(intervals, newInterval);

    cout << "Merged intervals after insertion:\n";
    for (auto &interval : merged) {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    cout << "\n";

    return 0;
}
