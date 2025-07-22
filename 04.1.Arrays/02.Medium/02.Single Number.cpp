/*
Given an array of nums of n integers. Every integer in the array appears twice except one integer. Find the number that appeared once in the array.
Examples:

Input : nums = [1, 2, 2, 4, 3, 1, 4]

Output : 3

Explanation : The integer 3 has appeared only once.

Input : nums = [5]

Output : 5

Explanation : The integer 5 has appeared only once.
*/

#include <iostream>
using namespace std;

int singleNumber(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i]; // XOR operation
    }
    return result; // The result will be the number that appears only once
}

int main() {
    int arr[] = {1, 2, 2, 4, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int uniqueNumber = singleNumber(arr, n);

    cout << "The number that appears only once is: " << uniqueNumber << endl;

    return 0;
}
// time complexity: O(n)
// space complexity: O(1)