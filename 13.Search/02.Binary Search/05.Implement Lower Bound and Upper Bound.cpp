/*
 * Problem Statement: Binary Search Variants
 *
 * You are given a sorted array 'arr' of integers and a target value 'target'.
 * Implement the following operations using binary search:
 * 1. Lower Bound: Smallest index where arr[index] >= target.
 * 2. Upper Bound: Smallest index where arr[index] > target.
 * 3. Search Insert Position: Index where target is found or should be inserted.
 * 4. Floor: Largest value <= target in arr.
 * 5. Ceil: Smallest value >= target in arr.
 *
 * Core Concept:
 * - Binary search can be adapted to find first/last occurrence, insert positions, and closest values.
 * - Use an 'answer' variable to store the best candidate during search.
 * - Time Complexity: O(log N) for all operations.
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [1,3,5,6,8,9]
 * target = 6
 * Lower Bound = 3 (index of 6)
 * Upper Bound = 4 (index of 8)
 * Search Insert Position = 3
 * Floor = 6
 * Ceil = 6
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// LOWER BOUND
// ---------------------------
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int answer = arr.size(); // default if target > all elements
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            answer = mid; // possible answer
            high = mid - 1; // search left for smaller index
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

// ---------------------------
// UPPER BOUND
// ---------------------------
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int answer = arr.size(); // default if target >= all elements
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            answer = mid; // possible answer
            high = mid - 1; // search left for smaller index
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

// ---------------------------
// SEARCH INSERT POSITION
// ---------------------------
int searchInsertPosition(vector<int>& arr, int target) {
    // Same as lower bound
    return lowerBound(arr, target);
}

// ---------------------------
// FLOOR
// ---------------------------
int floorValue(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int answer = -1; // default if no element <= target
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            answer = arr[mid]; // possible floor
            low = mid + 1; // search right for larger value <= target
        } else {
            high = mid - 1;
        }
    }
    return answer;
}

// ---------------------------
// CEIL
// ---------------------------
int ceilValue(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int answer = -1; // default if no element >= target
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            answer = arr[mid]; // possible ceil
            high = mid - 1; // search left for smaller value >= target
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {1, 3, 5, 6, 8, 9};
    int target = 6;

    cout << "Lower Bound index: " << lowerBound(arr, target) << endl;
    cout << "Upper Bound index: " << upperBound(arr, target) << endl;
    cout << "Search Insert Position: " << searchInsertPosition(arr, target) << endl;
    cout << "Floor value: " << floorValue(arr, target) << endl;
    cout << "Ceil value: " << ceilValue(arr, target) << endl;

    return 0;
}
