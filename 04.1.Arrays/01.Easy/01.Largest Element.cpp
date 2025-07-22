/*
Given an array of integers nums, return the value of the largest element in the array
Examples:

Input: nums = [3, 3, 6, 1]

Output: 6

Explanation: The largest element in array is 6

Input: nums = [3, 3, 0, 99, -40]

Output: 99

Explanation: The largest element in array is 99
*/

#include <iostream>
#include <vector>
using namespace std;

int largestElement(const vector<int>& nums) {
    int maxElement = nums[0]; // Assume first element is the largest

    for (int num : nums) {
        if (num > maxElement) {
            maxElement = num; // Update max if current number is larger
        }
    }

    return maxElement; // Return the largest element found
}

int main() {
    vector<int> nums = {3, 3, 6, 1};

    cout << "Largest element in the array: " << largestElement(nums) << endl;

    nums = {3, 3, 0, 99, -40};
    cout << "Largest element in the array: " << largestElement(nums) << endl;

    return 0;
}

// Time Complexity: O(N) where N is the number of elements in the array
// Space Complexity: O(1) since we are using a constant amount of extra space
