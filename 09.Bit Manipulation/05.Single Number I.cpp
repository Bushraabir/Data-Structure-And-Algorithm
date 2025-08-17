#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;

    // count frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    // find the number that appears once
    for (auto &entry : freq) {
        if (entry.second == 1) {
            return entry.first;
        }
    }

    return -1; // should never happen for valid input
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number (brute force): " << singleNumber(nums) << endl;
    return 0;
}
