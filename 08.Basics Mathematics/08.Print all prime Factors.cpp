#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------
PRINT ALL PRIME FACTORS OF A NUMBER
-------------------------------------------------
We’ll implement:
1. Naive Approach
2. Optimized Naive Approach
3. Most Optimized Approach (School Method)
-------------------------------------------------
*/

// 🔹 Utility: Prime Check using O(sqrt(n))
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

/*
-------------------------------------------------
1️⃣ Naive Approach
- Loop i = 2 to n
- If i divides n, check if i is prime
- Print/store if prime
Time Complexity: O(n * sqrt(n))
-------------------------------------------------
*/
vector<int> primeFactorsNaive(int n) {
    vector<int> factors;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            factors.push_back(i);
        }
    }
    return factors;
}

/*
-------------------------------------------------
2️⃣ Optimized Naive Approach
- Loop i = 2 to sqrt(n)
- If i divides n, check i and n/i for primality
- Avoid duplicates for perfect squares
Time Complexity: Approx O(sqrt(n) * sqrt(n)) → O(n)
-------------------------------------------------
*/
vector<int> primeFactorsOptimizedNaive(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i)) factors.push_back(i);
            int other = n / i;
            if (other != i && isPrime(other)) factors.push_back(other);
        }
    }
    sort(factors.begin(), factors.end()); // To keep output sorted
    return factors;
}

/*
-------------------------------------------------
3️⃣ Most Optimized Approach (School Method)
- Divide n by smallest possible prime factor repeatedly
- Increment i and continue
- If after loop n > 1, add it as last prime factor
Time Complexity: O(sqrt(n) + log n)
-------------------------------------------------
*/
vector<int> primeFactorsMostOptimized(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) { // Keep dividing by i
            factors.push_back(i);
            n /= i;
        }
    }
    if (n != 1) factors.push_back(n); // Last remaining prime
    // Remove duplicates since prime factors are unique
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    return factors;
}

/*
-------------------------------------------------
Main: Test the three methods
-------------------------------------------------
*/
int main() {
    int n = 780;

    cout << "Number: " << n << "\n";

    // 1. Naive
    auto f1 = primeFactorsNaive(n);
    cout << "Naive Approach Factors: ";
    for (int f : f1) cout << f << " ";
    cout << "\n";

    // 2. Optimized Naive
    auto f2 = primeFactorsOptimizedNaive(n);
    cout << "Optimized Naive Factors: ";
    for (int f : f2) cout << f << " ";
    cout << "\n";

    // 3. Most Optimized
    auto f3 = primeFactorsMostOptimized(n);
    cout << "Most Optimized Factors: ";
    for (int f : f3) cout << f << " ";
    cout << "\n";

    return 0;
}
