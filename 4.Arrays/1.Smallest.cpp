// Problem:
// Given an array of 6 integers, find and print the smallest value in the array.


#include <iostream>
using namespace std;

int main() {
    int a[6];
    int small = INT16_MAX; 

    cout << "Enter 6 values: ";
    for (int j = 0; j < 6; j++) {
        cin >> a[j];

        if (a[j] < small)
            small = a[j]; 
    }

    cout << "The smallest value is " << small << endl;
    return 0;
}
