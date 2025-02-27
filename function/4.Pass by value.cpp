// Problem: Demonstrate pass-by-value in C++ by creating a function that attempts to swap two numbers.
// The function swapNumbers takes two integer parameters by value, swaps them inside the function,
// and prints the swapped values. In the main function, define two integers, print their values,
// call the swapNumbers function, and print their values again to show that the original variables remain unchanged.

#include <iostream>
using namespace std;

void swapNumbers(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapNumbers function: a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 10, y = 20;
    cout << "Before calling swapNumbers: x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After calling swapNumbers: x = " << x << ", y = " << y << endl;
    return 0;
}
