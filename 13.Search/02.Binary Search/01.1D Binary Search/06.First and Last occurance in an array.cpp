/*
 * Problem Statement: First and Last Occurrences in Array
 *
 * You are given a sorted array 'arr' of integers and a target value 'target'.
 * Implement the following operations using binary search:
 * 1. First Occurrence: Smallest index where arr[index] == target.
 * 2. Last Occurrence: Largest index where arr[index] == target.
 * 3. Count Occurrences: Total number of times target appears in arr.
 *
 * Core Concept:
 * - Use binary search to efficiently find first and last occurrences.
 * - For first occurrence, move left when element == target.
 * - For last occurrence, move right when element == target.
 * - Count = (last_occurrence_index - first_occurrence_index) + 1
 * - Time Complexity: O(log N) for each operation.
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [1,2,2,2,3,4,5], target = 2
 * First Occurrence = 1
 * Last Occurrence = 3
 * Count Occurrences = 3
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// FIRST OCCURRENCE
// ---------------------------
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int first = -1; // default if target not found
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;        // potential first occurrence
            high = mid - 1;     // search left for smaller index
        } else if (arr[mid] < target) {
            low = mid + 1;      // search right
        } else {
            high = mid - 1;     // search left
        }
    }
    return first;
}

// ---------------------------
// LAST OCCURRENCE
// ---------------------------
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int last = -1; // default if target not found
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;         // potential last occurrence
            low = mid + 1;      // search right for larger index
        } else if (arr[mid] < target) {
            low = mid + 1;      // search right
        } else {
            high = mid - 1;     // search left
        }
    }
    return last;
}

// ---------------------------
// COUNT OCCURRENCES
// ---------------------------
int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1) return 0; // target not found
    int last = lastOccurrence(arr, target);
    return last - first + 1;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {1,2,2,2,3,4,5};
    int target = 2;

    cout << "First Occurrence index: " << firstOccurrence(arr, target) << endl;
    cout << "Last Occurrence index: " << lastOccurrence(arr, target) << endl;
    cout << "Count of Occurrences: " << countOccurrences(arr, target) << endl;

    return 0;
}
