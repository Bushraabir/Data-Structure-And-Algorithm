// 1. Problem Introduction
// -----------------------
//
// Goal: Find the **median** in a row-wise sorted 2D matrix.
//
// Matrix Properties:
// - N x M matrix (both N and M are odd → total elements odd)
// - Each row is sorted in ascending order
//
// Example:
// matrix = {
//   {1, 3, 5},
//   {2, 6, 9},
//   {3, 6, 9}
// }
// Flattened sorted array: {1,2,3,3,5,6,6,9,9}
// Median = 5
//
// Constraints:
// - 1 ≤ N, M ≤ 10^3
// - 1 ≤ matrix[i][j] ≤ 10^9
//
// Equivalent Problems:
// - Median of 1D sorted array (generalized to 2D)
// - Binary search on answer

#include <bits/stdc++.h>
using namespace std;

// Helper: Count number of elements <= x in a row using upper_bound
int countSmallerEquals(vector<int>& row, int x) {
    return upper_bound(row.begin(), row.end(), x) - row.begin();
}

// 2. Brute Force (Flatten & Sort)
// -------------------------------
//
// Idea:
// - Flatten the 2D matrix into a 1D array
// - Sort the array and return middle element
//
// Time Complexity: O(N*M * log(N*M))
// Space Complexity: O(N*M)
int findMedianBrute(vector<vector<int>>& matrix) {
    vector<int> all;
    for(auto &row : matrix)
        for(int val : row)
            all.push_back(val);

    sort(all.begin(), all.end());
    return all[all.size()/2];
}

// 3. Most Optimized (Binary Search on Answer)
// -------------------------------------------
//
// Idea:
// - Apply binary search on the range of possible values (1 to 10^9)
// - At each mid value, count elements <= mid using row-wise binary search
// - Adjust search space to find the smallest number such that
//   count of elements <= mid > N*M/2 (middle index)
//
// Time Complexity: O(log(MaxVal) * N * log M)
// Space Complexity: O(1)
int findMedianBinarySearch(vector<vector<int>>& matrix) {
    int N = matrix.size(), M = matrix[0].size();
    int low = 1, high = 1e9;
    int required = (N*M)/2;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        int count = 0;
        for(int i=0; i<N; i++)
            count += countSmallerEquals(matrix[i], mid);

        if(count <= required) {
            low = mid + 1; // median is larger
        } else {
            ans = mid;     // potential median
            high = mid - 1; // try smaller value
        }
    }
    return ans;
}

// 4. Example Usage
// ----------------
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Brute Force Median: " << findMedianBrute(matrix) << endl;         // 5
    cout << "Binary Search Median: " << findMedianBinarySearch(matrix) << endl; // 5

    return 0;
}
