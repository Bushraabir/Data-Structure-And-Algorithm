/*
Greedy Algorithm – Job Sequencing Problem (Maximize Total Profit)
- Given jobs with deadlines and profits, each job takes exactly one day.
- Only one job can be scheduled per day.
- Goal: maximize total profit by scheduling jobs before their deadlines.

Intuition & Logic (Detailed Notes):
1. Greedy Choice:
   - Always pick the job with the highest profit first. This ensures we prioritize high-value work.
   - Place each job in the **latest possible free slot** before its deadline.
     - Why latest? It leaves earlier days available for jobs with tighter deadlines.
   - This simple local decision (highest profit first) leads to a global optimal solution.
2. Steps:
   - Sort jobs by profit descending → ensures greedy selection.
   - Track schedule days with an array, initially all free (-1).
   - For each job, scan backward from its deadline to find a free day.
   - Place the job in the first free slot found, update profit and count.
3. Complexity:
   - Time: O(N log N + N * maxDeadline) → sorting + scanning slots.
   - Space: O(maxDeadline) → schedule array.

Example:
Jobs (sorted by profit):
ID: J6, Profit: 80, Deadline: 2
ID: J3, Profit: 70, Deadline: 6
ID: J4, Profit: 65, Deadline: 6
ID: J2, Profit: 60, Deadline: 5
ID: J5, Profit: 25, Deadline: 4
ID: J8, Profit: 22, Deadline: 2
ID: J1, Profit: 20, Deadline: 4
ID: J7, Profit: 18, Deadline: 2

Schedule by placing each job in the latest free slot before its deadline:
- J6 on day 2
- J3 on day 6
- J4 on day 5
- J2 on day 4
- J5 on day 3
- J8 on day 1
- J1 on day 0 (if indexing from 0)
- J7 cannot be scheduled

Max profit = 342 with 7 jobs scheduled.
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;       // Unique job ID
    int deadline; // Last day the job can be scheduled
    int profit;   // Profit if the job is completed
};

// Comparator: sort jobs by descending profit
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobSequencing(vector<Job>& jobs) {
    int n = (int)jobs.size();

    // Step 1: Sort jobs by profit descending
    sort(jobs.begin(), jobs.end(), cmp);

    // Step 2: Find the maximum deadline to know schedule length
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 3: Initialize schedule array to track free days
    // -1 indicates the day is free
    vector<int> schedule(maxDeadline + 1, -1);

    int totalProfit = 0;
    int jobsCount = 0;

    // Step 4: Schedule jobs using greedy approach
    for (const Job& job : jobs) {
        // Try to schedule job on the latest possible day before its deadline
        for (int day = job.deadline; day > 0; day--) {
            if (schedule[day] == -1) { // Free slot found
                schedule[day] = job.id; // Assign job
                totalProfit += job.profit;
                jobsCount++;
                break; // Job scheduled, move to next
            }
        }
    }

    // Step 5: Return total jobs scheduled and total profit
    return {jobsCount, totalProfit};
}

int main() {
    vector<Job> jobs = {
        {6, 2, 80},
        {3, 6, 70},
        {4, 6, 65},
        {2, 5, 60},
        {5, 4, 25},
        {8, 2, 22},
        {1, 4, 20},
        {7, 2, 18}
    };

    pair<int, int> result = jobSequencing(jobs);

    cout << "Jobs scheduled: " << result.first << "\n";
    cout << "Total profit: " << result.second << "\n";

    return 0;
}