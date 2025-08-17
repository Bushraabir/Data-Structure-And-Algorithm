/*  
Binary Search is an efficient searching algorithm for finding a target element  
in a **sorted** array by repeatedly dividing the search range in half.  

It is widely used when:  
- The dataset is large  
- The array is sorted (ascending or descending order)  
- Performance is important  

Definition:
Given a sorted array of size N and a target value X,  
- Compare X with the middle element of the array.  
- If they match, return the index.  
- If X is smaller, search the left half.  
- If X is larger, search the right half.  
- Repeat until the element is found or the search space becomes empty.  

Example:
Array: [10, 20, 30, 40, 50]  
Target: 30  

Process:  
    Step 1: mid = (0+4)/2 = 2 → arr[2] = 30 → match found at index 2  

Working Principle:
1. Initialize `low = 0` and `high = N - 1`.  
2. While `low <= high`:  
    a. Calculate `mid = (low + high) / 2`.  
    b. If `arr[mid] == target`, return `mid`.  
    c. If `arr[mid] > target`, set `high = mid - 1` (search left half).  
    d. If `arr[mid] < target`, set `low = mid + 1` (search right half).  
3. If not found, return -1.  

Time Complexity:
    - Best Case: O(1) → Target found at middle.  
    - Average Case: O(log N)  
    - Worst Case: O(log N) → Keep halving until one element remains.  
Space Complexity:
    - O(1) for iterative version  
    - O(log N) for recursive version (stack space)  

Stable: Not applicable (searching only)  
Adaptive: No  

Constraints:
- Works only on **sorted** arrays.  
- For unsorted arrays, must sort first (which adds O(N log N) time).  
*/

#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int binarySearch(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow

        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] > target)
            high = mid - 1; // Search left half
        else
            low = mid + 1; // Search right half
    }
    return -1; // Not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;

    cout << "Array elements (sorted):\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\nSearching for: " << target << "\n";

    int index = binarySearch(arr, target);

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

Step 1: low = 0, high = 4  
        mid = (0+4)/2 = 2 → arr[2] = 30 → Match found → Return 2  

Final Output:
Element found at index: 2
*/
