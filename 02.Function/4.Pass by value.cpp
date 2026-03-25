// Problem: Demonstrate pass-by-value in C++ by creating a function that attempts to swap two numbers.
// The function swapNumbers takes two integer parameters by value, swaps them inside the function,
// and prints the swapped values. In the main function, define two integers, print their values,
// call the swapNumbers function, and print their values again to show that the original variables remain unchanged.

#include <iostream>
using namespace std;

void swapNumbers(int a, int b) { // Pass by value: a and b are copies of the original variables passed from main
                                // Any changes to a and b inside this function will not affect the original variables in main
                                // pass by reference would require using reference parameters (int &a, int &b) instead of value parameters (int a, int b)
                                // pass by pointer would require using pointer parameters (int *a, int *b) and dereferencing them inside the function
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



/*

    there are three ways to pass arguments to a function in C++:
    1. Pass by Value: In this method, a copy of the actual parameter is passed to the function. 
       Changes made to the parameter inside the function do not affect the original variable outside the function.

        - this is used when you want to ensure that the original variable remains unchanged after the function call.
        - it is also used when the data being passed is small (like primitive data types), as it can be more efficient than pass by reference or pass by pointer for small data.

    2. Pass by Reference: In this method, a reference to the actual parameter is passed to the function.
         Changes made to the parameter inside the function will affect the original variable outside the function.

        - this is used when you want the function to modify the original variable passed from the caller.
        - it is also used when the data being passed is large (like objects or structures), as it can be more efficient than pass by value for large data, since it avoids copying the entire data.

    3. Pass by Pointer: In this method, a pointer to the actual parameter is passed to the function.
       Changes made to the parameter inside the function will affect the original variable outside the function.

        - this is used when you want the function to modify the original variable passed from the caller, similar to pass by reference.
        - it is also used when you want to pass null pointers or when you want to indicate that a parameter is optional, as references cannot be null.

*/