
/*
 * Given an array of distinct integers, return all possible permutations.
 *
 * Example:
 * Input: [1,2,3]
 * Permutations:
 *   [1,2,3]
 *   [1,3,2]
 *   [2,1,3]
 *   [2,3,1]
 *   [3,1,2]
 *   [3,2,1]
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ---------------- Brute Force Approach ----------------
/*
 * Intuition:
 *   • We maintain a 'used' array to mark which elements have already been placed
 *     in the current partial permutation ('path').
 *   • At each recursive call, we try to pick any unused element and append it to 'path'.
 *   • Once 'path' has length N, we've formed a complete permutation—add it to 'ans'.
 *   • Backtracking: after returning, we unmark the element and remove it from 'path'
 *     so other elements can take its place in different positions.
 */



void permute_BruteForce_Helper(const vector<int>& nums,vector<bool>& used,vector<int>& path,vector<vector<int>>& ans) {
    int n = nums.size();
    // Base case: if we've picked N elements, record the permutation
    if (path.size() == n) {
        ans.push_back(path);
        return;
    }
    // Try every element that hasn't been used yet
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;        // skip already-used elements
        used[i] = true;               // mark as used
        path.push_back(nums[i]);      // include in current permutation

        permute_BruteForce_Helper(nums, used, path, ans);

        // backtrack: remove and unmark so we can try a different choice here
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute_BruteForce(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    permute_BruteForce_Helper(nums, used, path, ans);
    return ans;
}

// ---------------- Optimized Swapping Approach ----------------
/*
 * Intuition:
 *   • Instead of a separate 'used' array, we generate permutations in-place:
 *     we swap the current index with each index >= current to fix one element at
 *     the current position, then recurse to fill the next position.
 *   • After recursion, we swap back to restore the original order (backtracking).
 *   • This way, every element will be moved into each position exactly once.
 */

 
void permute_Optimized_Helper(int index, vector<int>& nums, vector<vector<int>>& ans) {
    int n = nums.size();
    // Base case: index == n means all positions are fixed, record the permutation
    if (index == n) {
        ans.push_back(nums);
        return;
    }
    // For each candidate to place at 'index'
    for (int i = index; i < n; ++i) {
        swap(nums[index], nums[i]);           // place nums[i] into position 'index'
        permute_Optimized_Helper(index + 1, nums, ans);
        swap(nums[index], nums[i]);           // backtrack: restore original order
    }
}

vector<vector<int>> permute_Optimized(vector<int>& nums) {
    vector<vector<int>> ans;
    permute_Optimized_Helper(0, nums, ans);
    return ans;
}


int main() {
    vector<int> nums = {1, 2, 3};

    // Compute with brute force
    auto brute = permute_BruteForce(nums);
    cout << "Brute Force Permutations:\n";
    for (auto& p : brute) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "]\n";
    }

    // Compute with optimized swapping
    auto opt = permute_Optimized(nums);
    cout << "\nOptimized Permutations:\n";
    for (auto& p : opt) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
