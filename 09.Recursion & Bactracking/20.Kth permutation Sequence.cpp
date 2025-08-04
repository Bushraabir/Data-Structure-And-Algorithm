/*
 * Problem Statement: K-th Permutation Sequence
 *
 * You are given two integers n and k. Consider the set of numbers {1, 2, ..., n}.
 * There are n! permutations of these numbers in lexicographical order.
 * Your task is to compute and return the k-th permutation as a string.
 *
 * Approach: Mathematical (Factorial Number System)
 * - We avoid generating all n! permutations by computing each position directly.
 * - Observe that the first digit changes every (n-1)! permutations, the second every (n-2)! within each block, and so on.
 * - Steps:
 *    1. Build a list nums = {1,2,...,n}.
 *    2. Decrement k by 1 to convert to zero-based index.
 *    3. Precompute factorial = (n-1)!.
 *    4. For i from n down to 1:
 *         a. index = k / factorial  -> which number to pick from nums
 *         b. append nums[index] to result string
 *         c. erase nums[index] from list
 *         d. k %= factorial        -> new relative position within the block
 *         e. if i > 1, factorial /= (i-1)
 *    5. Return the built string.
 *
 * Time Complexity: O(n^2) due to erasing from the middle of the list each iteration.
 * Space Complexity: O(n) for nums list and the result string.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getKthPermutation(int n, int k) {
    // Step 1: prepare numbers and factorial
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) nums[i] = i + 1;
    int factorial = 1;
    for (int i = 1; i < n; ++i) factorial *= i;
    
    // Step 2: convert k to 0-based
    k -= 1;
    
    // Step 3: build the permutation
    string result;
    result.reserve(n);
    int remaining = n;
    while (remaining > 0) {
        int index = k / factorial;
        result.push_back(char('0' + nums[index]));
        nums.erase(nums.begin() + index);
        
        k %= factorial;
        if (remaining > 1) 
            factorial /= (remaining - 1);
        remaining--;
    }
    
    return result;
}

int main() {
    int n = 4, k = 17;
    cout << "n = " << n << ", k = " << k
         << " -> " << getKthPermutation(n, k) << "\n";
    
    // Additional examples
    n = 3; k = 5;
    cout << "n = " << n << ", k = " << k
         << " -> " << getKthPermutation(n, k) << "\n";
    
    return 0;
}
