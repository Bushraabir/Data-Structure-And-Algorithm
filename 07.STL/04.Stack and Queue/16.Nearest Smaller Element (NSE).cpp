// Problem Statement: Nearest Smaller Element (NSE) on the Left
// -----------------------------------------------------------
// Given an array of integers, for each element, find the nearest element to its LEFT which is smaller than it.
// If no such element exists, output -1 for that index.
// 
// Example:
// Input: [4, 5, 2, 2, 8]
// Output: [-1, 4, -1, -1, 2]
// Explanation:
//  - For 4, there's nothing to the left → -1
//  - For 5, the nearest smaller to left is 4
//  - For 2, nothing smaller to the left → -1
//  - For 2 (second 2), previous 2 is equal (not smaller) → -1
//  - For 8, nearest smaller to the left is 2

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Brute Force Approach for Nearest Smaller to Left (NSE)
// ------------------------------------------------------
// Concept: For every element, scan backwards to find the nearest smaller element on the left.
vector<int> LeftSmallerBruteForce(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                result[i] = nums[j];
                break;
            }
        }
    }
    return result;
}
// Time Complexity: O(N^2)
// Space Complexity: O(N) for result array


// Optimized Approach Using Monotonic Stack for NSE
// ------------------------------------------------
// Concept: Traverse left-to-right. Stack maintains increasing elements from top to bottom.
// For each element, pop elements >= current. Top of stack is nearest smaller element.
vector<int> LeftSmallerOptimized(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(nums[i]);
    }
    return result;
}
// Time Complexity: O(N)
//     - Each element is pushed and popped at most once
// Space Complexity: O(N)
//     - Stack stores at most N elements
//     - Result array of size N


// Example Usage
// -------------
void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {4, 5, 2, 2, 8};

    cout << "Brute Force (Nearest Smaller Left): ";
    printVector(LeftSmallerBruteForce(nums));

    cout << "Optimized Stack (Nearest Smaller Left): ";
    printVector(LeftSmallerOptimized(nums));

    return 0;
}
