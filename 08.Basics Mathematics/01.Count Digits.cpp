/*
You are given an integer n. You need to return the number of digits in the number.
The number will have no leading zeroes, except when the number is 0 itself.
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;
    int count = (int)(log10(n)+1);

    return count;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    
    int result = countDigits(n);
    cout << "Number of digits: " << result << endl;
    
    return 0;
}