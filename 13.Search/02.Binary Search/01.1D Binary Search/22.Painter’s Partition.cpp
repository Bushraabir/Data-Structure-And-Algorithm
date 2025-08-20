// 1. Problem Introduction
// -----------------------
//
// Goal: Split an array of size `n` into `k` parts such that the
//       **maximum sum of any part is minimized**.
//
// Equivalent Problems:
// - Allocate Books
// - Painter’s Partition
// - Split Array Largest Sum
//
// Rules:
// - Each part must have at least one element
// - Each element must belong to exactly one part
// - Allocation must be contiguous (no skipping elements)
//
// Example: arr = [10, 20, 30, 40], k = 2
// - Allocation 1: [10] | [20, 30, 40] → max = 90
// - Allocation 2: [10, 20] | [30, 40] → max = 70
// - Allocation 3: [10, 20, 30] | [40] → max = 60
// → Answer = 60
//
// Constraints:
// - 1 ≤ n ≤ 10^5
// - 1 ≤ arr[i] ≤ 10^9
// - 1 ≤ k ≤ n
// - Return -1 if k > n


// 2. Brute Force (Linear Search on Answer)
// ----------------------------------------
//
// Idea:
// - Possible range of "maximum sum per part":
//   * low = max(arr)   (at least one big element must fit)
//   * high = sum(arr)  (all elements in one part)
// - For each candidate X in [low, high]:
//   * Use helper `countPartitions` to check how many parts needed
//     if no part exceeds X
//   * If parts_needed <= k → X is valid
//   * First valid X is the answer
//
// Helper: countPartitions(arr, X)
// - Greedily allocate elements into parts without exceeding X
// - If arr[i] > X → impossible, return large number
// - Return number of partitions used
//
// Time Complexity: O(N * (Sum - Max))
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

// Helper: number of partitions if max sum allowed = maxSum
int countPartitions(vector<int>& arr, int maxSum) {
    int partitions = 1;
    long long currentSum = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > maxSum) return INT_MAX; // impossible
        if(currentSum + arr[i] <= maxSum) {
            currentSum += arr[i];
        } else {
            partitions++;
            currentSum = arr[i];
        }
    }
    return partitions;
}

// Brute force
int splitArrayBrute(vector<int>& arr, int k) {
    int n = arr.size();
    if(k > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);

    int ans = -1;
    for(long long x = low; x <= high; x++) {
        int partitions = countPartitions(arr, x);
        if(partitions <= k) {
            ans = x;
            break; // first valid is minimum
        }
    }
    return ans;
}


// 3. Optimized Solution (Binary Search on Answer)
// ------------------------------------------------
//
// Key Insight:
// - If X sum allowed → k parts needed
//   * Any value > X will need ≤ k parts
//   * Any value < X will need ≥ k parts
// - Monotonic property → Binary Search
//
// Steps:
// 1. low = max(arr), high = sum(arr)
// 2. while(low <= high):
//      mid = (low + high) / 2
//      if countPartitions(arr, mid) <= k:
//          ans = mid
//          high = mid - 1   // try smaller
//      else
//          low = mid + 1    // need bigger sum
// 3. Return ans
//
// Time Complexity: O(N log(Sum - Max))
// Space Complexity: O(1)


int splitArray(vector<int>& arr, int k) {
    int n = arr.size();
    if(k > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    int ans = -1;

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        int partitions = countPartitions(arr, mid);

        if(partitions <= k) {
            ans = mid;
            high = mid - 1; // minimize further
        } else {
            low = mid + 1;  // need to allow bigger sums
        }
    }
    return ans;
}


// 4. Example Usage
// ----------------
int main() {
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    cout << "Brute: " << splitArrayBrute(arr, k) << endl;     // 60
    cout << "Binary Search: " << splitArray(arr, k) << endl;  // 60

    return 0;
}
