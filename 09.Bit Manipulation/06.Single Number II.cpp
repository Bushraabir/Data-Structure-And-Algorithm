#include <bits/stdc++.h>
using namespace std;

// Brute-Force Approach using Hash Map
int singleNumber_map(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    // Find the number that appears only once
    for (auto &entry : freq) {
        if (entry.second == 1) {
            return entry.first;
        }
    }
    return -1; // should never happen for valid input
}

// Bit Manipulation Approach (Count Bits)
int singleNumber_bitCount(vector<int>& nums) {
    int result = 0;

    // Loop through each bit position (0 to 31 for 32-bit integers)
    for (int bit = 0; bit < 32; ++bit) {
        int count = 0;

        // Count number of set bits at current position across all numbers
        for (int num : nums) {
            if (num & (1 << bit)) {
                count++;
            }
        }

        // If count % 3 == 1, this bit belongs to the single number
        if (count % 3 == 1) {
            result |= (1 << bit);
        }
    }

    return result;
}

// Optimal Bit Manipulation Approach (Buckets/Ones & Twos)
int singleNumber_buckets(vector<int>& nums) {
    int ones = 0; // bits that have appeared once
    int twos = 0; // bits that have appeared twice

    for (int num : nums) {
        // Update ones: XOR current number with ones, then remove bits present in twos
        ones = (ones ^ num) & ~twos;

        // Update twos: XOR current number with twos, then remove bits present in updated ones
        twos = (twos ^ num) & ~ones;
    }

    // After processing all numbers, 'ones' contains the number that appeared once
    return ones;
}

int main() {
    vector<int> nums = {5, 5, 5, 2, 4, 4, 4};

    cout << "Single number (map approach): " << singleNumber_map(nums) << endl;
    cout << "Single number (bit-count approach): " << singleNumber_bitCount(nums) << endl;
    cout << "Single number (optimal buckets approach): " << singleNumber_buckets(nums) << endl;

    return 0;
}
