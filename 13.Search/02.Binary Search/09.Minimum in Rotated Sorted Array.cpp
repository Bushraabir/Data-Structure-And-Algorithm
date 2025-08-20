/*
 * Problem Statement: Minimum in Rotated Sorted Array
 *
 * You are given a rotated sorted array 'arr' of unique integers.
 * A rotated sorted array is an array that was initially sorted but then rotated at some pivot.
 * The task is to find and return the minimum element in the array.
 *
 * Core Concept:
 * - Use binary search to efficiently find the minimum element.
 * - At each step, identify if the current search space is sorted:
 *   - If arr[low] <= arr[high], then arr[low] is the minimum in this segment.
 * - Otherwise, determine which half is sorted and eliminate it while keeping track of potential minimums:
 *   - If left half is sorted, update answer = min(answer, arr[low]) and search right half.
 *   - If right half is sorted, update answer = min(answer, arr[mid]) and search left half.
 * - Time Complexity: O(log N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [4,5,6,7,0,1,2]
 * Answer = 0
 * arr = [1,2,3,4,5]
 * Answer = 1
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// FIND MINIMUM IN ROTATED SORTED ARRAY
// ---------------------------
int findMinRotatedSortedArray(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int answer = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If current segment is already sorted
        if (arr[low] <= arr[high]) {
            answer = min(answer, arr[low]);
            break;
        }

        // Identify which half is sorted
        if (arr[low] <= arr[mid]) {
            // Left half is sorted
            answer = min(answer, arr[low]);
            low = mid + 1; // search in right half
        } else {
            // Right half is sorted
            answer = min(answer, arr[mid]);
            high = mid - 1; // search in left half
        }
    }

    return answer;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {4,5,6,7,0,1,2};

    int minimum = findMinRotatedSortedArray(arr);
    cout << "Minimum element in array: " << minimum << endl;

    return 0;
}
