/*  
Topological Sort is a linear ordering of vertices in a Directed Acyclic Graph (DAG)  
such that for every directed edge U → V, vertex U comes before V in the ordering.

Applications:
- Task scheduling (order of execution with dependencies)
- Resolving symbol dependencies in compilers
- Determining course order in academic prerequisites

Working Principle (Kahn’s Algorithm - BFS based):
1. Calculate the in-degree (number of incoming edges) for each vertex.
2. Push all vertices with in-degree 0 into a queue (these have no dependencies).
3. While the queue is not empty:
    - Remove a vertex from the queue and add it to the topological order.
    - Decrease the in-degree of all its neighbors by 1.
    - If a neighbor’s in-degree becomes 0, push it into the queue.
4. If all vertices are processed, we have a valid topological order.
5. If not all vertices are processed → there is a cycle (topological sort not possible).

Why it works:
- Vertices with no incoming edges can safely be placed first.
- Removing them (and their edges) reveals new vertices with no dependencies.

Time Complexity:
    - O(V + E)  → V = vertices, E = edges (each vertex and edge is processed once)
Space Complexity:
    - O(V)  → For storing in-degree array, queue, and output

Constraints:
- Works only for Directed Acyclic Graphs (DAGs)
- Not unique: Multiple valid orders may exist

Stable Sort: Not applicable
Adaptive: Not applicable
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform Topological Sort (Kahn's Algorithm)
vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Step 1: Calculate in-degree for each vertex
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Queue for vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;

    // Step 3: Process the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Step 4: Reduce in-degree of neighbors
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 5: Check for cycle
    if ((int)topoOrder.size() != V) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return {};
    }

    return topoOrder;
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Example Graph:
    // 5 → 0 → 2 → 3
    // ↓         ↑
    // 4 → 1 ----
    adj[5] = {0, 2};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    cout << "Topological Sort Order:\n";
    vector<int> result = topologicalSort(V, adj);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*
Example Dry Run:
----------------
Graph Edges:
5 → 0, 5 → 2
4 → 0, 4 → 1
2 → 3
3 → 1

Step 1: Calculate in-degree
inDegree = [2, 2, 1, 1, 0, 0]

Step 2: Queue initially = [4, 5] (in-degree 0)

Step 3:
- Pop 4 → topo = [4], reduce neighbors: inDegree = [1, 1, 1, 1, 0, 0]
- Pop 5 → topo = [4, 5], reduce neighbors: inDegree = [0, 1, 0, 1, 0, 0]
    → Push 0, 2 to queue
- Pop 0 → topo = [4, 5, 0], reduce neighbors: inDegree unchanged (0 has no neighbors)
- Pop 2 → topo = [4, 5, 0, 2], reduce neighbors: inDegree = [0, 1, 0, 0, 0, 0]
    → Push 3
- Pop 3 → topo = [4, 5, 0, 2, 3], reduce neighbors: inDegree = [0, 0, 0, 0, 0, 0]
    → Push 1
- Pop 1 → topo = [4, 5, 0, 2, 3, 1]

Final topological order: 4 5 0 2 3 1
*/
