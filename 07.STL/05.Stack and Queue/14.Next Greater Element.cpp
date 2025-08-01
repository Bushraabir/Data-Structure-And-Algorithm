//monotonic stack(the stack that is used to store elements in a specific order, like increasing or decreasing order) is used to solve problems like next greater element, next smaller element, etc.
// It is a stack that maintains its elements in a specific order, either increasing or decreasing.      


// Monotonic stacks are particularly useful for problems that involve finding the next greater or smaller element in an array.

// Problem Statement: Next Greater Element (NGE)
// ------------------------------------------------
// Given an array of integers, for each element, find the next element to its right which is greater than it.
// If no such element exists, output -1 for that index.
// 
// Example:
// Input: [6, 0, 8, 1, 3]
// Output: [8, 8, -1, 3, -1]
// Explanation:
//  - For 6, the next greater is 8
//  - For 0, the next greater is 8
//  - For 8, there is no greater element on the right → -1
//  - For 1, the next greater is 3
//  - For 3, there is no greater → -1

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 5.1 Brute Force Approach
// ------------------------
// Concept: For each element, scan to the right to find the next greater element
// This is straightforward but inefficient for large arrays
vector<int> BruteForce(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                result[i] = nums[j];
                break; // stop at the first greater
            }
        }
    }
    return result;
}
// Time Complexity: O(N^2) due to nested loops
// Space Complexity: O(N) for the result array


// 5.2 Optimized Approach Using Monotonic Stack
// --------------------------------------------
// Concept: Use a stack to maintain a decreasing sequence of potential greater elements
// Traverse the array from right to left so we know the elements that come after the current one
// For each element, we pop all smaller/equal elements (as they can’t be the answer)
// The remaining top (if any) is the next greater
vector<int> Optimized(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // Stack will keep track of greater elements on the right

    for (int i = n - 1; i >= 0; i--) {
        // Remove elements smaller than or equal to current element
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        // If stack is not empty, the top is the next greater element
        if (!st.empty()) {
            result[i] = st.top();
        }

        // Push current element to stack for future comparisons
        st.push(nums[i]);
    }
    return result;
}
// Time Complexity: O(N)
//     - Each element is pushed and popped at most once
// Space Complexity: O(N)
//     - Stack stores at most N elements
//     - Result array of size N


// 5.3 Example Usage
// -----------------
void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {6, 0, 8, 1, 3};

    cout << "Brute Force NGE: ";
    printVector(BruteForce(nums));

    cout << "Optimized Stack NGE: ";
    printVector(Optimized(nums));

    return 0;
}
