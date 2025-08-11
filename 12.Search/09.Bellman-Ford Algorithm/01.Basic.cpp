/*  
Bellman–Ford Algorithm is a **shortest path algorithm** that works  
on graphs with **negative edge weights** (and positive weights as well).  

It is useful when:  
- We need the shortest path in a weighted graph with possible negative weights  
- We need to detect **negative weight cycles** in a graph  
- Problems like currency arbitrage detection, time travel constraints, etc.  

Definition:  
Given a weighted graph, Bellman–Ford finds the shortest distance  
from a source node to all other nodes by **relaxing** all edges  
(V-1) times, where V is the number of vertices.  

- "Relaxing" means: if the current known distance to a vertex can  
  be improved by going through an edge, update it.  

Example:  
Graph (Adjacency List with weights):  
0 → (1, 4), (2, 5)  
1 → (3, -3)  
2 → (1, 6), (3, 2)  
3 → —  

Starting Node: 0  

Process:  
    Step 1: dist[0] = 0, all others = ∞  
    Step 2: Repeat V-1 = 3 times:  
        - For every edge (u, v, w):  
            if dist[u] + w < dist[v] → update dist[v] = dist[u] + w  
    Step 3: Check for negative cycles by doing one more relaxation round:  
        - If any distance improves → negative cycle exists  

Working Principle:  
1. Initialize distances array with ∞, set dist[start] = 0  
2. Repeat (V-1) times:  
    a. For every edge (u, v, w), update if a shorter path is found  
3. Optional: Run one more iteration to detect negative cycles  
4. Output the shortest distances or report negative cycle  

Time Complexity:  
    - O(V × E)  
Space Complexity:  
    - O(V) for distance array  

Stable: Not applicable (shortest path algorithm)  
Adaptive: No  

Constraints:  
- Works with negative weights  
- If negative cycle exists → shortest paths are undefined for affected vertices  
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, vector<Edge> &edges, int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    // Check for negative weight cycle
    for (auto &edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "Graph contains a negative weight cycle\n";
            return;
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        cout << "Distance from " << start << " to " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    // Graph representation (edge list)
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 3, -3},
        {2, 1, 6},
        {2, 3, 2}
    };

    int startNode = 0;
    cout << "Bellman–Ford algorithm starting from node " << startNode << ":\n";
    bellmanFord(V, E, edges, startNode);

    return 0;
}

/*  
Example Dry Run:  
----------------  
Graph:  
0 → (1,4), (2,5)  
1 → (3,-3)  
2 → (1,6), (3,2)  
3 → —  

Start = 0  

Initial: dist = [0, ∞, ∞, ∞]  

Iteration 1:  
    Edge (0,1,4): dist[1] = 4  
    Edge (0,2,5): dist[2] = 5  
    Edge (1,3,-3): dist[3] = 1 (4 + -3)  
    Edge (2,1,6): no update (5+6=11 > 4)  
    Edge (2,3,2): no update (5+2=7 > 1)  
    dist = [0, 4, 5, 1]  

Iteration 2: (no further improvements)  
Iteration 3: (no further improvements)  

Negative cycle check: none found  

Final Output:  
Distance from 0 to 0: 0  
Distance from 0 to 1: 4  
Distance from 0 to 2: 5  
Distance from 0 to 3: 1  
*/
