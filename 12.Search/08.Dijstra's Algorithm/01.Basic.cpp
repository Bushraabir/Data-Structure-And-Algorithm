/*  
Dijkstra’s Algorithm is a **shortest path algorithm** for graphs  
with **non-negative edge weights**.  

It is useful when:  
- We need the shortest path in a weighted graph (no negative weights)  
- Edge weights vary and cannot be handled by simple BFS  
- Problems like route planning, network routing, and map navigation  

Definition:  
Given a weighted graph, Dijkstra’s algorithm finds the shortest distance  
from a source node to all other nodes by always expanding the currently  
known closest node first (greedy approach).  

Example:  
Graph (Adjacency List with weights):  
0 → (1, 4), (2, 1)  
1 → (3, 1)  
2 → (1, 2), (3, 5)  
3 → —  

Starting Node: 0  

Process:  
    Step 1: dist[0] = 0, all others = ∞, push (0,0) into min-heap  
    Step 2: Pop (0,0) → update dist[1] = 4, dist[2] = 1 → push (1,2), (4,1)  
    Step 3: Pop (1,2) → update dist[1] = 3 (better than 4), dist[3] = 6 → push (3,1), (6,3)  
    Step 4: Pop (3,1) → update dist[3] = 4 (better than 6) → push (4,3)  
    Step 5: Pop remaining nodes but no better distances found  

Working Principle:  
1. Initialize distances array with ∞, set dist[start] = 0  
2. Use a min-heap (priority queue) to store (distance, node) pairs  
3. While heap is not empty:  
    a. Pop the node with smallest distance  
    b. For each neighbor:  
        - If dist[current] + weight < dist[neighbor], update and push into heap  
4. Continue until all nodes are processed  

Time Complexity:  
    - O((V + E) log V) with min-heap  
Space Complexity:  
    - O(V) for distance array + O(V) for heap  

Stable: Not applicable (shortest path algorithm)  
Adaptive: No  

Constraints:  
- Works only with non-negative edge weights  
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(const vector<vector<pair<int,int>>> &graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {distance, node}

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue; // Skip if we already found a better path

        for (auto [neighbor, weight] : graph[node]) {
            if (dist[neighbor] > dist[node] + weight) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
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
        {{1, 4}, {2, 1}}, // Node 0 connects to (1,4) and (2,1)
        {{3, 1}},         // Node 1 connects to (3,1)
        {{1, 2}, {3, 5}}, // Node 2 connects to (1,2) and (3,5)
        {}                // Node 3 has no outgoing edges
    };

    int startNode = 0;
    cout << "Dijkstra’s algorithm starting from node " << startNode << ":\n";
    dijkstra(graph, startNode);

    return 0;
}

/*  
Example Dry Run:  
----------------  
Graph:  
0 → (1,4), (2,1)  
1 → (3,1)  
2 → (1,2), (3,5)  
3 → —  

Start = 0  

Step 1: dist = [0, ∞, ∞, ∞], pq = [(0,0)]  
Step 2: Pop (0,0) → update: dist[1] = 4, dist[2] = 1, pq = [(1,2), (4,1)]  
Step 3: Pop (1,2) → update: dist[1] = 3, dist[3] = 6, pq = [(3,1), (4,1), (6,3)]  
Step 4: Pop (3,1) → update: dist[3] = 4, pq = [(4,1), (4,3), (6,3)]  
Step 5: Pop (4,1) → no updates  
Step 6: Pop (4,3) → no updates  
Step 7: Pop (6,3) → no updates  

Final Output:  
Distance from 0 to 0: 0  
Distance from 0 to 1: 3  
Distance from 0 to 2: 1  
Distance from 0 to 3: 4  
*/
