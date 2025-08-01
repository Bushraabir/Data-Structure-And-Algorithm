/*   
This program demonstrates the Prefix Sum technique step by step using a class-based approach.
It is used to compute the sum of elements in a subarray efficiently.

 Class Design:
1. Constructor builds the prefix sum array:
   - prefixSum[i] = nums[0] + nums[1] + ... + nums[i]
   - We use a 1D array to store cumulative sums.
   - This allows us to answer any subarray sum query in O(1) time.

2. sumRange(l, r):
   - Returns the sum from index l to r (inclusive)
   - If l == 0: return prefixSum[r]
   - Else: return prefixSum[r] - prefixSum[l - 1]

 Time Complexity:
    - Constructor: O(N) → builds prefix sum once
    - sumRange(): O(1) → constant time query

 Space Complexity:
    - O(N) → to store the prefix sum array
*/

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> prefixSum;

    //  Constructor: Build the prefix sum array during object creation
    NumArray(const vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n); // allocate memory for prefix sums
        prefixSum[0] = nums[0]; // first element is same as original

        // Build prefixSum such that prefixSum[i] = sum of nums[0] to nums[i]
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
    }

    // Query function: Returns the sum of elements from index l to r
    int sumRange(int l, int r) {
        if (l == 0)
            return prefixSum[r]; // sum from 0 to r is directly prefixSum[r]
        else
            return prefixSum[r] - prefixSum[l - 1]; // subtract prefix up to l-1
    }
};

int main(){
    vector<int> nums = {2, 4, 1, 3, 5};

    cout << "Input array:\n";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << "\n\n";

    // Create NumArray object, which builds the prefix sum during construction
    NumArray numArray(nums);

    cout << "Prefix Sum array:\n";
    for (int val : numArray.prefixSum) {
        cout << val << " ";
    }
    cout << "\n\n";

    //  Query 1: sum from index 1 to 3
    
    int l = 1, r = 3;
    cout << "Sum from index " << l << " to " << r << " = " << numArray.sumRange(l, r) << endl;

    //  Query 2: sum from index 0 to 4
    
    l = 0, r = 4;
    cout << "Sum from index " << l << " to " << r << " = " << numArray.sumRange(l, r) << endl;

    return 0;
}
