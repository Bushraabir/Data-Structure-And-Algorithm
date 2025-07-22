/*
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.
Examples:

Input : nums = [1, 2, 3, 4, 5]

Output : true

Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.

Input : nums = [1, 2, 1, 4, 5]

Output : false

Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.
*/

#include <iostream>
#include <vector>
using namespace std;
bool isSorted(const vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            return false; // Found an element that is smaller than the previous one
        }
    }
    return true; // All elements are in non-decreasing order
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 1, 4, 5};

    cout <<  (isSorted(nums1) ? "True" : "False") << endl;
    cout <<  (isSorted(nums2) ? "True" : "False") << endl;

    return 0;
}

// Time Complexity: O(N) where N is the number of elements in the array
// Space Complexity: O(1) since we are using a constant amount of extra space
