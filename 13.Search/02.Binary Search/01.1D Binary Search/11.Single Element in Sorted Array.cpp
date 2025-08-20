/*
 * Problem Statement: Find Single Element in a Sorted Array
 *
 * You are given a sorted array 'arr' where every element appears exactly twice except for one element, 
 * which appears only once. The task is to find and return this single element.
 *
 * Core Concept:
 * - A brute-force approach checks each element and its neighbors, but this is O(N).
 * - Optimized solution uses binary search:
 *   - Paired elements follow an (even, odd) index pattern before the single element.
 *   - After the single element, the pattern shifts to (odd, even).
 *   - Use this property to decide which half of the array to search.
 * - Time Complexity: O(log N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [1,1,2,3,3,4,4,8,8]
 * Answer = 2
 * arr = [3,3,7,7,10,11,11]
 * Answer = 10
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// FIND SINGLE ELEMENT USING BINARY SEARCH
// ---------------------------
int findSingleElement(vector<int>& arr) {
    int n = arr.size();

    // Edge cases: first or last element
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the single element
        if (arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }

        // Determine which half to search based on pairing pattern
        if ((mid % 2 == 0 && arr[mid] == arr[mid+1]) ||
            (mid % 2 == 1 && arr[mid] == arr[mid-1])) {
            // Single element is in the right half
            low = mid + 1;
        } else {
            // Single element is in the left half
            high = mid - 1;
        }
    }

    return -1; // Should never reach here as per problem constraints
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {1,1,2,3,3,4,4,8,8};

    int single = findSingleElement(arr);
    cout << "The single element in array: " << single << endl;

    return 0;
}
