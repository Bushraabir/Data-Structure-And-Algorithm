/*  
Depth First Search (DFS) is a **graph/tree traversal algorithm**  
that explores as far as possible along each branch before backtracking.  

It is useful when:  
- We need to explore all nodes in a path before moving to another path  
- We want to detect cycles in a graph  
- We need topological sorting in DAGs  
- We are solving maze/connected components problems  

Definition:  
Given a graph (directed or undirected), DFS starts from a source node and  
- Visits the node  
- Recursively (or using a stack) visits all unvisited adjacent nodes  
- Backtracks when no unvisited adjacent nodes are left  

Example:  
Graph (Adjacency List):  
0 → 1, 2  
1 → 2  
2 → 0, 3  
3 → 3  

Starting Node: 2  

Process:  
    Step 1: Visit 2 → mark visited  
    Step 2: Visit 0 from 2  
    Step 3: Visit 1 from 0  
    Step 4: Visit 2 from 1 (already visited) → backtrack  
    Step 5: Visit 3 from 2 → Visit 3 again from 3 (already visited)  

Working Principle:  
1. Start from the given source node and mark it as visited  
2. Visit all adjacent unvisited nodes (recursively or with a stack)  
3. If all adjacent nodes are visited, backtrack  
4. Continue until all reachable nodes are visited  

Time Complexity:  
    - O(V + E) where V = vertices, E = edges  
Space Complexity:  
    - O(V) for visited array + recursion stack  

Stable: Not applicable (traversal)  
Adaptive: No  

Constraints:  
- Works on both connected and disconnected graphs (for disconnected, run DFS from each unvisited node)  
*/

#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[node] = true;
    cout << node << " "; // Process node

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited, graph);
        }
    }
}

// DFS driver function
void dfs(const vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    dfsUtil(start, visited, graph);
}

int main() {
    // Graph representation (Adjacency List)
    vector<vector<int>> graph = {
        {1, 2},   // Node 0 connects to 1, 2
        {2},      // Node 1 connects to 2
        {0, 3},   // Node 2 connects to 0, 3
        {3}       // Node 3 connects to itself
    };

    int startNode = 2;

    cout << "DFS starting from node " << startNode << ": ";
    dfs(graph, startNode);
    cout << "\n";

    return 0;
}

/*  
Example Dry Run:  
----------------  
Graph:  
0 → 1, 2  
1 → 2  
2 → 0, 3  
3 → 3  

Start = 2  

Step 1: Visit 2 → mark visited  
Step 2: From 2 → visit 0 → mark visited  
Step 3: From 0 → visit 1 → mark visited  
Step 4: From 1 → visit 2 (already visited) → backtrack  
Step 5: From 2 → visit 3 → mark visited → from 3 visit 3 (already visited)  

Final Output:  
DFS starting from node 2: 2 0 1 3  
*/
