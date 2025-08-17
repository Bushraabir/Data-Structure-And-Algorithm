#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given an integer array nums of unique elements,
return all possible subsets (the power set).

Approach (Bitmask / Power Set):
- There are 2^n subsets for an array of size n.
- For each number 'mask' in [0, 2^n - 1]:
    - Use binary representation of 'mask' to decide
      which elements to include in the current subset.
- Example: nums = [1,2,3]
    mask = 5 -> binary 101 -> take nums[0], nums[2] -> subset {1,3}
*/

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int num_subsets = 1 << n;  // 2^n
    vector<vector<int>> ans;

    for (int mask = 0; mask < num_subsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // if ith bit is set
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subset);
    }

    return ans;
}

// -------------------
// Driver
// -------------------
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "All subsets:\n";
    for (auto &subset : result) {
        cout << "{ ";
        for (auto &x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
