/*  
Breadth First Search (BFS) is a **graph/tree traversal algorithm**  
that explores all neighbors of a node before moving to the next level.  

It is useful when:  
- We want the shortest path in an unweighted graph  
- We need to visit all nodes in increasing order of their distance from the source  
- We are solving problems like minimum moves in a game, web crawling, or level-order traversal of trees  

Definition:  
Given a graph (directed or undirected), BFS starts from a source node and  
- Visits the node  
- Uses a queue to visit all unvisited neighbors  
- Continues level by level until all reachable nodes are visited  

Example:  
Graph (Adjacency List):  
0 → 1, 2  
1 → 2  
2 → 0, 3  
3 → 3  

Starting Node: 2  

Process:  
    Step 1: Enqueue 2 → mark visited  
    Step 2: Dequeue 2 → visit neighbors 0, 3 → enqueue them  
    Step 3: Dequeue 0 → visit neighbor 1 → enqueue it  
    Step 4: Dequeue 3 → visit neighbor 3 (already visited)  
    Step 5: Dequeue 1 → visit neighbor 2 (already visited)  

Working Principle:  
1. Start from the given source node and mark it as visited  
2. Push it into a queue  
3. While the queue is not empty:  
    a. Pop the front node  
    b. Visit all its unvisited neighbors, mark them visited, and enqueue them  
4. Continue until the queue is empty  

Time Complexity:  
    - O(V + E) where V = vertices, E = edges  
Space Complexity:  
    - O(V) for visited array + O(V) for queue  

Stable: Not applicable (traversal)  
Adaptive: No  

Constraints:  
- Works on both connected and disconnected graphs (for disconnected, run BFS from each unvisited node)  
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS driver function
void bfs(const vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Process node

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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

    cout << "BFS starting from node " << startNode << ": ";
    bfs(graph, startNode);
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

Step 1: Enqueue 2 → mark visited  
Step 2: Dequeue 2 → visit 0, 3 → enqueue them  
Step 3: Dequeue 0 → visit 1 → enqueue it  
Step 4: Dequeue 3 → visit 3 (already visited)  
Step 5: Dequeue 1 → visit 2 (already visited)  

Final Output:  
BFS starting from node 2: 2 0 3 1  
*/
