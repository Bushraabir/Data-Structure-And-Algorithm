/*
    ▪ Purpose: Print all possible subset sums of a given list of integers in increasing order.

    ▪ Step-by-Step Logic:
        • Use a recursive approach based on the "pick / not-pick" pattern.
        • For each element at the current index, you have two choices:
            - Include it in the subset sum.
            - Exclude it from the subset sum.
        • Recursively explore both choices for all elements in the list.
        • When the index reaches the end of the array (base case), store the computed sum.
        • After exploring all subsets, sort the list of sums in increasing order.

    ▪ Time Complexity: O(2^n * n)
        • 2^n combinations of subsets.
        • Each subset sum is stored and then all sums are sorted (log factor included).

    ▪ Space Complexity: O(2^n)
        • To store all subset sums.
        • O(n) additional space for the recursion call stack.

    ▪ Example:
        Input: arr = [3, 1, 2]
        Output (sorted subset sums): [0, 1, 2, 3, 3, 4, 5, 6]

        Subsets and their sums:
        [] → 0
        [3] → 3
        [1] → 1
        [2] → 2
        [3,1] → 4
        [3,2] → 5
        [1,2] → 3
        [3,1,2] → 6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to compute all subset sums
void findSubsetSums(int index, int currentSum, vector<int>& arr, vector<int>& sums) {
    if (index == arr.size()) {
        sums.push_back(currentSum);
        return;
    }

    // Pick the element
    findSubsetSums(index + 1, currentSum + arr[index], arr, sums);

    // Not pick the element
    findSubsetSums(index + 1, currentSum, arr, sums);
}

// Main function to return sorted subset sums
vector<int> subsetSums(vector<int>& arr) {
    vector<int> sums;
    findSubsetSums(0, 0, arr, sums);
    sort(sums.begin(), sums.end());
    return sums;
}


int main() {
    vector<int> arr = {3, 1, 2};
    
    vector<int> result = subsetSums(arr);

    cout << "Subset sums in increasing order:\n";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
