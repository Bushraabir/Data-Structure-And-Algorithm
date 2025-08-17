/*
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.
*/

#include <iostream>
using namespace std;    

int sumOfFirstN(int n) {
    if (n == 0) return 0; // Base case: if n is 0, return 0
    return n + sumOfFirstN(n - 1); // Recursive call with n-1
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int result = sumOfFirstN(n); // Call the function 
    cout << "Sum of first " << n << " natural numbers is: " << result << endl;

    return 0;
}