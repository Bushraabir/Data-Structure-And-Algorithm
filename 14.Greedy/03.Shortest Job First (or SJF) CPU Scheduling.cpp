/*
Greedy Algorithm – Shortest Job First (SJF) CPU Scheduling

Intuition & Logic:
- Given N processes with known execution times, all arriving at time 0 simultaneously.
- Goal: Schedule processes to minimize average waiting time.
- SJF scheduling always picks the shortest job next, a greedy strategy to reduce waiting.
- Sort processes by execution time in ascending order.
- Waiting time for a process = total execution time of all previous processes.
- Sum all waiting times, then divide by N for average.
- Return the truncated integer value of the average waiting time.

Problem Example:
- Processes (execution times): 4, 3, 7, 1, 2

Sorted:
- 1, 2, 3, 4, 7

Calculations:
- Process 1 (1 unit): wait = 0, total wait = 0, timer = 1
- Process 2 (2 units): wait = 1, total wait = 1, timer = 3
- Process 3 (3 units): wait = 3, total wait = 4, timer = 6
- Process 4 (4 units): wait = 6, total wait = 10, timer = 10
- Process 5 (7 units): wait = 10, total wait = 20, timer = 17

Average waiting time = 20 / 5 = 4 (truncated)

Algorithm:
- Sort execution times.
- Initialize timer = 0, total_wait = 0.
- For each process:
    - Add current timer to total_wait (waiting time for this process).
    - Update timer by adding current process execution time.
- Return total_wait / N (integer division).

TIME & SPACE COMPLEXITY:
- Time: O(N log N) due to sorting.
- Space: O(1) extra space (sorting in-place).

*/

/* -------------------- SJF CPU SCHEDULING IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

int averageWaitingTime(vector<int>& processes) {
    sort(processes.begin(), processes.end());
    int timer = 0;
    int total_wait = 0;

    for (int time : processes) {
        total_wait += timer;  // waiting time for current process
        timer += time;        // update timer to include this process execution
    }

    return total_wait / (int)processes.size(); // truncated average waiting time
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> processes = {4, 3, 7, 1, 2};
    cout << "Average Waiting Time: " << averageWaitingTime(processes) << "\n"; // Output: 4

    return 0;
}
