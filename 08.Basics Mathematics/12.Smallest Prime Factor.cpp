#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Efficient prime factorization for multiple queries using Smallest Prime Factor (SPF) array.

    Constraints:
    - Number of queries Q can be large.
    - Each number N can be up to 10^5.

    Naive Approach:
    - For each query, factorize N by checking divisors up to sqrt(N).
    - Time complexity O(Q * sqrt(N)) which is too slow for large Q.

    Optimal Solution:
    - Precompute SPF array using a modified sieve.
    - SPF[i] stores the smallest prime factor of i.
    - Factorization of any number n is done in O(log n) by repeatedly dividing by SPF[n].

    Intuition:
    - Precompute smallest prime factors for all numbers once.
    - For each query, repeatedly divide the number by its SPF to get all prime factors including duplicates.
*/

const int MAXN = 100000;
int SPF[MAXN + 1];  // SPF[i] = smallest prime factor of i

// Function to precompute SPF array
void computeSPF() {
    // Initialize SPF[i] = i for all i
    for (int i = 1; i <= MAXN; i++) {
        SPF[i] = i;
    }

    // 0 and 1 are not primes but handled by SPF[i] = i initialization
    SPF[1] = 1;

    // Modified sieve to fill SPF for every number
    for (int i = 2; i * i <= MAXN; i++) {
        // If i is prime (SPF[i] == i), mark multiples
        if (SPF[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                // Update SPF[j] only if not updated before (to keep smallest prime factor)
                if (SPF[j] == j) {
                    SPF[j] = i;
                }
            }
        }
    }
}

// Function to get prime factorization of n using SPF array
vector<int> getPrimeFactorization(int n) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(SPF[n]);  // Add smallest prime factor
        n /= SPF[n];                // Divide n by smallest prime factor
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    computeSPF(); // Precompute SPF array once

    int Q; // Number of queries
    cin >> Q;

    while (Q--) {
        int n;
        cin >> n;

        // Get prime factors including duplicates
        vector<int> factors = getPrimeFactorization(n);

        // Print prime factors for the query
        for (int factor : factors) {
            cout << factor << " ";
        }
        cout << "\n";
    }

    return 0;
}
