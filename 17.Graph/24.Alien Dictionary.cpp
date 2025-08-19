/*
 * Problem Statement: Alien Dictionary - Determine Character Order Using Topological Sort
 *
 * You are given a dictionary of N words from an alien language and K possible characters.
 * The words are sorted according to the alien language's order.
 *
 * Task: Find one possible order of characters in the alien language. If no valid order exists
 *       (due to prefix violations or cycles), return an empty string.
 *
 * Key Observations:
 * - Compare adjacent words to find the first differing character; this gives a dependency.
 * - Each dependency U -> V means character U comes before character V.
 * - Build a directed graph representing these dependencies.
 * - Topological sort of the graph provides one valid character order.
 * - Cycles or prefix violations make a valid order impossible.
 *
 * Intuition:
 * 1. Map each character to a 0-based index for graph representation.
 * 2. For each adjacent word pair:
 *     - Find the first differing character.
 *     - Add a directed edge from the first character to the second.
 * 3. Build in-degree array for all characters.
 * 4. Apply BFS-based Kahn's Algorithm to compute topological order:
 *     - Initialize queue with characters having in-degree 0.
 *     - Dequeue a character, append to result, decrement in-degrees of neighbors.
 *     - Enqueue neighbors whose in-degree becomes 0.
 * 5. If topological sort includes all characters, convert indices back to characters.
 * 6. Handle prefix violations: if a longer word comes before a shorter word with same prefix, invalid.
 *
 * Time Complexity:
 * - O(N * L + K), where N = number of words, L = max word length, K = number of characters.
 *
 * Space Complexity:
 * - O(K + E), for adjacency list, in-degree array, queue, and result.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Function to find one valid alien character order
// ---------------------------
string alienOrder(vector<string> &words, int K) {
    vector<vector<int>> adj(K);
    vector<int> inDegree(K, 0);

    // Step 1: Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string &w1 = words[i];
        string &w2 = words[i+1];
        int minLen = min(w1.size(), w2.size());
        bool edgeAdded = false;
        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                adj[u].push_back(v);
                inDegree[v]++;
                edgeAdded = true;
                break;
            }
        }
        // Prefix violation: longer word comes before shorter with same prefix
        if (!edgeAdded && w1.size() > w2.size()) return "";
    }

    // Step 2: Kahn's Algorithm
    queue<int> q;
    for (int i = 0; i < K; i++)
        if (inDegree[i] == 0) q.push(i);

    string order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order += (char)(node + 'a');
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    // Step 3: Check if topological sort includes all characters
    for (int i = 0; i < K; i++)
        if (inDegree[i] != 0) return ""; // cycle exists

    return order;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    int K = 4; // a, b, c, d

    string order = alienOrder(words, K);

    if (!order.empty()) {
        cout << "One possible alien character order: " << order << "\n";
    } else {
        cout << "No valid character order exists (prefix violation or cycle).\n";
    }

    return 0;
}
