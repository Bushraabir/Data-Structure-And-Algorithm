/*
 * Problem Statement: Count Inversions
 *
 * You are given an array of integers. An inversion is a pair (i, j) such that
 *   • i < j
 *   • arr[i] > arr[j]
 * Your task is to count the total number of inversions in the array.
 *
 * Approach 1: Brute Force (O(n^2))
 *   - Check every pair i < j and increment count if arr[i] > arr[j].
 *
 * Approach 2: Merge Sort (O(n log n))
 *   - During the merge step of Merge Sort, when an element from the right
 *     subarray is placed before elements from the left subarray, it forms
 *     inversions equal to the number of remaining elements in the left subarray.
 *   - Accumulate these counts as you merge.
 */

#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Brute Force
long long countInversions_BruteForce(const vector<int>& arr) {
    int n = arr.size();
    long long invCount = 0;
    // Check all pairs i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                ++invCount;
            }
        }
    }
    return invCount;
}

// Helper to merge two sorted halves and count cross-inversions
long long mergeAndCount(vector<int>& temp, vector<int>& arr,
                        int left, int mid, int right) {
    int i = left;      // pointer in left half
    int j = mid + 1;   // pointer in right half
    int k = left;      // pointer in temp
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j] => all remaining arr[i..mid] > arr[j]
            invCount += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }
    // Copy any remaining elements
    while (i <= mid)    temp[k++] = arr[i++];
    while (j <= right)  temp[k++] = arr[j++];

    // Transfer merged segment back to original array
    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
    return invCount;
}

// Recursive Merge Sort that counts inversions
long long mergeSortAndCount(vector<int>& temp, vector<int>& arr,
                            int left, int right) {
    if (left >= right) 
        return 0;
    int mid = left + (right - left) / 2;
    long long invCount = 0;
    invCount += mergeSortAndCount(temp, arr, left, mid);
    invCount += mergeSortAndCount(temp, arr, mid + 1, right);
    invCount += mergeAndCount(temp, arr, left, mid, right);
    return invCount;
}

// Approach 2: Merge Sort
long long countInversions_MergeSort(vector<int> arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(temp, arr, 0, n - 1);
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << "Inversion count (Brute Force): "
         << countInversions_BruteForce(arr) << "\n";
    cout << "Inversion count (Merge Sort):  "
         << countInversions_MergeSort(arr) << "\n";
    return 0;
}
