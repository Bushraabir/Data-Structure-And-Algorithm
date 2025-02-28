// This program finds the maximum subarray sum using Kadane's algorithm.
// Kadane's algorithm efficiently computes the maximum sum of a contiguous subarray.
// It works by iterating through the array and maintaining two variables:
// - currentSum: the maximum subarray sum ending at the current index.
// - maxSum: the maximum subarray sum found so far.
// For each element, it decides whether to add the current element to the existing subarray
// or to start a new subarray from the current element. The maximum of these choices is stored
// as the new currentSum, and maxSum is updated accordingly.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSubArraySum(const vector<int>& nums) {
    int maxSum = nums[0];      // Initialize maxSum with the first element
    int currentSum = nums[0];  // Initialize currentSum with the first element

    // Iterate through the vector starting from the second element
    for (size_t i = 1; i < nums.size(); i++) {
        // Update currentSum: either start a new subarray at nums[i] or add nums[i] to the existing subarray
        currentSum = max(nums[i], currentSum + nums[i]);
        // Update maxSum if currentSum is greater
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "The maximum subarray sum is: " << maxSubArraySum(nums) << endl;
    return 0;
}
