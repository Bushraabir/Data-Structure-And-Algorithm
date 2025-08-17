/*  
Jump Search is a **search algorithm** for **sorted arrays** that  
works by jumping ahead by fixed steps instead of checking every element.  

It is useful when:  
- The array is sorted  
- We want better performance than Linear Search but with simpler logic than Binary Search  
- Useful for scenarios with slow random access (like disk-based storage)  

Definition:  
Jump Search moves ahead in blocks of size `√n` until it finds a block  
where the target could be present, and then performs a linear search  
within that block.  

Example:  
Array: [2, 3, 4, 10, 15, 18, 21, 28, 36, 45]  
Target: 18  

Process:  
    Step 1: Jump by step=√10 ≈ 3 → check arr[3]=10 < 18 → continue  
    Step 2: Jump to arr[6]=21 > 18 → target must be between indices [4, 6]  
    Step 3: Linear search from index 4 → arr[5]=18 → found  

Working Principle:  
1. Choose jump size = √n (n = size of array)  
2. Start at index 0, jump forward by step size until:  
    - Target found, OR  
    - Current element > target, OR  
    - End of array reached  
3. Perform linear search in the last block where the target could be  
4. Return index if found, else -1  

Time Complexity:  
    - O(√n) for both best and worst case  
Space Complexity:  
    - O(1)  

Stable: Not applicable (search algorithm)  
Adaptive: No  

Constraints:  
- Array must be **sorted**  
- Performs fewer comparisons than Linear Search in large arrays  
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(const vector<int> &arr, int target) {
    int n = arr.size();
    if (n == 0) return -1;

    int step = sqrt(n);
    int prev = 0;

    // Jump ahead in blocks
    while (prev < n && arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    // Linear search within the block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) return i;
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 15, 18, 21, 28, 36, 45};
    int target = 18;

    int result = jumpSearch(arr, target);
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
Target: 18  
Step size = √10 ≈ 3  

Step 1: Check arr[2] = 4 < 18 → jump to index 3  
Step 2: Check arr[5] = 18 == target → found at index 5  

Final Output:  
Element found at index 5  
*/
