/*
 * Solve the M-Coloring problem: given an undirected graph and an integer M,
 * determine if the graph can be colored using at most M colors so that no two
 * adjacent vertices share the same color.
 *
 * Example:
 *   n = 4, M = 3
 *   Adjacency matrix:
 *     {{0,1,1,1},
 *      {1,0,1,0},
 *      {1,1,0,1},
 *      {1,0,1,0}}
 *   Possible coloring with 3 colors? Yes → returns true (1)
 *
 *   n = 4, M = 2
 *   Same graph
 *   Possible coloring with 2 colors? No → returns false (0)
 */

#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to color 'node' with color 'c'
// by ensuring no adjacent vertex already has color 'c'.
bool isSafe(int node, int c,
            const vector<vector<int>>& graph,
            const vector<int>& color) {
    int n = graph.size();
    for (int adj = 0; adj < n; ++adj) {
        // If there's an edge and the adjacent node has same color, it's not safe
        if (graph[node][adj] && color[adj] == c)
            return false;
    }
    return true;
}

// Recursive backtracking to try coloring each node from 0..n-1
bool graphColoringHelper(int node, int M,
                         const vector<vector<int>>& graph,
                         vector<int>& color) {
    int n = graph.size();
    // Base case: all nodes colored successfully
    if (node == n) 
        return true;

    // Try each color from 1 to M for current node
    for (int c = 1; c <= M; ++c) {
        if (isSafe(node, c, graph, color)) {
            color[node] = c;                      // Assign color
            if (graphColoringHelper(node + 1, M, graph, color))
                return true;                     // Found valid coloring downstream
            color[node] = 0;                      // Backtrack: remove color
        }
    }
    // No valid color found for this node → backtrack
    return false;
}

// Public API: returns true if graph can be M-colored, else false
bool graphColoring(const vector<vector<int>>& graph, int M) {
    int n = graph.size();
    vector<int> color(n, 0);  // 0 means uncolored
    return graphColoringHelper(0, M, graph, color);
}

int main() {
    // Example graph as adjacency matrix
    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int M1 = 3, M2 = 2;
    cout << "Can color with " << M1 << " colors? "
         << (graphColoring(graph, M1) ? "Yes (1)\n" : "No (0)\n");
    cout << "Can color with " << M2 << " colors? "
         << (graphColoring(graph, M2) ? "Yes (1)\n" : "No (0)\n");

    return 0;
}
