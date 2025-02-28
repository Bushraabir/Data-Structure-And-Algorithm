// leetcode 136 
/*
    int singleNumber(vector<int>& nums) { -->due to & sign the original vector is passed by reference
                                          --> if there were no & sign, it would have passed by value
        
    }

*/


//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

//
// Explanation:
// The XOR (^) operation has several useful properties:
// 1. a ^ a = 0: XORing two identical numbers results in zero.
// 2. a ^ 0 = a: XORing a number with zero results in the number itself.
// 3. XOR is both commutative and associative, meaning the order of operations does not matter.
// By XORing all the numbers in the array, the numbers that appear in pairs cancel out,
// leaving only the number that appears once.

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(const vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR accumulates the result
    }
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example array where every element appears twice except one.
    
    cout << "The single number in the array is: " << singleNumber(nums) << endl;
    return 0;
}