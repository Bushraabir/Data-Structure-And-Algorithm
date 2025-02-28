// This program performs a linear search on a vector of integers.
// It defines a function named linearSearch that takes a vector and a target value,
// and returns the index of the target if found, otherwise returns -1.
// The function iterates through the vector sequentially to locate the target element.

#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search on a vector
int linearSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target)
            return i; // Return the index if target is found
    }
    return -1; // Return -1 if target is not found
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    int target;
    
    cout << "Enter the target value: ";
    cin >> target;
    
    int index = linearSearch(vec, target);
    
    if(index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element " << target << " not found in the vector." << endl;
    
    return 0;
}
