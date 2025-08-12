/*
Given an integer x, return true if x is a , and false otherwise.

*/

#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(int x) {
    int number  = x;

    if (x < 0) return false; // Negative numbers are not palindromes
    if (x < 10 ) return true; // single digit is a palindrome

    int reversed = 0;
    while( number>0){
        reversed = reversed * 10 + number % 10; // Append the last digit to the reversed number
        number /= 10; // Remove the last digit from x
    }

    if(reversed == x) {
        return true; 
    } else {
        return false; 
    }
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    bool result = isPalindrome(n);
    if (result) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }

    return 0;
}