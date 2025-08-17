/*  
Bitmask Search is a **combinatorial search technique**  
that uses **binary representation** (bitmasks) to represent subsets or states.  

It is useful when:  
- The problem involves checking all subsets of a set  
- We want a compact and efficient way to store/iterate over choices  
- The number of elements `n` is small (usually n ≤ 20) so that 2^n is feasible  

Definition:  
A **bitmask** is an integer where the i-th bit (0 or 1)  
represents whether the i-th element is included in a subset or  
whether a certain property/state is active.  

Example Problem:  
Given numbers [1, 2, 3], find all possible subsets.  

Process:  
    Step 1: Total subsets = 2^n = 8  
    Step 2: For each number from 0 to 7 (binary 000 to 111),  
            interpret bits: 1 = include element, 0 = exclude  
    Step 3: Generate and process each subset  

Working Principle:  
1. Represent a subset or state as a binary number of length n  
2. Loop over all integers from 0 to (1<<n) - 1  
3. For each bit set in mask → include that element  
4. Apply desired processing/checking logic  

Time Complexity:  
    - O(2^n * n) (iterate over all subsets and check bits)  
Space Complexity:  
    - O(1) extra space (excluding input and output)  

Stable: Not applicable (combinatorial technique)  
Adaptive: No  

Constraints:  
- Works best for small n (usually ≤ 20)  
- Extremely versatile in DP, subset generation, and optimization problems  
*/

#include <iostream>
#include <vector>
using namespace std;

void bitmaskSearch(const vector<int> &arr) {
    int n = arr.size();
    int totalMasks = 1 << n; // 2^n subsets

    for (int mask = 0; mask < totalMasks; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // If i-th bit is set
                cout << arr[i] << " ";
            }
        }
        cout << "}\n";
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    bitmaskSearch(arr);
    return 0;
}

/*  
Example Dry Run:  
----------------  
Array: [1, 2, 3], n = 3  
Total masks = 2^3 = 8  

mask = 0 (000) → {}  
mask = 1 (001) → {1}  
mask = 2 (010) → {2}  
mask = 3 (011) → {1, 2}  
mask = 4 (100) → {3}  
mask = 5 (101) → {1, 3}  
mask = 6 (110) → {2, 3}  
mask = 7 (111) → {1, 2, 3}  

Final Output:  
{}  
{1}  
{2}  
{1, 2}  
{3}  
{1, 3}  
{2, 3}  
{1, 2, 3}  
*/
