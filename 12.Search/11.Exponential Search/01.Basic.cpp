/*  
Exponential Search is a **search algorithm** designed for **sorted arrays**  
that works faster than Binary Search in cases where the target element  
is near the beginning of the array.  

It is useful when:  
- The array is **sorted** but we do not know its size in advance (unbounded search)  
- We want to quickly find the range where the element might exist before doing binary search  
- Suitable for infinite or very large datasets where reading sequentially is costly  

Definition:  
Exponential Search first checks elements at indices:  
1, 2, 4, 8, 16, ... until it finds a range containing the target.  
Then it applies **Binary Search** in that range.  

Example:  
Array: [2, 3, 4, 10, 15, 18, 21, 28, 36, 45]  
Target: 15  

Process:  
    Step 1: Check index 1 → 3 < 15  
    Step 2: Check index 2 → 4 < 15  
    Step 3: Check index 4 → 15 == target → found  

If not found during doubling step:  
    - Suppose target is 28 →  
        Step 1: 1 → 3 < 28  
        Step 2: 2 → 4 < 28  
        Step 3: 4 → 15 < 28  
        Step 4: 8 → 36 > 28 → range is [4, 8]  
        Step 5: Apply binary search in that range  

Working Principle:  
1. Start with index = 1  
2. While index < size and arr[index] <= target → double index  
3. Perform binary search between index/2 and min(index, size-1)  
4. Return position if found, else -1  

Time Complexity:  
    - O(log i) where i is the position of the target  
    - Worst case: O(log n)  
Space Complexity:  
    - O(1) (iterative implementation)  

Stable: Not applicable (search algorithm)  
Adaptive: Yes, faster if element is near start  

Constraints:  
- Array must be **sorted**  
- Works well for unbounded/infinite lists or large arrays when position is small  
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int> &arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int exponentialSearch(const vector<int> &arr, int target) {
    if (arr.empty()) return -1;
    if (arr[0] == target) return 0;

    int index = 1;
    int n = arr.size();
    while (index < n && arr[index] <= target) {
        index *= 2;
    }

    return binarySearch(arr, index/2, min(index, n-1), target);
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 15, 18, 21, 28, 36, 45};
    int target = 15;

    int result = exponentialSearch(arr, target);
    if (result != -1)
        cout << "Element found at index " << result << "\n";
    else
        cout << "Element not found\n";

    return 0;
}

/*  
Example Dry Run:  
----------------  
Array: [2, 3, 4, 10, 15, 18, 21, 28, 36, 45]  
Target: 15  

Step 1: arr[0] = 2 ≠ target  
Step 2: index=1 → arr[1]=3 < 15  
Step 3: index=2 → arr[2]=4 < 15  
Step 4: index=4 → arr[4]=15 == target → found at index 4  

Final Output:  
Element found at index 4  
*/
