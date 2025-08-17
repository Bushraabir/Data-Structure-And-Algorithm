/*
Greedy Algorithm – N Meetings in One Room (Maximize Number of Meetings)

Intuition & Logic:
- Given N meetings, each with start and end times.
- Only one meeting room available, so meetings cannot overlap.
- Goal: schedule the maximum number of meetings without overlap.
- Greedy choice:
    - Sort meetings by their earliest finishing time (end time).
    - Always pick the meeting that ends earliest to free the room sooner.
    - This allows scheduling more meetings afterwards.
- This approach guarantees the maximum number of non-overlapping meetings.

Problem Example:
Meetings (sorted by end time):
ID: 1, Start: 1, End: 2
ID: 4, Start: 3, End: 4
ID: 2, Start: 5, End: 7
ID: 3, Start: 8, End: 9
ID: 5, Start: 8, End: 9

Schedule by picking earliest finishing meetings compatible with previous:
- Meeting 1 (ends at 2)
- Meeting 4 (starts 3 ≥ 2)
- Meeting 2 (starts 5 ≥ 4)
- Meeting 3 (starts 8 ≥ 7)
- Meeting 5 (starts 8 overlaps with Meeting 3 end at 9, so cannot pick both)

Max meetings = 4 with order: 1, 4, 2, 3

Algorithm:
- Create meeting objects with start, end, and original index.
- Sort meetings by ascending end time.
- Initialize count = 1 and add first meeting’s index to order list.
- Set freeTime = end time of first meeting.
- For each subsequent meeting:
    - If meeting.start >= freeTime, schedule it:
        - count++, update freeTime to meeting.end.
        - Append meeting index to order list.
- Return count and order list.

TIME & SPACE COMPLEXITY:
- Time: O(N log N) due to sorting.
- Space: O(N) for storing meeting data and result order.

*/

/* -------------------- N MEETINGS IN ONE ROOM IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
    int index; // original position
};

// Comparator to sort meetings by end time ascending
bool cmp(Meeting a, Meeting b) {
    return a.end < b.end;
}

pair<int, vector<int>> maxMeetings(vector<int>& start, vector<int>& end) {
    int n = (int)start.size();
    vector<Meeting> meetings(n);

    // Populate meetings with start, end, and index
    for (int i = 0; i < n; i++) {
        meetings[i] = {start[i], end[i], i + 1}; // 1-based indexing for meeting IDs
    }

    // Sort meetings by their finishing times
    sort(meetings.begin(), meetings.end(), cmp);

    vector<int> order;
    order.push_back(meetings[0].index);
    int count = 1;
    int freeTime = meetings[0].end;

    // Schedule meetings greedily
    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= freeTime) {
            count++;
            freeTime = meetings[i].end;
            order.push_back(meetings[i].index);
        }
    }

    return {count, order};
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> startTimes = {1, 5, 8, 3, 8};
    vector<int> endTimes = {2, 7, 9, 4, 9};

    auto result = maxMeetings(startTimes, endTimes);

    cout << "Maximum meetings scheduled: " << result.first << "\n";
    cout << "Order of meetings: ";
    for (int idx : result.second) {
        cout << idx << " ";
    }
    cout << "\n";

    return 0;
}
