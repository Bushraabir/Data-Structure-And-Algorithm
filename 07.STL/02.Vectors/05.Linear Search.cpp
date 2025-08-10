/*
Linear Search – Sequential Search in an Array/Vector

Problem Statement:
- Given an array/vector of integers and a target value.
- Task: Find the index of the target in the vector.
- If the target is present, return its index (0-based).
- If the target is not present, return -1.

Example:
vec = {10, 20, 30, 40, 50}, target = 30
Process:
    Compare target with vec[0] → 10 != 30
    Compare target with vec[1] → 20 != 30
    Compare target with vec[2] → 30 == 30 
Answer: index = 2

Algorithm Steps:
1. Iterate from i = 0 to n-1
2. If vec[i] == target → return i
3. If loop ends without finding → return -1

Time Complexity:
- Best case: O(1) (if target is at index 0)
- Worst case: O(N) (if target is last or not present)
- Average case: O(N)

Space Complexity:
- O(1) extra space (in-place search)
*/

/* -------------------- FUNCTION DEFINITION -------------------- */
#include <iostream>
#include <vector>
using namespace std;

// Function to perform Linear Search
int linearSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target)
            return i; // Return index if target found
    }
    return -1; // Target not found
}


int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    int index = linearSearch(vec, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << "\n";
    else
        cout << "Element " << target << " not found in the vector.\n";

    return 0;
}
