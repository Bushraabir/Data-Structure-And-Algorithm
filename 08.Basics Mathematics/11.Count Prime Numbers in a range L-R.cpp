#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Count prime numbers within multiple given ranges [L, R] efficiently.

    Constraints:
    - Number of queries Q can be up to 10^5.
    - Maximum R can be up to 10^6.

    Naive Approach:
    - For each query, check each number from L to R for primality using trial division.
    - Time complexity is too large: O(Q * (R-L+1) * sqrt(R)) — not feasible for given constraints.

    Intermediate Optimization:
    - Precompute primes up to max R using Sieve of Eratosthenes (O(N log log N)).
    - For each query, check each number in [L, R] against sieve boolean array in O(1).
    - Still costly: O(Q * (R-L+1)) can be up to 10^11 operations — still not feasible.

    Optimal Solution: Sieve + Prefix Sum Array
    - Precompute sieve once.
    - Convert sieve boolean array into prefix sum array where prefix[i] = count of primes up to i.
    - For each query [L, R], answer = prefix[R] - prefix[L-1] in O(1).
    - Overall time: O(N log log N + N + Q) which is efficient for constraints.

    Intuition:
    - Sieve marks primes efficiently.
    - Prefix sum enables quick range queries without repeated iteration.
*/

const int MAXN = 1'000'000;
vector<int> prefixPrimeCount(MAXN + 1, 0);

// Function to generate sieve and prefix sums
void generateSievePrefix() {
    // Step 1: Create a boolean prime vector initialized to true
    vector<bool> prime(MAXN + 1, true);
    prime[0] = prime[1] = false; // 0 and 1 are not primes

    // Step 2: Sieve of Eratosthenes to mark non-primes
    for (int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                prime[j] = false;
            }
        }
    }

    // Step 3: Build prefix sum array of prime counts
    int count = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i]) count++;
        prefixPrimeCount[i] = count;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generateSievePrefix();

    int Q; // Number of queries
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;

        // Handle edge case if L == 1, prefixPrimeCount[0] is 0 anyway
        int answer = prefixPrimeCount[R] - prefixPrimeCount[L - 1];
        cout << answer << "\n";
    }

    return 0;
}
