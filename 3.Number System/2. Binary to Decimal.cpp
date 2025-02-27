// Problem:
// Given a positive integer representing a binary number, convert it to its decimal representation.
// Implement a function named binaryToDecimal that takes a binary number (as an integer)
// and returns its decimal equivalent. In the main function, prompt the user for a binary number
// and output its decimal representation.

#include <iostream>
using namespace std;


int binaryToDecimal(int bin) {
    int dec = 0, base = 1;
    while(bin > 0) {
        int rem = bin % 10;
        bin /= 10;
        dec += rem * base;
        base *= 2;
    }
    return dec;
}

int main(){
    int binary;
    cout << "Enter any binary number: ";
    cin >> binary;
    
    cout << "The decimal of " << binary << " is " << binaryToDecimal(binary) << endl;
    return 0;
}
