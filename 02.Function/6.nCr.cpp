// Problem: Given two integers n and r, calculate nCr (the number of combinations) using the formula:
// nCr = n! / (r! * (n - r)!)
// Implement a recursive function fac(int n) to compute the factorial of n,
// then use it in the nCr function to compute the result.

#include <iostream>
using namespace std;

int fac(int n) {
    if(n <= 1)
        return 1;
    return n * fac(n - 1);
}

int nCr(int n, int r) {
    return fac(n) / (fac(r) * fac(n - r));
}

int main() {
    int n, r;
    cout << "Enter any number for nCr: \n n: ";
    cin >> n;
    cout << "r: ";
    cin >> r;
    
    cout << nCr(n, r) << endl;
    return 0;
}
