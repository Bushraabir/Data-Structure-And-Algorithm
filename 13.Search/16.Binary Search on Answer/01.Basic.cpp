/*  
Binary Search on Answer (BSoA) is a **problem-solving technique**  
that applies Binary Search to the **answer space** instead of searching  
in an array directly.  

It is useful when:  
- The problem asks for the **minimum** or **maximum** value satisfying some condition  
- The answer lies in a **monotonic search space** (once a condition becomes true/false, it stays that way)  
- We can check feasibility with a helper function (predicate)  

Definition:  
Instead of searching for a specific value in an array, we search  
for the smallest or largest value in a range that satisfies a  
given condition, using Binary Search logic.  

Example Problem:  
We have boards of lengths [10, 20, 30, 40] and 2 painters.  
Find the **minimum time** needed if each painter paints continuous boards  
and takes 1 unit time per length.  

Process:  
    Step 1: Low = max(board lengths) = 40  
            High = sum(board lengths) = 100  
    Step 2: Mid = (40+100)/2 = 70  
            → Check if painters can finish with max load 70 → YES  
              So try smaller: high = 70  
    Step 3: Mid = (40+70)/2 = 55  
            → Check feasibility → NO → low = 56  
    Step 4: Repeat until low meets high → answer found  

Working Principle:  
1. Define the search range [low, high] as the possible answers  
2. While low < high:  
    - mid = (low + high) / 2  
    - If condition(mid) is true → high = mid  
    - Else → low = mid + 1  
3. Return low (or high) as final answer  

Time Complexity:  
    - O(log(range) * check_time)  
Space Complexity:  
    - O(1) (excluding input storage)  

Stable: Not applicable (optimization technique)  
Adaptive: No  

Constraints:  
- Works only if the feasibility check is monotonic  
- Common in allocation, scheduling, and minimization/maximization problems  
*/

#include <iostream>
#include <vector>
using namespace std;

// Helper function: check if maxLoad is possible
bool canPaint(const vector<int> &boards, int painters, int maxLoad) {
    int required = 1, currentLoad = 0;
    for (int length : boards) {
        if (length > maxLoad) return false;
        if (currentLoad + length > maxLoad) {
            required++;
            currentLoad = length;
            if (required > painters) return false;
        } else {
            currentLoad += length;
        }
    }
    return true;
}

int binarySearchOnAnswer(const vector<int> &boards, int painters) {
    int low = 0, high = 0;
    for (int length : boards) {
        low = max(low, length);
        high += length;
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canPaint(boards, painters, mid)) {
            high = mid; // Try smaller maximum
        } else {
            low = mid + 1; // Need bigger limit
        }
    }
    return low;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;

    int result = binarySearchOnAnswer(boards, painters);
    cout << "Minimum time required: " << result << "\n";

    return 0;
}

/*  
Example Dry Run:  
----------------  
Boards: [10, 20, 30, 40], Painters = 2  
Low = max(boards) = 40  
High = sum(boards) = 100  

Step 1: mid = (40+100)/2 = 70 → possible → high = 70  
Step 2: mid = (40+70)/2 = 55 → not possible → low = 56  
Step 3: mid = (56+70)/2 = 63 → possible → high = 63  
...  
Repeat until low = high = 60  

Final Output:  
Minimum time required: 60  
*/
