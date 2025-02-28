// Given an array of integers, this program finds the minimum
// and maximum elements and swaps them.
// It first determines the indices of the minimum and maximum
// values and then swaps these elements.
// Finally, it prints the modified array.

#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 3, 9, 1, 7};
    int size = sizeof(a) / sizeof(a[0]);
    
    int minIndex = 0, maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (a[i] < a[minIndex])
            minIndex = i;
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }
    
   
    swap(a[minIndex], a[maxIndex]);
    
    cout << "Array after swapping minimum and maximum elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
