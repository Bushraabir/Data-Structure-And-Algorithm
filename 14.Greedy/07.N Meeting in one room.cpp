/*
Greedy Algorithm – N Meetings in One Room (Maximize Number of Meetings)
- Given N meetings, each with start and end times.
- Only one meeting room available, so meetings cannot overlap.
- Goal: schedule the maximum number of meetings without overlap.

Intuition & Logic (Detailed Notes):
1. Greedy Choice:
   - Always pick the meeting that **finishes earliest**. Why?
     - Picking earliest finishing meetings frees the room sooner for future meetings.
     - This local decision ensures globally maximum meetings can be scheduled.
   - Sort all meetings by ascending end time to facilitate greedy selection.
2. Steps:
   - Create Meeting objects with start, end, and original index.
   - Sort meetings by end time.
   - Initialize:
     - count = 1 (first meeting always picked)
     - freeTime = end time of first meeting
     - order list = store scheduled meeting indices
   - Iterate over remaining meetings:
     - If meeting.start >= freeTime → schedule it
       - Increment count, update freeTime = meeting.end
       - Append meeting index to order
3. Complexity:
   - Time: O(N log N) → sorting dominates
   - Space: O(N) → storing meetings and result order

Example:
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
- Meeting 5 overlaps with Meeting 3 → cannot pick

Max meetings = 4 with order: 1, 4, 2, 3
*/

#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;  // Meeting start time
    int end;    // Meeting end time
    int index;  // Original position (1-based ID)
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
        meetings[i] = {start[i], end[i], i + 1}; // 1-based indexing
    }

    // Step 1: Sort meetings by their finishing times
    sort(meetings.begin(), meetings.end(), cmp);

    vector<int> order;
    // Pick first meeting
    order.push_back(meetings[0].index);
    int count = 1;
    int freeTime = meetings[0].end;

    // Step 2: Schedule remaining meetings greedily
    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= freeTime) {
            count++;
            freeTime = meetings[i].end;
            order.push_back(meetings[i].index);
        }
    }

    return {count, order};
}


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