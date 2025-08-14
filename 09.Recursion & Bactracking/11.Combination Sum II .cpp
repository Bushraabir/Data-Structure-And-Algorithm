/*
    ▪ Purpose: Find all unique combinations in a given array where each number can be used only once, 
               and the combination sum equals a target value.

    ▪ Step-by-Step Logic:
        • Sort the input array to simplify handling duplicates and to allow pruning.
        • Use a recursive backtracking function to explore combinations.
        • At each step in the recursion:
            - If the target becomes 0, a valid combination is found; add it to the result.
            - If the target is negative or the index goes out of bounds, return (invalid path).
        • Iterate through the array starting from the current index:
            - Skip duplicate elements at the same recursive depth using:
              `if (i > index && candidates[i] == candidates[i-1]) continue;`
            - If the current candidate exceeds the target, break early (pruning).
            - Choose the current element, recurse with updated target and index + 1.
            - After recursion, backtrack by removing the last chosen element.

    ▪ Time Complexity: O(2^N * k)
        - 2^N possible subsets in the worst case.
        - k is the average length of valid combinations being copied to the result list.

    ▪ Space Complexity: O(k * X)
        - k: average size of a combination.
        - X: total number of unique combinations.
        - Additional space used in recursion stack.

    ▪ Example:
        Input: candidates = [10,1,2,7,6,1,5], target = 8
        Output:
        [
            [1,1,6],
            [1,2,5],
            [1,7],
            [2,6]
        ]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void findCombinations(int index, int target, vector<int>& arr, 
                      vector<int>& ds, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < arr.size(); i++) { // to explore all possible candidates starting from the current index — but not before it
        // Skip duplicates at the same recursion depth
        if (i > index && arr[i] == arr[i - 1]) continue;

        // If current number exceeds target, break (prune)
        if (arr[i] > target) break;

        // Pick the current number
        ds.push_back(arr[i]);
        
        // Recurse with next index (each number can be used once)
        findCombinations(i + 1, target - arr[i], arr, ds, ans);
        
        // Backtrack
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());  // Sort input for duplicate handling and pruning
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(0, target, arr, current, result);
    return result;
}


int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> combinations = combinationSum2(candidates, target);

    cout << "Unique combinations summing to " << target << ":\n";
    for (const auto& comb : combinations) {
        cout << "[ ";
        for (int num : comb)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
