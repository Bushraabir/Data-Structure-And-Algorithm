// Given an array of integers, this program calculates the sum
// and product of all the numbers in the array.
// It iterates through the array, updating the sum and
// product for each element, and then prints the results.

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    int product = 1;

    for (int i = 0; i < size; i++) {
        sum += a[i];
        product *= a[i];
    }

    cout << "Sum of array elements: " << sum << endl;
    cout << "Product of array elements: " << product << endl;

    return 0;
}
