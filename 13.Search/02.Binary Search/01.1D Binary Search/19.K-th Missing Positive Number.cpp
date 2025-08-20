// 1. Problem Introduction
// -----------------------
//
// Goal: Find the K-th missing positive integer given a sorted increasing array.
//
// Examples:
// - arr = [2,3,4,7,11], K = 5 → Missing numbers = {1,5,6,8,9,10}, Answer = 9
// - arr = [5,6,7], K = 4 → Missing numbers = {1,2,3,4}, Answer = 4
//
// Constraints:
// - Array is sorted and strictly increasing
// - Positive integers only
// - Missing numbers may lie before, between, or after array elements


// 2. Brute Force (Linear Scan)
// ----------------------------
//
// Idea:
// - Iterate through the array
// - If arr[i] <= K, increment K (skip this as it's not missing)
// - Else break (we’ve found the range)
// - Final value of K is the answer
//
// Example: arr = [2,3,4,7,11], K = 5
// - arr[0] = 2 <= 5 → K = 6
// - arr[1] = 3 <= 6 → K = 7
// - arr[2] = 4 <= 7 → K = 8
// - arr[3] = 7 <= 8 → K = 9
// - arr[4] = 11 > 9 → stop, answer = 9
//
// Time Complexity: O(n)
// Space Complexity: O(1)


// 3. Optimized Solution (Binary Search on Index)
// ----------------------------------------------
//
// Key Insight:
// - Missing numbers till index i = arr[i] - (i + 1)
// - This is because in a perfect sequence, arr[i] should = i+1
//
// Binary Search Steps:
// 1. low = 0, high = n-1
// 2. while(low <= high):
//      mid = (low + high) / 2
//      missing = arr[mid] - (mid + 1)
//      if missing < K → search right (low = mid + 1)
//      else → search left (high = mid - 1)
// 3. Final Answer = low + K
//
// Why low + K?
// - At the end, "low" points to the index where K-th missing lies
// - Formula derived: Answer = K + low
//
// Time Complexity: O(log n)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n)
int findKthPositiveBrute(vector<int>& arr, int K) {
    for(int num : arr) {
        if(num <= K) K++;
        else break;
    }
    return K;
}

// Optimized Binary Search: O(log n)
int findKthPositive(vector<int>& arr, int K) {
    int low = 0, high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);

        if(missing < K) {
            low = mid + 1; // need more missing
        } else {
            high = mid - 1; // too many missing, go left
        }
    }
    return low + K;
}


// 4. Example Usage
// ----------------
int main() {
    vector<int> arr1 = {2,3,4,7,11};
    int K1 = 5;
    cout << "Brute: " << findKthPositiveBrute(arr1, K1) << endl; // 9
    cout << "Binary Search: " << findKthPositive(arr1, K1) << endl; // 9

    vector<int> arr2 = {5,6,7};
    int K2 = 4;
    cout << "Brute: " << findKthPositiveBrute(arr2, K2) << endl; // 4
    cout << "Binary Search: " << findKthPositive(arr2, K2) << endl; // 4

    return 0;
}
