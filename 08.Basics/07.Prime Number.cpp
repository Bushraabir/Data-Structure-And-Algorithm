/*
You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.


A prime number is a number which has no divisors except 1 and itself.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    if (n <= 3) return true; // 2 and 3 are prime numbers

    // Check for factors from 2 to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // If n is divisible by i, it's not prime
    }
    
    return true; // If no factors found, n is prime
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    bool result = isPrime(n);
    if (result) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}