/*
Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not found in the array, return -1
Examples:

Input: nums = [2, 3, 4, 5, 3], target = 3

Output: 1

Explanation: The first occurence of 3 in nums is at index 1

Input: nums = [2, -4, 4, 0, 10], target = 6

Output: -1

Explanation: The value 6 does not occur in the array, hence output is -1
*/

#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int arr[] = {2, 3, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int index = linearSearch(arr, n, target);

    if (index != -1) {
        cout << "The first occurrence of " << target << " is at index: " << index << endl;
    } else {
        cout << target << " is not found in the array." << endl;
    }

    return 0;
}

// time complexity: O(n)
// space complexity: O(1)