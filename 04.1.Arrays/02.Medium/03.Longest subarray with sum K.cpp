/*

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
Examples:

Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Input: nums = [-3, 2, 1], k=6

Output: 0

Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k) {
    unordered_map<int, int> sumIndexMap; // To store the first occurrence of each sum
    int maxLength = 0;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i]; // Update the current sum

        // Check if the current sum is equal to k
        if (currentSum == k) {
            maxLength = i + 1; // Update maxLength if we found a sub-array from index 0 to i
        }

        // If currentSum - k exists in the map, it means we found a sub-array with sum k
        if (sumIndexMap.find(currentSum - k) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[currentSum - k]);
        }

        // Store the first occurrence of the current sum
        if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {
            sumIndexMap[currentSum] = i;
        }
    }

    return maxLength; // Return the length of the longest sub-array with sum k
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;

    int length = longestSubarrayWithSumK(arr, n, k);

    cout << "Length of the longest sub-array with sum " << k << ": " << length << endl;

    return 0;
}
// time complexity: O(n)
// space complexity: O(n)