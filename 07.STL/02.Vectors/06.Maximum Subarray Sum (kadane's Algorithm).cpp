// Kadane's Algorithm to find the Maximum Subarray Sum
//
// Intuition:
// At each number in the array, we have two choices:
// 1) Start a new subarray from the current number, or
// 2) Add the current number to the subarray we were building before.
//
// We pick the option that gives us the bigger sum at every step.
// *****If the previous subarray sum is negative, it's better to start fresh from the current number.
//
// By doing this for every number, we find the subarray with the biggest total sum.
//
// Time Complexity:
// The algorithm goes through the array once, so it takes O(n) time.
//
// Space Complexity:
// It uses only a few variables, so the extra space used is O(1).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
int maxSubArraySum(const vector<int>& nums) {
    int maxSum = nums[0];       // Store the best sum found so far
    int currentSum = nums[0];   // Sum of subarray ending at current position

    for (size_t i = 1; i < nums.size(); i++) { // size_t is a type in C++ (and C) used to represent sizes and counts. It’s an unsigned integer type designed to hold the size of any object in memory, like the length of an array or a vector.
        // Choose to start new subarray at nums[i] or continue old one by adding nums[i]
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update maxSum if currentSum is bigger
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

*/

int maxSubArraySum(const vector<int>& nums) {
    int maxSum = nums[0];       // Store the best sum found so far
    int currentSum = nums[0];   // Sum of subarray ending at current position

    for (size_t i = 1; i < nums.size(); i++) { // size_t is a type in C++ (and C) used to represent sizes and counts. It’s an unsigned integer type designed to hold the size of any object in memory, like the length of an array or a vector.
       if(currentSum < 0) {
            currentSum = nums[i]; // Start new subarray if previous sum is negative
        } else {
            currentSum += nums[i]; // Continue old subarray
        }

        // Update maxSum if currentSum is bigger
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}


int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "The maximum subarray sum is: " << maxSubArraySum(nums) << endl;
    return 0;
}
