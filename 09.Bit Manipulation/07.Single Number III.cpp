#include <bits/stdc++.h>
using namespace std;

// Brute-Force Approach using Hash Map
vector<int> singleNumber_map(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    vector<int> answer;
    // Collect numbers that appear exactly once
    for (auto &entry : freq) {
        if (entry.second == 1) {
            answer.push_back(entry.first);
        }
    }

    return answer;
}

// Optimal Bit Manipulation Approach
vector<int> singleNumber_bitManipulation(vector<int>& nums) {
    int xor_sum = 0;

    // Step 1: XOR all numbers to get xor_sum = X ^ Y
    for (int num : nums) {
        xor_sum ^= num;
    }

    // Step 2: Find the rightmost set bit in xor_sum
    int rightmost_set_bit = xor_sum & (-xor_sum);

    int bucket1 = 0; // Will contain one unique number
    int bucket2 = 0; // Will contain the other unique number

    // Step 3: Partition numbers into two buckets based on the differentiating bit
    for (int num : nums) {
        if (num & rightmost_set_bit) {
            bucket1 ^= num; // XOR numbers with the bit set
        } else {
            bucket2 ^= num; // XOR numbers with the bit not set
        }
    }

    // Step 4: Return the two unique numbers
    return {bucket1, bucket2};
}

int main() {
    vector<int> nums = {2, 4, 2, 6, 3, 7, 7, 3};

    // Using Hash Map
    vector<int> result_map = singleNumber_map(nums);
    cout << "Single numbers (map approach): ";
    for (int num : result_map) cout << num << " ";
    cout << endl;

    // Using Optimal Bit Manipulation
    vector<int> result_bit = singleNumber_bitManipulation(nums);
    cout << "Single numbers (bit manipulation approach): ";
    for (int num : result_bit) cout << num << " ";
    cout << endl;

    return 0;
}
