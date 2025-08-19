/*
 * Problem Statement: Check Bipartite Graph
 *
 * You are given a graph with N nodes represented as an adjacency list.
 * Task: Determine if the graph is bipartite, i.e., it can be colored with two colors
 *       such that no two adjacent nodes have the same color.
 *
 * Example Input:
 * N = 4
 * adjacencyList = {
 *   {1, 3},    // Node 0 is connected to Node 1 and Node 3
 *   {0, 2},    // Node 1 is connected to Node 0 and Node 2
 *   {1, 3},    // Node 2 is connected to Node 1 and Node 3
 *   {0, 2}     // Node 3 is connected to Node 0 and Node 2
 * }
 *
 * Key Observations:
 * - A graph is bipartite if it has no odd-length cycles.
 * - Linear graphs or graphs with only even-length cycles are always bipartite.
 * - Use DFS to attempt coloring nodes with two colors (0 and 1).
 *
 * Intuition:
 * - Initialize a color array of size N with -1 (uncolored).
 * - For each uncolored node, perform DFS:
 *     * Assign initial color 0 to the start node.
 *     * For each neighbor:
 *         - If uncolored, assign opposite color and recursively DFS.
 *         - If already colored with same color as current node, return false.
 * - If DFS finishes without conflicts for all components, return true.
 *
 * Edge Cases:
 * - Disconnected graphs (multiple components) must be checked separately.
 * - Graphs with no edges are trivially bipartite.
 *
 * Time Complexity:
 * - O(N + M), where N is the number of nodes and M is the number of edges.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for color array, O(N) for recursion stack.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Function to Check Bipartiteness from a Node
// ---------------------------
bool dfsCheck(int node, int currentColor, vector<int> &color, vector<vector<int>> &adj) {
    color[node] = currentColor;

    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            if (!dfsCheck(neighbor, 1 - currentColor, color, adj))
                return false;
        } else if (color[neighbor] == color[node]) {
            return false; // conflict found, not bipartite
        }
    }

    return true;
}

// ---------------------------
// Function to Check if Graph is Bipartite
// ---------------------------
bool isBipartite(int N, vector<vector<int>> &adj) {
    vector<int> color(N, -1); // -1 = uncolored

    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            if (!dfsCheck(i, 0, color, adj))
                return false;
        }
    }

    return true;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 4;
    vector<vector<int>> adjacencyList = {
        {1, 3}, // Node 0
        {0, 2}, // Node 1
        {1, 3}, // Node 2
        {0, 2}  // Node 3
    };

    if (isBipartite(N, adjacencyList))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is Not Bipartite\n";

    return 0;
}
