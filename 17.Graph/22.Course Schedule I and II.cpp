/*
 * Problem Statement: Course Schedule I & II Using BFS (Kahn's Algorithm)
 *
 * You are given a set of N tasks (courses) and a list of prerequisite pairs.
 * Task 1 (Course Schedule I): Determine if it is possible to finish all tasks.
 * Task 2 (Course Schedule II): Return a valid ordering of tasks to complete all,
 *       or an empty array if impossible.
 *
 * Graph Representation:
 * - Each prerequisite pair (A, B) means "to do task A, you must first complete B".
 * - Create a directed edge B -> A to indicate dependency.
 *
 * Key Observations:
 * - Topological sort is only possible for Directed Acyclic Graphs (DAGs).
 * - If a complete topological ordering exists, there is no cycle, and all tasks
 *   can be completed.
 * - BFS-based Kahn's Algorithm can detect cycles and produce task ordering.
 *
 * Intuition:
 * - Calculate in-degree for each node (number of prerequisites).
 * - Initialize a queue with nodes having in-degree 0 (no prerequisites).
 * - While the queue is not empty:
 *     * Dequeue a node and add to ordering/result.
 *     * For each neighbor, decrement its in-degree by 1.
 *     * If neighbor's in-degree becomes 0, enqueue it.
 * - After processing all possible nodes:
 *     * If result size == N, return result (ordering exists, no cycle).
 *     * If result size < N, return empty array (cycle exists, impossible).
 *
 * Time Complexity:
 * - O(N + M), where N is number of tasks, M is number of prerequisite edges.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for in-degree array, O(N) for queue and result.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Function to find a valid task ordering using Kahn's Algorithm (BFS)
// Returns empty vector if impossible (cycle exists)
// ---------------------------
vector<int> courseSchedule(int N, vector<pair<int,int>> &prerequisites) {
    vector<vector<int>> adj(N);
    vector<int> inDegree(N, 0);

    // Build adjacency list and in-degree array
    for (auto &p : prerequisites) {
        int u = p.second; // prerequisite
        int v = p.first;  // course dependent on u
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    // If topoOrder size == N, return ordering; else cycle exists
    if (topoOrder.size() == N) return topoOrder;
    return {};
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 6;
    vector<pair<int,int>> prerequisites = {
        {0,1}, // To take 0, must first do 1
        {2,3}, // To take 2, must first do 3
        {0,4}, // To take 0, must first do 4
        {1,4}, // To take 1, must first do 4
        {2,5}, // To take 2, must first do 5
    };

    vector<int> ordering = courseSchedule(N, prerequisites);

    if (!ordering.empty()) {
        cout << "Tasks can be completed in this order: ";
        for (int t : ordering) cout << t << " ";
        cout << "\n";
    } else {
        cout << "It is impossible to complete all tasks (cycle exists).\n";
    }

    return 0;
}
