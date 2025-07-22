/*
Given a binary array nums, return the maximum number of consecutive 1s in the array.


A binary array is an array that contains only 0s and 1s.
Examples:

Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]

Output: 3

Explanation: The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s

Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]

Output: 0

Explanation: No 1s are present in nums, thus we return 0

*/

#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(int nums[], int n) {
    int maxCount = 0, currentCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            currentCount++; // Increment count for consecutive 1s
        } else {
            maxCount = max(maxCount, currentCount); // Update max count if needed
            currentCount = 0; // Reset count for 0
        }
    }

    // Final check to update maxCount in case the array ends with 1s
    return max(maxCount, currentCount);
}
int main() {
    int nums[] = {1, 1, 0, 0, 1, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums, n);

    cout << "Maximum consecutive 1s: " << maxConsecutiveOnes << endl;

    return 0;
}
// time complexity: O(n)
// space complexity: O(1)