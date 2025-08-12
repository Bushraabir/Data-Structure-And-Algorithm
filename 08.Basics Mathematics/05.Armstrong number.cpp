/*
You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.


An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

*/

#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
    int number = n;
    int sum = 0;
    int digits = 0;

    // Count the number of digits
    while (n > 0) {
        n /= 10;
        digits++;
    }


    // Calculate the sum of the digits raised to the power of the number of digits
    while (number > 0) {
        int digit = number % 10;
        sum += pow(digit, digits);
        number /= 10;
    }

    return sum == n; // Check if the sum is equal to the original number
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    bool result = isArmstrong(n);
    if (result) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }

    return 0;
}