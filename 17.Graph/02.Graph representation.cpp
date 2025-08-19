/*
 * Problem Statement: Graph Representation in C++
 *
 * You are given a graph input consisting of N nodes and M edges.
 * Task: Represent the graph in a program using C++ with either:
 *       - Adjacency Matrix
 *       - Adjacency List
 * Consider whether the graph is directed, undirected, weighted, or unweighted.
 *
 * Example Input (Undirected, Unweighted):
 * N = 5, M = 6
 * Edges:
 * 1 2
 * 1 3
 * 2 4
 * 3 4
 * 4 5
 * 2 5
 *
 * Key Observations:
 * - Graphs can be directed or undirected.
 * - Graphs can have weights on edges.
 * - Representation choice affects space efficiency:
 *   * Adjacency Matrix: O(N^2)
 *   * Adjacency List: O(E) (more efficient for sparse graphs)
 *
 * Intuition:
 * - Adjacency Matrix: use a 2D array, quick edge lookup.
 * - Adjacency List: use an array of vectors/lists, efficient for large sparse graphs.
 * - For weighted graphs, store weights instead of 1.
 * - For directed graphs, store edges in one direction only.
 *
 * Edge Cases:
 * - Sparse graph → adjacency list preferred.
 * - Dense graph → adjacency matrix acceptable.
 * - Weighted graphs → store actual weights.
 *
 * Time Complexity:
 * - Building adjacency matrix: O(M)
 * - Building adjacency list: O(M)
 *
 * Space Complexity:
 * - Matrix: O(N^2)
 * - List: O(E) for directed, O(2*E) for undirected
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Adjacency Matrix Example
// ---------------------------
void adjacencyMatrixExample(int N, vector<pair<int,int>> edges, bool directed=false) {
    vector<vector<int>> adj(N+1, vector<int>(N+1, 0)); // 1-based indexing

    for (auto [u,v] : edges) {
        adj[u][v] = 1;
        if (!directed) adj[v][u] = 1; // undirected
    }

    cout << "Adjacency Matrix:\n";
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    /*
     * Time Complexity:
     *   - Initializing matrix: O(N^2)
     *   - Filling edges: O(M)
     * Overall: O(N^2 + M) ≈ O(N^2)
     *
     * Space Complexity: O(N^2)
     */
}

// ---------------------------
// Adjacency List Example
// ---------------------------
void adjacencyListExample(int N, vector<pair<int,int>> edges, bool directed=false) {
    vector<vector<int>> adj(N+1); // 1-based indexing

    for (auto [u,v] : edges) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u); // undirected
    }

    cout << "Adjacency List:\n";
    for (int i=1; i<=N; i++) {
        cout << i << ": ";
        for (int neigh : adj[i]) cout << neigh << " ";
        cout << "\n";
    }

    /*
     * Time Complexity:
     *   - Creating adjacency list: O(M)
     *
     * Space Complexity:
     *   - Directed: O(E)
     *   - Undirected: O(2*E)
     */
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 5; // number of nodes
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{3,4},{4,5},{2,5}};

    adjacencyMatrixExample(N, edges, false); // undirected
    cout << "\n";
    adjacencyListExample(N, edges, false); // undirected

    return 0;
}
