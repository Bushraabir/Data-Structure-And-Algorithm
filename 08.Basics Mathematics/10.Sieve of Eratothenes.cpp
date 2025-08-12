#include <bits/stdc++.h>
using namespace std;

/*
    Function: sieveOfEratosthenes
    Purpose: Efficiently find and print all prime numbers up to n using the Sieve of Eratosthenes algorithm.

    Intuition:
    - Every composite number has at least one prime factor.
    - By iteratively marking multiples of primes starting from the smallest prime (2),
      we can eliminate all composite numbers.
    - Starting to mark multiples from i*i is safe because any smaller multiple
      would have already been marked by a smaller prime factor.
*/

void sieveOfEratosthenes(int n) {
    // Step 1: Create a boolean vector 'prime' of size n+1.
    // We use n+1 to include the number n itself.
    // Initialize all entries as true to assume all numbers are prime initially.
    vector<bool> prime(n + 1, true);

    // 0 and 1 are NOT prime numbers by definition.
    prime[0] = false;
    prime[1] = false;

    // Step 2: Iterate from i = 2 to sqrt(n)
    // We only need to check up to sqrt(n) because:
    // - If n is composite, it must have a factor less than or equal to sqrt(n).
    for (int i = 2; i * i <= n; i++) {
        // If i is still marked prime, it means it is a prime number.
        if (prime[i]) {
            // Step 3: Mark all multiples of i as not prime (composite).
            // Start from i*i because:
            // - All smaller multiples of i (like i*2, i*3, ..., i*(i-1)) were already marked
            //   by smaller primes.
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    // Step 4: After the sieve is complete, print all numbers marked as prime.
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    
    sieveOfEratosthenes(n);

    return 0;
}
