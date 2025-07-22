/*
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.


The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.
Examples:

Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation: The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> unionOfSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
        } else if (nums1[i] > nums2[j]) {
            if (result.empty() || result.back() != nums2[j]) {
                result.push_back(nums2[j]);
            }
            j++;
        } else { // nums1[i] == nums2[j]
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from nums1
    while (i < nums1.size()) {
        if (result.empty() || result.back() != nums1[i]) {
            result.push_back(nums1[i]);
        }
        i++;
    }

    // Add remaining elements from nums2
    while (j < nums2.size()) {
        if (result.empty() || result.back() != nums2[j]) {
            result.push_back(nums2[j]);
        }
        j++;
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 7};

    vector<int> result = unionOfSortedArrays(nums1, nums2);

    cout << "Union of the two sorted arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// time complexity: O(n + m) where n and m are the sizes of nums1 and nums2 respectively
// space complexity: O(n + m) for the result array