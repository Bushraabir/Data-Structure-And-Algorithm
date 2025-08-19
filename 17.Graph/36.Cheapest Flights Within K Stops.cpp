/*
 * Problem Statement: Cheapest Flights Within K Stops
 *
 * You are given 'n' cities numbered from 0 to n-1 and a list of flights.
 * Each flight is represented as (from, to, price). You are also given a 
 * source city, a destination city, and an integer K (maximum number of stops).
 *
 * The goal is to find the cheapest price to travel from the source to the
 * destination with at most K stops. If no such route exists, return -1.
 *
 * Key Observations:
 * - Simple Dijkstra's algorithm fails because it only considers the cheapest
 *   cost so far and ignores the number of stops, which may invalidate paths.
 * - BFS-like traversal with stop tracking ensures all paths within K stops
 *   are considered.
 *
 * Intuition:
 * 1. Build an adjacency list 'graph' from the flights array.
 * 2. Initialize a 1D array 'min_cost' of size n with INF; set min_cost[source] = 0.
 * 3. Use a queue to store {stops_taken, current_city, current_cost}.
 * 4. While the queue is not empty:
 *     a. Dequeue {current_stops, current_city, current_cost}.
 *     b. If current_stops > K, continue to next element.
 *     c. For each neighbor of current_city:
 *         - Calculate new_cost = current_cost + edge_weight.
 *         - If new_cost < min_cost[neighbor]:
 *             - Update min_cost[neighbor] = new_cost.
 *             - Enqueue {current_stops + 1, neighbor, new_cost}.
 * 5. After traversal, if min_cost[destination] is INF, return -1; else return min_cost[destination].
 *
 * Time Complexity:
 * - O(K * E) in worst case, where E is the number of flights (edges).
 *
 * Space Complexity:
 * - O(N + E) for adjacency list.
 * - O(N) for min_cost array.
 * - O(N * K) for queue in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Cheapest Flights Within K Stops
// ---------------------------
int findCheapestPrice(int n, vector<vector<int>>& flights, int source, int destination, int K) {
    // Build adjacency list: graph[from] = {to, price}
    vector<vector<pair<int,int>>> graph(n);
    for (auto &f : flights) {
        graph[f[0]].push_back({f[1], f[2]});
    }
    
    vector<int> min_cost(n, INT_MAX);
    min_cost[source] = 0;
    
    queue<tuple<int,int,int>> q; // {stops_taken, city, cost}
    q.push({0, source, 0});
    
    while (!q.empty()) {
        auto [stops, city, cost] = q.front(); q.pop();
        
        if (stops > K) continue;
        
        for (auto &[neighbor, price] : graph[city]) {
            int new_cost = cost + price;
            if (new_cost < min_cost[neighbor]) {
                min_cost[neighbor] = new_cost;
                q.push({stops + 1, neighbor, new_cost});
            }
        }
    }
    
    return (min_cost[destination] == INT_MAX) ? -1 : min_cost[destination];
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int source = 0, destination = 3, K = 1;
    
    int cheapest = findCheapestPrice(n, flights, source, destination, K);
    if (cheapest != -1)
        cout << "Cheapest price within " << K << " stops: " << cheapest << "\n";
    else
        cout << "No route found within " << K << " stops.\n";
    
    return 0;
}
