/*
Greedy Algorithm – Job Sequencing Problem (Maximize Total Profit)

Intuition & Logic:
- Given jobs with deadlines and profits, each job takes exactly one day.
- Only one job can be scheduled per day.
- Goal: maximize total profit by scheduling jobs before their deadlines.
- Greedy choice:
    - Sort jobs by descending profit to prioritize high-profit jobs.
    - For each job, schedule it on the latest available day before its deadline.
    - Scheduling jobs as late as possible frees earlier days for other jobs with tighter deadlines.
- This approach ensures maximum total profit and maximum jobs done.

Problem Example:
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

Algorithm:
- Sort jobs in descending order by profit.
- Find maxDeadline among jobs.
- Initialize schedule array (size maxDeadline+1) with -1 (indicating free day).
- For each job in sorted order:
    - Check from job.deadline down to day 1 for a free slot.
    - If free slot found, assign job and update total profit and count.
- Return total jobs scheduled and total profit.

TIME & SPACE COMPLEXITY:
- Time: O(N log N + N * maxDeadline), due to sorting and scheduling.
- Space: O(maxDeadline), for the schedule array.

*/

/* -------------------- JOB SEQUENCING IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator to sort jobs by descending profit
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobSequencing(vector<Job>& jobs) {
    int n = (int)jobs.size();

    // Step 1: Sort jobs by profit descending
    sort(jobs.begin(), jobs.end(), cmp);

    // Step 2: Find max deadline
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 3: Initialize schedule array to track free days (-1 means free)
    vector<int> schedule(maxDeadline + 1, -1);

    int totalProfit = 0;
    int jobsCount = 0;

    // Step 4: Schedule jobs
    for (const Job& job : jobs) {
        // Try to schedule job on latest possible day before deadline
        for (int day = job.deadline; day > 0; day--) {
            if (schedule[day] == -1) {
                schedule[day] = job.id;
                totalProfit += job.profit;
                jobsCount++;
                break; // Job scheduled, move to next
            }
        }
    }

    return {jobsCount, totalProfit};
}

/* -------------------- MAIN FUNCTION -------------------- */

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
