/*
 * Problem Statement: Number of Ways to Arrive at Destination
 *
 * You are given a city represented as an undirected graph with n intersections (nodes)
 * numbered from 0 to n-1 and a list of roads. Each road is represented as [u, v, time],
 * indicating travel time between intersections u and v. The goal is to find the total
 * number of distinct shortest paths from source (node 0) to destination (node n-1).
 *
 * Key Observations:
 * - Standard Dijkstra finds shortest distances but does not count the number of shortest paths.
 * - To count paths, maintain an array 'ways[]' where ways[i] = number of shortest paths to node i.
 * - When a node v is reached via a strictly shorter path, reset ways[v] = ways[u].
 * - When a node v is reached via an equally short path, add ways[u] to ways[v] modulo 1e9+7.
 *
 * Intuition:
 * 1. Build an adjacency list 'graph' from the roads array.
 * 2. Initialize distance array 'dist' of size n with INF; dist[0] = 0.
 * 3. Initialize ways array 'ways' of size n with 0; ways[0] = 1.
 * 4. Use a priority queue to process nodes in increasing order of distance.
 * 5. While the priority queue is not empty:
 *     a. Pop (current_distance, u) from the queue.
 *     b. Skip if current_distance > dist[u].
 *     c. For each neighbor v of u with edge weight w:
 *         - new_distance = dist[u] + w
 *         - If new_distance < dist[v]:
 *             - dist[v] = new_distance
 *             - ways[v] = ways[u]
 *             - Push (new_distance, v) into the priority queue.
 *         - Else if new_distance == dist[v]:
 *             - ways[v] = (ways[v] + ways[u]) % MOD
 * 6. Return ways[n-1] as the number of shortest paths to the destination modulo 1e9+7.
 *
 * Time Complexity:
 * - O(E log V), where V = n and E = number of roads.
 *
 * Space Complexity:
 * - O(V + E) for the graph.
 * - O(V) for distance and ways arrays.
 * - O(E) for priority queue in the worst case.
 */

#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> graph(n);
    
    for (auto &road : roads) {
        int u = road[0], v = road[1], time = road[2];
        graph[u].push_back({v, time});
        graph[v].push_back({u, time}); // undirected
    }

    vector<long long> dist(n, 1e18);
    vector<long long> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : graph[u]) {
            long long new_dist = d + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                ways[v] = ways[u];
                pq.push({new_dist, v});
            } else if (new_dist == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    return ways[n-1];
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 7;
    vector<vector<int>> roads = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {1, 3, 3},
        {2, 5, 1}, {3, 5, 1}, {4, 6, 6}, {5, 6, 1}
    };

    int totalWays = countPaths(n, roads);
    cout << "Total number of shortest paths: " << totalWays << "\n";

    return 0;
}
