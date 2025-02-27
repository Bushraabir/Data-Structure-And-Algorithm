// In C++, we can pass an array by reference to a function by 
// specifying the array's size in the parameter.
// This approach ensures that the function receives the entire
// array (without decaying it to a pointer)
// and retains the size information of the array.

#include <iostream>
using namespace std;

void modifyArray(int (&arr)[6]) {
    for (int i = 0; i < 6; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};

    cout << "Original array: ";
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    modifyArray(a);

    cout << "Modified array (each element doubled): ";
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
