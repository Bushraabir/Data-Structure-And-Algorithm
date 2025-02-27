// Problem:
// Given a positive decimal number, convert it to its binary representation.
// Implement a function named binary that takes a decimal number and returns its binary equivalent as an integer.

#include <iostream>
using namespace std;


int binary(int dec) {
    int ans = 0, pow = 1;
    while(dec > 0) {
        int rem = dec % 2;
        dec /= 2;
        ans += (rem * pow);
        pow *= 10;  
    }
    return ans;
}

int main(){
    int decimal;
    cout << "Enter any decimal number: ";
    cin >> decimal;

    cout << "The binary of " << decimal << " is " << binary(decimal) << endl;
    return 0;
}
