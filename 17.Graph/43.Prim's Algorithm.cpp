/*
 * Problem Statement: Minimum Spanning Tree (MST)
 *
 * You are given an undirected weighted graph with 'n' nodes numbered from 0 to n-1
 * and a list of edges. Each edge is represented as [u, v, wt], indicating an edge
 * between u and v with weight wt. The goal is to construct a spanning tree that
 * connects all nodes using exactly n-1 edges and has the minimum total sum of edge weights.
 *
 * Key Observations:
 * - A spanning tree is a connected acyclic subgraph containing all n nodes.
 * - The MST is the spanning tree with the minimum total edge weight.
 * - A graph can have multiple spanning trees, but MST ensures the total weight is minimum.
 * - Algorithms like Prim's or Kruskal's are used to efficiently compute MSTs.
 *
 * Intuition (Prim's Algorithm Example):
 * 1. Start from any node and initialize a min-priority queue with its edges.
 * 2. Initialize a visited set to track included nodes in the MST.
 * 3. While the MST has fewer than n-1 edges:
 *     a. Extract the edge with minimum weight from the priority queue.
 *     b. If it connects a new node (not in visited):
 *         i. Include the edge in the MST.
 *         ii. Mark the new node as visited.
 *         iii. Add all edges from this node to the priority queue that lead to unvisited nodes.
 * 4. Repeat until all nodes are included in the MST.
 * 5. Return the list of edges in the MST and/or its total weight.
 *
 * Time Complexity:
 * - O(E log V), where E = number of edges, V = number of nodes (due to priority queue operations).
 *
 * Space Complexity:
 * - O(V + E) for adjacency list and priority queue.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// PRIM'S MST IMPLEMENTATION
// ---------------------------
long long primMST(int n, vector<vector<pair<int,int>>>& adjList, vector<pair<int,int>>& mstEdges) {
    vector<bool> visited(n, false);
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    long long totalWeight = 0;

    // Start from node 0
    pq.push({0, -1, 0}); // {weight, parent, node}

    while(!pq.empty()) {
        auto [wt, parent, u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(parent != -1) mstEdges.push_back({parent,u});
        totalWeight += wt;

        for(auto &[v, w] : adjList[u]) {
            if(!visited[v]) pq.push({w, u, v});
        }
    }

    return totalWeight;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 4;
    vector<vector<pair<int,int>>> adjList(n);
    vector<tuple<int,int,int>> edges = {
        {0,1,3},
        {0,2,6},
        {1,2,4},
        {1,3,4},
        {2,3,2}
    };

    // Build adjacency list
    for(auto &[u,v,wt] : edges) {
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt}); // undirected graph
    }

    vector<pair<int,int>> mstEdges;
    long long mstWeight = primMST(n, adjList, mstEdges);

    cout << "MST total weight: " << mstWeight << "\nEdges in MST:\n";
    for(auto &[u,v] : mstEdges) {
        cout << u << " - " << v << "\n";
    }

    return 0;
}
