/*  
Linear Search (also called Sequential Search) is the simplest searching algorithm.  
It checks each element in the list sequentially until the target element is found  
or the entire list has been searched.  

It is widely used when:  
- The list is unsorted  
- The dataset is small  
- Simplicity is more important than efficiency  

Definition:
Given an array of size N and a target value X,  
- Start from the first element and compare each element with X.  
- If an element matches X, return its index (or position).  
- If the end of the array is reached without a match, return -1 (not found).  

Example:
Array: [10, 20, 30, 40, 50]  
Target: 30  
Process:  
    Compare 10 → not match  
    Compare 20 → not match  
    Compare 30 → match found at index 2  

Working Principle:
1. Iterate through each element of the array from index 0 to N-1.  
2. Compare the current element with the target.  
3. If found, return the index immediately.  
4. If not found after the loop ends, return -1.  

Time Complexity:
    - Best Case: O(1) → Target found at first position.  
    - Average Case: O(N)  
    - Worst Case: O(N) → Target not present or found at last position.  
Space Complexity:
    - O(1) (No extra space used apart from a few variables)  

Stable: Yes (Order of elements is not changed)  
Adaptive: No  

Constraints:
- Works on sorted or unsorted arrays.  
- Slower than binary search for large sorted datasets.  
*/

#include <iostream>
#include <vector>
using namespace std;

// Linear search function
int linearSearch(const vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;

    cout << "Array elements:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\nSearching for: " << target << "\n";

    int index = linearSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index: " << index << "\n";
    } else {
        cout << "Element not found\n";
    }

    return 0;
}

/*
Example Dry Run:
----------------
Array: 10 20 30 40 50
Target: 30

Step 1: Compare arr[0] (10) → Not match
Step 2: Compare arr[1] (20) → Not match
Step 3: Compare arr[2] (30) → Match found → Return 2

Final Output:
Element found at index: 2
*/
