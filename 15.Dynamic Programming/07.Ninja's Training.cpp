/*
Problem Statement:
- A ninja has a training schedule of n days.
- Each day the ninja must do exactly one of three activities:
    0 -> running
    1 -> fighting practice
    2 -> learning new moves
- You are given a 2D array points of size n x 3 where points[i][j] is the merit points
  for doing activity j on day i.
- Constraint: The ninja cannot perform the same activity on two consecutive days.
- Objective: Maximize the total merit points over n days.

Example:
points = {
    {50, 10, 20},   // Day 0
    {5,  100, 11}   // Day 1
}
Greedy picks Day0:50 -> then Day1 best !=50's activity is 11 => total 61 (wrong).
Optimal: pick Day0:10 and Day1:100 => total 110 (correct).
Answer: 110

Why This is a DP Problem:
- We want the maximum total under constraints — optimal substructure applies.
- Overlapping subproblems: same (day, last_activity) states appear multiple times.
- We use DP over states (day, last_activity) where last_activity in {0,1,2,3}
  and 3 denotes "no activity done previously" (initial state).

Recurrence:
Let f(day, last) = maximum points achievable from days [0..day] given that the
activity performed on day+1 (the next day) was 'last'. We compute from day=0 upwards
or from day=n-1 downwards. Using the reversed index approach:

If day == 0:
    f(0, last) = max( points[0][task] ) for all task != last

For day > 0:
    f(day, last) = max over task in {0,1,2} and task != last of
                   points[day][task] + f(day-1, task)

Initial Call (top-down): f(n-1, 3)  // last = 3 means "no restriction"

Time Complexity:
- O(N * 4 * 3) which is O(N) (N days, 4 possible last values, 3 choices each)

Space Complexity:
- Memoization: O(N * 4) + recursion stack O(N)
- Tabulation: O(N * 4)
- Space-optimized: O(4) ~ O(1)
*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int ninjaMemo(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; ++task) {
            if (task == last) continue;
            maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    if (dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for (int task = 0; task < 3; ++task) {
        if (task == last) continue;
        int pointsToday = points[day][task] + ninjaMemo(day - 1, task, points, dp);
        maxi = max(maxi, pointsToday);
    }

    return dp[day][last] = maxi;
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int ninjaTab(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case for day 0
    for (int last = 0; last < 4; ++last) {
        int maxi = 0;
        for (int task = 0; task < 3; ++task) {
            if (task == last) continue;
            maxi = max(maxi, points[0][task]);
        }
        dp[0][last] = maxi;
    }

    // Fill dp for days 1..n-1
    for (int day = 1; day < n; ++day) {
        for (int last = 0; last < 4; ++last) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; ++task) {
                if (task == last) continue;
                int val = points[day][task] + dp[day - 1][task];
                dp[day][last] = max(dp[day][last], val);
            }
        }
    }

    // Answer: no restriction on previous day
    return dp[n - 1][3];
}

/* -------------------- SPACE OPTIMIZED (O(1) extra space) -------------------- */
int ninjaSpaceOpt(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 0) return 0;

    vector<int> prev(4, 0), curr(4, 0);

    // Base case day 0
    for (int last = 0; last < 4; ++last) {
        int maxi = 0;
        for (int task = 0; task < 3; ++task) {
            if (task == last) continue;
            maxi = max(maxi, points[0][task]);
        }
        prev[last] = maxi;
    }

    // Iterate days
    for (int day = 1; day < n; ++day) {
        fill(curr.begin(), curr.end(), 0);
        for (int last = 0; last < 4; ++last) {
            for (int task = 0; task < 3; ++task) {
                if (task == last) continue;
                curr[last] = max(curr[last], points[day][task] + prev[task]);
            }
        }
        prev = curr;
    }

    return prev[3];
}

/* -------------------- MAIN FUNCTION (Demo) -------------------- */
int main() {
    // Example that demonstrates greedy failure:
    vector<vector<int>> points = {
        {50, 10, 20},  // Day 0
        {5,  100, 11}  // Day 1
    };

    int n = points.size();

    // Memoization
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << "Max Points (Memoization): " << ninjaMemo(n - 1, 3, points, dp) << "\n";

    // Tabulation
    cout << "Max Points (Tabulation): " << ninjaTab(points) << "\n";

    // Space Optimized
    cout << "Max Points (Space Optimized): " << ninjaSpaceOpt(points) << "\n";

    return 0;
}
