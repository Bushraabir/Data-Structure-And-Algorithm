/*  
Ternary Search is a searching algorithm used to find a target element in a  
**sorted** array by repeatedly dividing the search range into **three** parts  
instead of two (like Binary Search).  

It is useful when:  
- The dataset is large  
- The array is sorted (ascending order)  
- We want to minimize the number of comparisons in some scenarios  
- Sometimes used in unimodal functions to find minima or maxima  

Definition:  
Given a sorted array of size N and a target value X,  
- Calculate two mid points: mid1 and mid2  
- If X equals arr[mid1], return mid1  
- If X equals arr[mid2], return mid2  
- If X is less than arr[mid1], search in the left third  
- If X is greater than arr[mid2], search in the right third  
- Otherwise, search in the middle third  

Example:  
Array: [10, 20, 30, 40, 50, 60]  
Target: 40  

Process:  
    Step 1: mid1 = low + (high-low)/3  
            mid2 = high - (high-low)/3  
            → mid1 = 1 → arr[1] = 20  
              mid2 = 4 → arr[4] = 50  
            Target 40 lies between mid1 and mid2 → search middle part  

Working Principle:  
1. Initialize `low = 0` and `high = N - 1`  
2. While `low <= high`:  
    a. mid1 = low + (high - low) / 3  
    b. mid2 = high - (high - low) / 3  
    c. If arr[mid1] == target → return mid1  
    d. If arr[mid2] == target → return mid2  
    e. If target < arr[mid1] → high = mid1 - 1  
    f. Else if target > arr[mid2] → low = mid2 + 1  
    g. Else → low = mid1 + 1, high = mid2 - 1  
3. If not found, return -1  

Time Complexity:  
    - Best Case: O(1) → Found at mid1 or mid2  
    - Average Case: O(log₃ N)  
    - Worst Case: O(log₃ N) → Dividing into 3 parts each time  
Space Complexity: O(1) for iterative version  

Stable: Not applicable (searching only)  
Adaptive: No  

Constraints:  
- Works only on **sorted** arrays  
- For unsorted arrays, must sort first (O(N log N))  
*/

#include <iostream>
#include <vector>
using namespace std;

// Iterative Ternary Search
int ternarySearch(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == target)
            return mid1; // Found at mid1
        if (arr[mid2] == target)
            return mid2; // Found at mid2

        if (target < arr[mid1])
            high = mid1 - 1; // Search in left third
        else if (target > arr[mid2])
            low = mid2 + 1; // Search in right third
        else {
            low = mid1 + 1;   // Search in middle third
            high = mid2 - 1;
        }
    }
    return -1; // Not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    int target = 40;

    cout << "Array elements (sorted):\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\nSearching for: " << target << "\n";

    int index = ternarySearch(arr, target);

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
Array: 10 20 30 40 50 60  
Target: 40  

Step 1: low=0, high=5  
        mid1 = 0 + (5-0)/3 = 1 → arr[1]=20  
        mid2 = 5 - (5-0)/3 = 4 → arr[4]=50  
        Target 40 lies between mid1 and mid2 → low=2, high=3  

Step 2: low=2, high=3  
        mid1 = 2 + (3-2)/3 = 2 → arr[2]=30  
        mid2 = 3 - (3-2)/3 = 3 → arr[3]=40 → Match found → Return 3  

Final Output:  
Element found at index: 3  
*/
