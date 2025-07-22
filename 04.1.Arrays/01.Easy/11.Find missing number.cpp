/*
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.
Examples:

Input: nums = [0, 2, 3, 1, 4]

Output: 5

Explanation: nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]

Input: nums = [0, 1, 2, 4, 5, 6]

Output: 3

Explanation: nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]
*/

#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int total = (n * (n + 1)) / 2; // Sum of first n natural numbers
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Calculate the sum of elements in the array
    }

    return total - sum; // The missing number is the difference
}

int main() {
    int arr[] = {0, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, n);

    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}

// time complexity: O(n)
// space complexity: O(1)