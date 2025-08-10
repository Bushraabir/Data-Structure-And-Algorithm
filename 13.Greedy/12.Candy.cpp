/*
Greedy Algorithm – Candy Distribution to Minimize Total Candies

Intuition & Logic:
- Given ratings of n children.
- Distribute candies such that:
    1. Each child gets at least 1 candy.
    2. Children with higher rating than neighbors get more candies.
- Key insight:
    - Use slopes of ratings: increasing and decreasing sequences.
    - Track lengths of increasing (peak) and decreasing (down) slopes.
    - Handle the peak candy count adjustment where increasing slope transitions to decreasing.
- Approach:
    - Iterate ratings once.
    - For increasing rating, increase peak length and candies.
    - For decreasing rating, increase down length and candies.
    - If down length >= peak length, adjust sum to ensure peak child gets more candies.
    - For equal ratings, reset slopes and assign 1 candy.

Problem Example:
Ratings: [1, 2, 4, 7, 6, 5, 4, 3, 2, 1]
Process:
- Increasing slope 1→2→4→7 with candies increasing 1,2,3,4 (peak=3)
- Then decreasing slope 7→6→5→4→3→2→1 with candies 1,2,3,4,5,6,7 (down=6)
- Peak adjustment adds extra candies so peak child gets enough.

Algorithm:
- Initialize sum_candies=1, peak=0, down=0.
- For i in 1 to n-1:
    - If ratings[i] == ratings[i-1]:
        - Reset peak=down=0; sum_candies +=1.
    - Else if ratings[i] > ratings[i-1]:
        - peak++; down=0; sum_candies += peak + 1.
    - Else (ratings[i] < ratings[i-1]):
        - down++;
        - sum_candies += down;
        - If down >= peak + 1: sum_candies++;
- Return sum_candies.

TIME & SPACE COMPLEXITY:
- Time: O(N), single pass through ratings.
- Space: O(1), constant extra space.

*/

/* -------------------- CANDY DISTRIBUTION IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;

    int sum_candies = 1; // first child gets 1 candy
    int peak = 0;        // length of current increasing slope
    int down = 0;        // length of current decreasing slope
    int prev_slope = 0;  // 1 for up, -1 for down, 0 for flat

    for (int i = 1; i < n; i++) {
        if (ratings[i] == ratings[i - 1]) {
            // Flat slope resets peak and down
            peak = down = 0;
            sum_candies += 1;
            prev_slope = 0;
        } else if (ratings[i] > ratings[i - 1]) {
            // Increasing slope
            peak = peak + 1;
            down = 0;
            sum_candies += peak + 1;
            prev_slope = 1;
        } else {
            // Decreasing slope
            down++;
            sum_candies += down;
            // Adjust peak candy if down >= peak + 1
            if (down >= peak + 1) {
                sum_candies++;
            }
            prev_slope = -1;
        }
    }

    return sum_candies;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> ratings1 = {1, 0, 2};
    vector<int> ratings2 = {1, 2, 2};
    vector<int> ratings3 = {1, 2, 4, 7, 6, 5, 4, 3, 2, 1};

    cout << "Minimum candies for ratings1: " << candy(ratings1) << "\n"; // Expected 5
    cout << "Minimum candies for ratings2: " << candy(ratings2) << "\n"; // Expected 4
    cout << "Minimum candies for ratings3: " << candy(ratings3) << "\n"; // Larger case

    return 0;
}
