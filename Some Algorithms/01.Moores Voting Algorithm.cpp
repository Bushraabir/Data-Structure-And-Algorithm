/*   
This program demonstrates the Moore's Voting Algorithm step by step.
It is used to find the majority element in an array (if it exists).
A majority element is an element that appears more than ⌊n/2⌋ times.

Steps:
1. Phase 1 (Finding a Candidate):
   - Iterate through the array and maintain a count and a candidate.
   - If count becomes 0, update the candidate.
   - If current element == candidate, increase count.
   - Else decrease count.

2. Phase 2 (Verifying the Candidate):
   - Check if the candidate actually appears more than ⌊n/2⌋ times.

Time Complexity:
    - O(N) (Linear traversal for both phases)

Space Complexity:
    - O(1) (No extra space used)
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find majority element using Moore's Voting Algorithm
int findMajorityElement(const vector<int>& nums) {
    int count = 0;
    int candidate = -1;

    // Phase 1: Find a candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num; // Assign new candidate
            count = 1;
        } else if (num == candidate) {
            count++; // Same as candidate, increment count
        } else {
            count--; // Different from candidate, decrement count
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate; // Majority element found
    } else {
        return -1; // No majority element
    }
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Input array:\n";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << "\n\n";

    int majority = findMajorityElement(nums);

    if (majority != -1) {
        cout << "Majority Element is: " << majority << endl;
    } else {
        cout << "No Majority Element found." << endl;
    }

    return 0;
}
