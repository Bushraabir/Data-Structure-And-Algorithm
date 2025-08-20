/*
 * Problem Statement: Binary Search
 *
 * You are given a sorted array 'arr' of integers and a target value 'target'.
 * The task is to find the index of 'target' in 'arr' using binary search.
 * If the target is not present, return -1.
 *
 * Core Concept:
 * - Binary search works on sorted search spaces.
 * - At each step, the search space is halved by comparing the middle element with the target.
 * - This process continues iteratively or recursively until the element is found or search space is exhausted.
 *
 * Real-life Example:
 * - Searching a word in a dictionary.
 * - You don’t check every page; instead, split the dictionary, determine which half contains the word, and continue.
 *
 * Brute Force Solution (Linear Search, O(N)):
 * 1. Iterate over the array from index 0 to n-1.
 * 2. Compare each element with target.
 * 3. If found, return index; else continue.
 * 4. If end is reached, return -1.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Optimal Solution (Binary Search, O(log N)):
 * Iterative Approach:
 * 1. Initialize low = 0, high = n-1.
 * 2. While low <= high:
 *      - Compute mid = low + (high - low) / 2  // avoids overflow
 *      - If arr[mid] == target, return mid.
 *      - If arr[mid] < target, set low = mid + 1.
 *      - If arr[mid] > target, set high = mid - 1.
 * 3. If element not found, return -1.
 *
 * Recursive Approach:
 * 1. Base case: if low > high, return -1.
 * 2. Compute mid = low + (high - low) / 2.
 * 3. If arr[mid] == target, return mid.
 * 4. If arr[mid] < target, recursively search in right half (low = mid + 1).
 * 5. If arr[mid] > target, recursively search in left half (high = mid - 1).
 *
 * Key Insight:
 * - Binary search reduces the search space by half every step.
 * - Time complexity: O(log N)
 * - Space complexity: O(1) for iterative, O(log N) for recursive (stack calls)
 * - Overflow Prevention: use mid = low + (high - low) / 2
 *
 * Example:
 * arr = [1,3,5,6,8,9], target = 6
 * Answer = 3 (index of 6)
 */

#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // prevents overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;  // target not found
}

// Recursive Binary Search
int binarySearchRecursive(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;  // prevents overflow
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
    else return binarySearchRecursive(arr, low, mid - 1, target);
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {1, 3, 5, 6, 8, 9};
    int target = 6;

    cout << "Iterative Binary Search index: "
         << binarySearchIterative(arr, target) << endl;

    cout << "Recursive Binary Search index: "
         << binarySearchRecursive(arr, 0, arr.size() - 1, target) << endl;

    return 0;
}
