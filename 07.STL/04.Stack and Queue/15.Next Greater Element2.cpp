// Problem Statement: Next Greater Element II (Circular Array)
// -----------------------------------------------------------
// Given a circular array of integers, for each element, find the next element to its right which is greater than it.
// If no such element exists, output -1 for that index.
// 
// Because the array is circular, we may have to wrap around to the beginning to find the NGE.
// 
// Example:
// Input: [2, 10, 12, 1, 11]
// Output: [10, 12, -1, 11, 12]
// Explanation:
//  - For 2, the next greater is 10
//  - For 10, the next greater is 12
//  - For 12, nothing is greater → -1
//  - For 1, the next greater is 11
//  - For 11, after wrapping around, the next greater is 12

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Brute Force Approach for Circular NGE
// -------------------------------------
// Concept: Check next greater in normal forward direction first.
// If not found, then wrap around using modulo and check from beginning.
vector<int> CircularBruteForce(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            int idx = (i + j) % n; // we are imaging a circular array so we use modulo to wrap around   
            if (nums[idx] > nums[i]) {
                result[i] = nums[idx];
                break;
            }
        }
    }
    return result;
}
// Time Complexity: O(N^2)
// Space Complexity: O(N) for the result array

// Optimized Approach Using Monotonic Stack for Circular NGE
// ----------------------------------------------------------
// Concept: Simulate a virtual array of size 2N and use modulo to wrap around.
// Traverse from 2N-1 down to 0 so elements that come after are seen first.
vector<int> CircularOptimized(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // stack stores potential NGE candidates

    for (int i = 2 * n - 1; i >= 0; --i) {
        int idx = i % n;

        // Maintain decreasing stack: pop elements <= current
        while (!st.empty() && st.top() <= nums[idx]) {
            st.pop();
        }

        // Only fill result during first pass (i < n)
        if (i < n) {
            if (!st.empty()) result[idx] = st.top();
            // else it remains -1
        }

        // Push current element for next iterations
        st.push(nums[idx]);
    }
    return result;
}
// Time Complexity: O(N)
//     - The loop runs 2N times
//     - Each element is pushed/popped at most once → Total: O(4N) = O(N)
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
    vector<int> nums = {2, 10, 12, 1, 11};

    cout << "Brute Force (Circular NGE): ";
    printVector(CircularBruteForce(nums));

    cout << "Optimized Stack (Circular NGE): ";
    printVector(CircularOptimized(nums));

    return 0;
}
