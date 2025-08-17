/*
 * Given an array of integers that may contain duplicates, return all possible unique subsets.
 *
 * Example:
 * Input: [1,2,2]
 * Unique subsets:
 *   []
 *   [1]
 *   [2]
 *   [1,2]
 *   [2,2]
 *   [1,2,2]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Brute Force Approach
vector<vector<int>> subsetsWithDup_BruteForce(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> uniqueSubsets;
    
    // Generate all 2^n subsets via bitmasking
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        sort(subset.begin(), subset.end());       // normalize order for set
        uniqueSubsets.insert(subset);             // set removes duplicates
    }
    
    // Convert set back to vector of vectors
    return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
}

/*
 * Optimized Approach:
 *
 * Sort the input and use recursive backtracking with duplicate-skipping logic:
 * - Sort nums so duplicates are adjacent.
 * - At each recursion level, iterate i from start to end.
 * - Skip nums[i] if it's the same as nums[i-1] at the same depth.
 * - Add current path to result at entry of recursive call.
 * - Recurse with i+1, then backtrack.
 *
 * Time complexity: O(2^n * k), where k is average subset size.
 * Space complexity: O(2^n * k) for results + O(n) recursion stack.
 */

// Helper for optimized recursion
void solveWithDup(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
    // Always capture current subset
    ans.push_back(path);
    
    int n = nums.size();
    for (int i = index; i < n; ++i) {
        // Skip duplicates at same recursion depth
        if (i > index && nums[i] == nums[i - 1]) 
            continue;
        
        // Pick nums[i]
        path.push_back(nums[i]);
        solveWithDup(i + 1, nums, path, ans);
        path.pop_back();  // backtrack
    }
}

vector<vector<int>> subsetsWithDup_Optimized(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> path;
    solveWithDup(0, nums, path, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2};
    
    // Brute force result
    auto brute = subsetsWithDup_BruteForce(nums);
    cout << "Brute Force Unique Subsets:\n";
    for (auto& s : brute) {
        cout << "[ ";
        for (int x : s) cout << x << " ";
        cout << "]\n";
    }
    
    // Optimized result
    auto opt = subsetsWithDup_Optimized(nums);
    cout << "\nOptimized Unique Subsets:\n";
    for (auto& s : opt) {
        cout << "[ ";
        for (int x : s) cout << x << " ";
        cout << "]\n";
    }
    
    return 0;
}
