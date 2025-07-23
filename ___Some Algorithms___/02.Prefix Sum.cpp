/*   
This program demonstrates the Prefix Sum technique step by step.
It is used to compute the sum of elements in a subarray efficiently.

Steps:
1. Construct a prefix sum array:
   - prefixSum[i] = sum of all elements from index 0 to i-1 (0-based indexing)
   - prefixSum[0] = 0 (to make calculations easier)

2. To find the sum of elements from index `l` to `r` (inclusive):
   - Use: sum = prefixSum[r + 1] - prefixSum[l]

Time Complexity:
    - O(N) to build the prefix sum array
    - O(1) for each range sum query

Space Complexity:
    - O(N) for the prefix sum array
*/



#include <iostream>
#include <vector>
using namespace std;

// Function to build prefix sum array
vector<int> buildPrefixSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0); // prefixSum[0] = 0

    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    return prefixSum;
}

// Function to get sum from index l to r (inclusive)
int rangeSum(const vector<int>& prefixSum, int l, int r) {
    return prefixSum[r + 1] - prefixSum[l];
}










int main() {
    vector<int> nums = {2, 4, 1, 3, 5};

    cout << "Input array:\n";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << "\n\n";

    // Build prefix sum array
    vector<int> prefixSum = buildPrefixSum(nums);

    cout << "Prefix Sum array:\n";
    for (int val : prefixSum) {
        cout << val << " ";
    }
    cout << "\n\n";

    // Example queries
    int l = 1, r = 3; // Sum from index 1 to 3 (4 + 1 + 3 = 8)
    cout << "Sum from index " << l << " to " << r << " = " << rangeSum(prefixSum, l, r) << endl;

    l = 0, r = 4; // Sum from index 0 to 4 (whole array = 15)
    cout << "Sum from index " << l << " to " << r << " = " << rangeSum(prefixSum, l, r) << endl;

    return 0;
}
