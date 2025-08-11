#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
DP 42 — Printing the Longest Increasing Subsequence (Tabulation)
--------------------------------------------------------------
1. DP Definition:
--------------------------------------------------------------
dp[i] = length of the Longest Increasing Subsequence that **ends** at index i.

Why “ends at i”?
- Because this allows us to build solutions incrementally:
  If nums[j] < nums[i], then nums[i] can extend the LIS ending at j.

--------------------------------------------------------------
2. Initialization:
--------------------------------------------------------------
- Every element itself is an LIS of length 1.
- So: dp[i] = 1 for all i.
- We also keep a `hash[i]` array to remember the previous index
  of the element that comes before nums[i] in the LIS ending at i.

Initially:
- hash[i] = i (means "I am the start of my own subsequence").

--------------------------------------------------------------
3. Transition:
--------------------------------------------------------------
For each index i from 0 to n-1:
    For each j from 0 to i-1:
        If nums[j] < nums[i] (strictly increasing condition):
            If 1 + dp[j] > dp[i]:
                dp[i] = 1 + dp[j]
                hash[i] = j  // store parent index

Why max?
- We want the *longest* subsequence that ends at i.

--------------------------------------------------------------
4. Tracking LIS Length and End Position:
--------------------------------------------------------------
- Keep `max_length` to store maximum LIS length found so far.
- Keep `last_index` to store the index where that LIS ends.

--------------------------------------------------------------
5. Backtracking to Print LIS:
--------------------------------------------------------------
- Start from last_index, add nums[last_index] to a temp vector.
- Move to hash[last_index].
- Stop when index == hash[index] (start element).
- Reverse the collected vector to get the LIS in correct order.

--------------------------------------------------------------
6. Complexity:
--------------------------------------------------------------
Time: O(N²)  — nested loops
Space: O(N)  — dp[] and hash[] arrays
--------------------------------------------------------------
*/

vector<int> printLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);    // dp[i] = LIS length ending at i
    vector<int> hash(n);     // hash[i] = previous index in LIS ending at i

    // Initialize hash[i] to itself
    for (int i = 0; i < n; i++) {
        hash[i] = i;
    }

    int max_length = 1;      // At least 1 element in LIS
    int last_index = 0;      // Will store where LIS ends

    // Build dp table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                hash[i] = j;  // Link to previous element in LIS
            }
        }

        // Update LIS info if we found a longer subsequence
        if (dp[i] > max_length) {
            max_length = dp[i];
            last_index = i;
        }
    }

    // Backtrack to build the LIS
    vector<int> lis;
    lis.push_back(nums[last_index]);
    while (hash[last_index] != last_index) {
        last_index = hash[last_index];
        lis.push_back(nums[last_index]);
    }

    reverse(lis.begin(), lis.end()); // reverse to get correct order
    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    vector<int> lis = printLIS(nums);

    cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of LIS: " << lis.size() << endl;

    return 0;
}


