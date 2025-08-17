/*  
0–1 BFS is a **graph traversal algorithm** optimized for graphs where  
edge weights are only 0 or 1.  

It is useful when:  
- We need the shortest path in a graph with weights only 0 and 1  
- Standard BFS cannot be used because of weighted edges  
- Dijkstra's algorithm works but is slower (O(E log V)) compared to 0–1 BFS (O(V + E))  
- Problems like minimum time with roads having two possible travel times (e.g., 0 or 1 unit)  

Definition:  
Given a graph with edge weights in {0, 1}, 0–1 BFS uses a **deque** instead of a queue.  
- For an edge with weight 0 → push the neighbor to the **front** of the deque (no extra cost)  
- For an edge with weight 1 → push the neighbor to the **back** of the deque (cost increases by 1)  
- This ensures we always process the shortest distance first, similar to Dijkstra’s algorithm but faster.  

Example:  
Graph (Adjacency List with weights):  
0 → (1, 0), (2, 1)  
1 → (2, 1), (3, 0)  
2 → (3, 1)  
3 → —  

Starting Node: 0  

Process:  
    Step 1: Push 0 into deque, dist[0] = 0  
    Step 2: Pop 0 → (1, 0) → front push (dist=0), (2, 1) → back push (dist=1)  
    Step 3: Pop 1 → (2, 1) → dist[2] already 1, no update; (3, 0) → front push dist=0  
    Step 4: Pop 3 → no neighbors  
    Step 5: Pop 2 → (3, 1) → dist[3] already smaller, no update  

Working Principle:  
1. Initialize distance array with ∞ (or large value), dist[start] = 0  
2. Push start node into deque  
3. While deque is not empty:  
    a. Pop from front  
    b. For each neighbor:  
        - If weight = 0 and dist[neighbor] > dist[node]: update and push front  
        - If weight = 1 and dist[neighbor] > dist[node] + 1: update and push back  
4. Continue until all nodes are processed  

Time Complexity:  
    - O(V + E)  
Space Complexity:  
    - O(V) for distance array + O(V) for deque  

Stable: Not applicable (traversal)  
Adaptive: No  

Constraints:  
- Works only when edge weights are 0 or 1  
*/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

void zeroOneBFS(const vector<vector<pair<int,int>>> &graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    deque<int> dq;

    dist[start] = 0;
    dq.push_front(start);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto [neighbor, weight] : graph[node]) {
            if (dist[neighbor] > dist[node] + weight) {
                dist[neighbor] = dist[node] + weight;
                if (weight == 0)
                    dq.push_front(neighbor);
                else
                    dq.push_back(neighbor);
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << start << " to " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    // Graph representation (Adjacency List with weights)
    vector<vector<pair<int,int>>> graph = {
        {{1, 0}, {2, 1}}, // Node 0 connects to (1,0) and (2,1)
        {{2, 1}, {3, 0}}, // Node 1 connects to (2,1) and (3,0)
        {{3, 1}},         // Node 2 connects to (3,1)
        {}                // Node 3 has no outgoing edges
    };

    int startNode = 0;
    cout << "0–1 BFS starting from node " << startNode << ":\n";
    zeroOneBFS(graph, startNode);

    return 0;
}

/*  
Example Dry Run:  
----------------  
Graph:  
0 → (1,0), (2,1)  
1 → (2,1), (3,0)  
2 → (3,1)  
3 → —  

Start = 0  

Step 1: dq = [0], dist[0] = 0  
Step 2: Pop 0 → (1,0) → front push (dist=0), (2,1) → back push (dist=1)  
Step 3: dq = [1, 2]  
Step 4: Pop 1 → (2,1) → no update (dist=1), (3,0) → front push (dist=0)  
Step 5: dq = [3, 2]  
Step 6: Pop 3 → no neighbors  
Step 7: Pop 2 → (3,1) → no update  

Final Output:  
Distance from 0 to 0: 0  
Distance from 0 to 1: 0  
Distance from 0 to 2: 1  
Distance from 0 to 3: 0  
*/
