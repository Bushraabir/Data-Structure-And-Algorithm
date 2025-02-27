// Problem:
// Given a negative decimal number, print its two's complement binary representation.
// Assume a fixed 32-bit representation for the conversion.
// Implement a function named twoComplementBinary that returns a string representing the 
// 32-bit two's complement form of the given negative number, and call it in the main function.

#include <iostream>
#include <string>
using namespace std;


string twoComplementBinary(int n) {
    string binary = "";
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1; // right shift ,Bitwise AND with 1
                                // 
                                // in case of decimal number system
                                //  a << b --> a * 2^(b)
                                //  b >> a --> a / 2^(b)
                                // 
                                // 
                                // in case of binary number system
                                //  a << b --> value will shift left by b position and the new position will contain 0
                                //  b >> a --> value will shift right by b position and the new position will contain 0
                                
        binary.push_back(bit + '0');
    }
    return binary;
}

int main() {
    int n;
    cout << "Enter a negative decimal number: ";
    cin >> n;
    
    if(n >= 0) {
        cout << "Please enter a negative number." << endl;
        return 1;
    }
    
    cout << "The two's complement binary representation of " << n << " is: " 
         << twoComplementBinary(n) << endl;
    
    return 0;
}
