/*
Combination Sum I (Leetcode 39)

You are given a list of distinct integers called `candidates` and a target integer `target`.

Your task is to find and return **all unique combinations** of `candidates` where the chosen numbers sum up to `target`.

**Important Notes:**
- You may use each number from `candidates` **an unlimited number of times**.
- The combinations should not contain duplicate sets.
- The order of numbers inside a combination doesn't matter, but the overall list of combinations must not have duplicates.

Example:
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2,2,3],[7]]
Explanation:
  - 2+2+3 = 7
  - 7 = 7
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Approach:
This uses recursion with the "pick and not pick" ("take or not take") approach.

Key Parameters:
- index → current index in the `candidates` array
- target → remaining sum we need to reach
- ds → current combination being built (vector<int>)
- ans → stores all valid combinations (vector<vector<int>>)

Rules:
1. "Pick" → include current element, reduce target, and **stay at same index** (since reuse is allowed)
2. "Not Pick" → skip current element, move to next index
3. Base Case:
    - If target == 0 → valid combination found → add to ans
    - If index == n or target < 0 → invalid → return
*/

void combinationSumHelper(int index, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    // Base case: target matched
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    // Base case: reached end of array or exceeded target
    if (index == arr.size() || target < 0) {
        return;
    }

    // Pick the current element (stay at index)
    if (arr[index] <= target) {
        ds.push_back(arr[index]);
        combinationSumHelper(index, target - arr[index], arr, ds, ans);
        ds.pop_back(); // backtrack
    }

    // Not pick the current element (move to index + 1)
    combinationSumHelper(index + 1, target, arr, ds, ans);
 }

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    combinationSumHelper(0, target, arr, ds, ans);
    return ans;
}  

int main() {
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(arr, target);

    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto& comb : result) {
        cout << "{ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
