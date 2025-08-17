/*
Greedy Algorithm – Minimum Number of Platforms Required in a Railway Station

Intuition & Logic:
- Given arrival and departure times of N trains.
- Need minimum number of platforms so that no two trains overlap on the same platform.
- Key insight: minimum platforms = maximum number of trains at station simultaneously.
- Approach:
    - Sort arrivals and departures separately.
    - Use two pointers to traverse arrivals and departures.
    - Increment platform count when a train arrives.
    - Decrement platform count when a train departs.
    - Track the maximum platforms needed at any point.

Problem Example:
Arrivals (sorted):   [900, 945, 955, 1100, 1500, 1800]
Departures (sorted): [920, 1130, 1150, 1200, 1900, 2000]

Process:
- Compare arrival and departure times in order.
- Increment platform on arrival <= current departure.
- Decrement platform on arrival > current departure.
- Max concurrent platforms = 3.

Algorithm:
- Sort arrival and departure arrays.
- Initialize i = 0, j = 0, currentPlatforms = 0, maxPlatforms = 0.
- While i < N:
    - If arrival[i] <= departure[j]:
        - currentPlatforms++, i++
        - maxPlatforms = max(maxPlatforms, currentPlatforms)
    - Else:
        - currentPlatforms--, j++
- Return maxPlatforms.

TIME & SPACE COMPLEXITY:
- Time: O(N log N) due to sorting.
- Space: O(1) if sorting in place, else O(N).

*/

/* -------------------- MINIMUM PLATFORM IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int>& arrivals, vector<int>& departures) {
    int n = arrivals.size();
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    int i = 0, j = 0;
    int currentPlatforms = 0, maxPlatforms = 0;

    while (i < n && j < n) {
        if (arrivals[i] <= departures[j]) {
            currentPlatforms++;
            maxPlatforms = max(maxPlatforms, currentPlatforms);
            i++;
        } else {
            currentPlatforms--;
            j++;
        }
    }
    return maxPlatforms;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> arrivals = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departures = {920, 1130, 1150, 1200, 1900, 2000};

    int platforms = minPlatforms(arrivals, departures);
    cout << "Minimum number of platforms required: " << platforms << "\n";  // Output: 3

    return 0;
}
