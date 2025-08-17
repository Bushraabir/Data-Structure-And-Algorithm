/*
Count contiguous subarrays with sum = K.
You are given an integer N and a target K. You need to count how many
contiguous subarrays of the input array sum up exactly to K.

Approach: 
 - Use a prefix‑sum + hashing technique.
 - As you iterate, keep track of the running sum `currentSum`.
 - Store in an unordered_map how many times each prefix‑sum has occurred.
 - For each new `currentSum`, look up `currentSum - K` in the map:
     the value tells you how many prior subarrays end here with sum K.
 - Update the map with the new `currentSum`.

Time Complexity: O(N) on average (each element causes O(1) map operations)  
Space Complexity: O(N) (for storing prefix‑sum frequencies in the map)  
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns the count of contiguous subarrays whose sum equals K
long long countSubarraysWithSumK(int n, long long K) {
    unordered_map<long long, int> freq;
    long long currentSum = 0;
    long long count = 0;

    // Base case: prefix sum = 0 has occurred once
    freq[0] = 1;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        currentSum += x;

        // If (currentSum - K) was seen before, those indices form valid subarrays
        if (freq.find(currentSum - K) != freq.end()) {
            count += freq[currentSum - K];
        }

        // Record this prefix sum
        freq[currentSum]++;
    }

    return count;
}

int main() {
    int n;
    long long K;
    cout << "Enter N (array size) and K (target sum): ";
    cin >> n >> K;

    cout << "Enter " << n << " array elements:\n";
    long long result = countSubarraysWithSumK(n, K);

    cout << "Number of subarrays with sum " << K << " is " << result << "\n";
    return 0;
}
// Time Complexity: O(N) on average (due to hash map operations)
// Space Complexity: O(N) (for storing prefix sums in the hash map)