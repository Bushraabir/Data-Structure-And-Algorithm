/*  
Lower Bound & Upper Bound Search are binary search–based algorithms used to  
find positions of elements in a **sorted** array.  

They are especially useful in competitive programming and STL (Standard Template Library) functions.  

📌 Lower Bound:  
- Finds the **first position** where the target can be inserted without breaking the sorting order.  
- If the target exists, returns the index of its **first occurrence**.  
- If the target does not exist, returns the index of the next greater element.  

📌 Upper Bound:  
- Finds the **first position** where an element **greater** than the target appears.  
- Always returns the index of the first element strictly greater than the target.  

Example:
Array: [10, 20, 20, 30, 40]  
Target: 20  

Lower Bound → index 1 (first 20)  
Upper Bound → index 3 (first element > 20, which is 30)  

Working Principle (Iterative Binary Search logic):  
1. Set `low = 0`, `high = N`.  
2. While `low < high`:  
    a. mid = (low + high) / 2  
    b. For Lower Bound:  
       - If `arr[mid] < target`, move `low = mid + 1`  
       - Else, move `high = mid`  
    c. For Upper Bound:  
       - If `arr[mid] <= target`, move `low = mid + 1`  
       - Else, move `high = mid`  
3. Return `low` as the position.  

Time Complexity:  
    - Best Case: O(1) (if found immediately)  
    - Average & Worst Case: O(log N)  
Space Complexity: O(1) (iterative)  

Stable: Not applicable (searching only)  
Adaptive: No  

Constraints:  
- Works only on **sorted** arrays.  
*/

#include <iostream>
#include <vector>
using namespace std;

// Lower Bound Implementation
int lowerBound(const vector<int> &arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Upper Bound Implementation
int upperBound(const vector<int> &arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    vector<int> arr = {10, 20, 20, 30, 40};
    int target = 20;

    cout << "Array elements (sorted):\n";
    for (int val : arr) cout << val << " ";
    cout << "\n\nTarget: " << target << "\n";

    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    cout << "Lower Bound index: " << lb << "\n";
    cout << "Upper Bound index: " << ub << "\n";

    return 0;
}

/*
Example Dry Run:
----------------
Array: 10 20 20 30 40
Target: 20

Lower Bound:
    low=0, high=5 → mid=2 → arr[2]=20 (>= target) → high=2
    low=0, high=2 → mid=1 → arr[1]=20 (>= target) → high=1
    low=0, high=1 → mid=0 → arr[0]=10 (< target) → low=1
    low=1, high=1 → stop → return 1

Upper Bound:
    low=0, high=5 → mid=2 → arr[2]=20 (<= target) → low=3
    low=3, high=5 → mid=4 → arr[4]=40 (> target) → high=4
    low=3, high=4 → mid=3 → arr[3]=30 (> target) → high=3
    low=3, high=3 → stop → return 3

Final Output:
Lower Bound index: 1
Upper Bound index: 3
*/
