/*  
Interpolation Search is a **search algorithm** for **sorted arrays**  
that estimates the position of the target based on the array's values,  
instead of always picking the middle like Binary Search.  

It is useful when:  
- The array is sorted  
- The elements are **uniformly distributed** (difference between values is roughly constant)  
- We want better performance than Binary Search in certain datasets  

Definition:  
Instead of picking the middle index, Interpolation Search guesses the  
position of the target by proportionally dividing the search space  
according to the target's value relative to the ends.  

Example:  
Array: [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]  
Target: 70  

Process:  
    Step 1: pos = low + [(target - arr[low]) * (high - low)] / (arr[high] - arr[low])  
            = 0 + [(70 - 10) * (9 - 0)] / (100 - 10)  
            = 0 + (60 * 9) / 90 = 6 → arr[6] = 70 → found  

Working Principle:  
1. Set low = 0, high = n-1  
2. While target is within arr[low] and arr[high]:  
    - Estimate position:  
      pos = low + [(target - arr[low]) * (high - low)] / (arr[high] - arr[low])  
    - If arr[pos] == target → return pos  
    - If arr[pos] < target → low = pos + 1  
    - If arr[pos] > target → high = pos - 1  
3. If not found, return -1  

Time Complexity:  
    - Best case: O(1) (target found on first try)  
    - Average case: O(log log n) for uniformly distributed data  
    - Worst case: O(n) (poor distribution)  
Space Complexity:  
    - O(1)  

Stable: Not applicable (search algorithm)  
Adaptive: Yes (fewer steps if close to correct guess)  

Constraints:  
- Array must be **sorted**  
- Works best when data is uniformly distributed  
- Can be inefficient for skewed datasets  
*/

#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            return (arr[low] == target) ? low : -1;
        }

        // Estimate position
        int pos = low + ((double)(target - arr[low]) * (high - low) /
                         (arr[high] - arr[low]));

        if (arr[pos] == target) return pos;
        else if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 70;

    int result = interpolationSearch(arr, target);
    if (result != -1)
        cout << "Element found at index " << result << "\n";
    else
        cout << "Element not found\n";

    return 0;
}

/*  
Example Dry Run:  
----------------  
Array: [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]  
Target: 70  

Step 1: low=0, high=9  
        pos = 0 + ((70 - 10) * (9 - 0)) / (100 - 10)  
            = (60 * 9) / 90 = 6  
        arr[6] = 70 → found  

Final Output:  
Element found at index 6  
*/
