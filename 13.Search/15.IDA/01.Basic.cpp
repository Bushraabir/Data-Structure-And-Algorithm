/*  
Iterative Deepening A* (IDA*) is a **graph search algorithm**  
that combines the **space efficiency** of Depth-First Search (DFS)  
with the **heuristic guidance** of A* Search.  

It is useful when:  
- The search space is large, but memory is limited  
- We have a good heuristic to guide the search  
- We want optimal solutions (like in A*) without storing large open/closed lists  

Definition:  
IDA* performs a series of depth-first searches,  
but instead of limiting depth by number of steps (as in IDDFS),  
it limits by **f-cost**:  
    f(n) = g(n) + h(n)  
where:  
    g(n) = cost so far to reach n  
    h(n) = estimated cost from n to goal (heuristic)  

Example Problem:  
8-puzzle shortest moves:  
Initial: 1 2 3  
         4 5 6  
         0 7 8  
Goal:    1 2 3  
         4 5 6  
         7 8 0  

Process:  
    Step 1: Calculate initial bound = h(start)  
    Step 2: DFS but prune nodes where f(n) > bound  
    Step 3: If goal not found, set bound = min(f(n) of pruned nodes) and repeat  
    Step 4: Continue until goal found or no nodes left  

Working Principle:  
1. Initialize bound = heuristic(start)  
2. Perform DFS, pruning nodes with f > bound  
3. Track smallest f that exceeded bound → new bound for next iteration  
4. Repeat until goal found  

Time Complexity:  
    - Worst-case: O(b^d) like DFS  
    - Often much better in practice with good heuristics  
Space Complexity:  
    - O(d) (only recursion stack)  

Stable: Not applicable (search algorithm)  
Adaptive: Yes (bound grows as needed)  

Constraints:  
- Heuristic must be admissible (never overestimate) for optimality  
- Works best when branching factor is manageable  
- Typically slower than A* but uses much less memory  
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Node {
    int state;
    int g; // cost so far
};

// Example heuristic: absolute difference from goal
int heuristic(int state) {
    return abs(state - 100); // placeholder heuristic
}

int dfs(Node node, int bound, int &nextBound) {
    int f = node.g + heuristic(node.state);
    if (f > bound) {
        nextBound = min(nextBound, f);
        return -1; // pruned
    }
    if (node.state == 100) return node.g; // goal found

    // Example children: increment or decrement state
    vector<int> moves = {+1, -1};
    for (int move : moves) {
        Node child = {node.state + move, node.g + 1};
        int result = dfs(child, bound, nextBound);
        if (result != -1) return result;
    }
    return -1; // not found in this path
}

int idaStar(int startState) {
    int bound = heuristic(startState);
    while (true) {
        int nextBound = numeric_limits<int>::max();
        int result = dfs({startState, 0}, bound, nextBound);
        if (result != -1) return result; // found
        if (nextBound == numeric_limits<int>::max()) return -1; // no solution
        bound = nextBound;
    }
}

int main() {
    int start = 95; // start state
    int result = idaStar(start);
    if (result != -1)
        cout << "Goal found with cost: " << result << "\n";
    else
        cout << "No solution found\n";
    return 0;
}

/*  
Example Dry Run:  
----------------  
Start = 95, Goal = 100  
Heuristic(start) = |95 - 100| = 5 → bound = 5  

Iteration 1: bound = 5  
    DFS explores states with f ≤ 5  
    Finds state = 100 with cost 5 → success  

Final Output:  
Goal found with cost: 5  
*/
