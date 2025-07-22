/*
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
Examples:

Input: nums = [8, 8, 7, 6, 5]

Output: 7

Explanation: The largest value in nums is 8, the second largest is 7

Input: nums = [10, 10, 10, 10, 10]

Output: -1

Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned

*/

#include <iostream>
#include <vector>
using namespace std;

int secondLargestElement(const vector<int>& nums) {
    int flargest = -1;
    int slargest = -1;

    for( int i = 0 ; i < nums.size() ; i++ ) {
        if( nums[i] > flargest ) {
            slargest = flargest; // Update second largest
            flargest = nums[i];  // Update largest
        } else if( nums[i] > slargest && nums[i] < flargest ) {
            slargest = nums[i];  // Update second largest only
        }
    }
    return slargest; // Return second largest or -1 if it doesn't exist

}

int main() {
    vector<int> nums = {8, 8, 7, 6, 5};
    cout << "Second largest element: " << secondLargestElement(nums) << endl;

    nums = {10, 10, 10, 10, 10};
    cout << "Second largest element: " << secondLargestElement(nums) << endl;

    return 0;
}

// Time Complexity: O(N) where N is the number of elements in the array
// Space Complexity: O(1) since we are using a constant amount of extra space
