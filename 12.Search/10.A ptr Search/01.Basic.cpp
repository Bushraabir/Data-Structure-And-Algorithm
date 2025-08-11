/*  
A* Search Algorithm is a **shortest path algorithm** that combines  
the benefits of **Dijkstra’s Algorithm** (guarantees shortest path)  
and **Greedy Best-First Search** (fast goal-directed search).  

It is useful when:  
- We need the shortest path **fast** in a weighted graph  
- We have a **heuristic function** that estimates distance to goal  
- Problems like map navigation, game AI, puzzle solving (8-puzzle, etc.)  

Definition:  
Given a weighted graph and a heuristic `h(n)` that estimates  
the cost from a node to the goal, A* expands nodes in order of:  

    f(n) = g(n) + h(n)  

Where:  
- g(n) = actual cost from start to n  
- h(n) = estimated cost from n to goal  
- f(n) = total estimated cost of path through n  

If h(n) is **admissible** (never overestimates) and **consistent**,  
A* is guaranteed to find the shortest path.  

Example:  
Graph (Adjacency List with weights):  
0 → (1, 1), (2, 4)  
1 → (2, 2), (3, 5)  
2 → (3, 1)  
3 → —  

Heuristic (to goal = 3):  
h[0] = 7  
h[1] = 6  
h[2] = 2  
h[3] = 0  

Start = 0, Goal = 3  

Process:  
    Step 1: g[0] = 0, f[0] = g[0] + h[0] = 7, push (7,0) into min-heap  
    Step 2: Pop node 0 → explore neighbors  
        - Node 1: g=1, f=7 → push (7,1)  
        - Node 2: g=4, f=6 → push (6,2)  
    Step 3: Pop node 2 (lowest f=6) → explore neighbors  
        - Node 3: g=5, f=5 → push (5,3)  
    Step 4: Pop node 3 → Goal reached, stop  

Working Principle:  
1. Maintain `g[]` (cost so far) and priority queue ordered by `f(n) = g(n) + h(n)`  
2. Start with f(start) = h(start), g(start) = 0  
3. While queue is not empty:  
    a. Pop node with smallest f(n)  
    b. If goal reached → return path and cost  
    c. For each neighbor:  
        - Tentative_g = g[current] + edge_weight  
        - If Tentative_g < g[neighbor], update and push into queue  
4. Stop when goal reached  

Time Complexity:  
    - O(E log V) (depends on heuristic quality)  
Space Complexity:  
    - O(V) for g[], f[], and queue  

Stable: Not applicable (search algorithm)  
Adaptive: Yes, based on heuristic  

Constraints:  
- Heuristic must be admissible for shortest path guarantee  
- If heuristic = 0 → behaves like Dijkstra’s Algorithm  
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

struct Node {
    int f, g, vertex;
    bool operator>(const Node &other) const {
        return f > other.f;
    }
};

void aStarSearch(const vector<vector<pair<int,int>>> &graph, const vector<int> &h, int start, int goal) {
    int n = graph.size();
    vector<int> gCost(n, INT_MAX);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    gCost[start] = 0;
    pq.push({h[start], 0, start});

    while (!pq.empty()) {
        auto [f, g, u] = pq.top();
        pq.pop();

        if (u == goal) {
            cout << "Shortest path cost from " << start << " to " << goal << ": " << g << "\n";
            return;
        }

        for (auto [v, w] : graph[u]) {
            int tentative_g = g + w;
            if (tentative_g < gCost[v]) {
                gCost[v] = tentative_g;
                pq.push({tentative_g + h[v], tentative_g, v});
            }
        }
    }

    cout << "Goal not reachable from start node.\n";
}

int main() {
    // Graph representation (Adjacency List with weights)
    vector<vector<pair<int,int>>> graph = {
        {{1,1}, {2,4}},   // 0
        {{2,2}, {3,5}},   // 1
        {{3,1}},          // 2
        {}                // 3
    };

    vector<int> heuristic = {7, 6, 2, 0}; // Estimated cost to goal=3

    int startNode = 0, goalNode = 3;
    cout << "A* Search Algorithm from node " << startNode << " to " << goalNode << ":\n";
    aStarSearch(graph, heuristic, startNode, goalNode);

    return 0;
}

/*  
Example Dry Run:  
----------------  
Graph:  
0 → (1,1), (2,4)  
1 → (2,2), (3,5)  
2 → (3,1)  
3 → —  

Heuristic: h[0]=7, h[1]=6, h[2]=2, h[3]=0  
Start=0, Goal=3  

Step 1: g[0]=0, f[0]=7 → pq=[(7,0)]  
Step 2: Pop (7,0) → neighbors:  
    1: g=1, f=7 → pq=[(7,1)]  
    2: g=4, f=6 → pq=[(6,2),(7,1)]  
Step 3: Pop (6,2) → neighbor:  
    3: g=5, f=5 → pq=[(5,3),(7,1)]  
Step 4: Pop (5,3) → Goal reached, cost=5  

Final Output:  
Shortest path cost from 0 to 3: 5  
*/
