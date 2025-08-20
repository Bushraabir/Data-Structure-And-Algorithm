// 1. Problem Introduction
// -----------------------
//
// Goal: For each query (Xi, Yi), find the **maximum XOR value** between Xi and an element arr[j] 
//       from the given array `arr`, with the constraint arr[j] <= Yi. Return -1 if no element satisfies.
//
// Technique:
// - Use a Trie to store binary representations of numbers
// - Each Trie node has two links: 0 and 1
// - Insert numbers bit by bit from MSB to LSB
// - Use **offline queries** approach:
//     * Sort arr in ascending order
//     * Sort queries by Yi in ascending order
//     * Insert into Trie only those arr[j] ≤ Yi for the current query
//     * Use getMax(Xi) to find maximum XOR for current query
//
// Example:
// arr = {1, 2, 3, 5}, queries = [(4,1), (1,5), (3,4)]
// Sorted queries by Yi: [(4,1), (3,4), (1,5)]
// Answers: [5, 2, 4]
//
// Constraints:
// - Non-negative integers
// - 32-bit integers for practical implementation
// - arr size ≤ 10^5, number of queries ≤ 10^5

#include <bits/stdc++.h>
using namespace std;

// 2. Trie Node Definition
// -----------------------
class TrieNode {
public:
    TrieNode* links[2]; // 0 and 1 links

    TrieNode() {
        links[0] = links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    TrieNode* get(int bit) {
        return links[bit];
    }

    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }
};

// 3. Trie Class Implementation
// ----------------------------
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            if(node->containsKey(oppositeBit)) {
                maxXor |= (1 << i);
                node = node->get(oppositeBit);
            } else if(node->containsKey(bit)) {
                node = node->get(bit);
            } else {
                return -1; // Trie is empty
            }
        }

        return maxXor;
    }
};

// 4. Maximum XOR With Queries (Offline Approach)
// ----------------------------------------------
vector<int> maximizeXor(vector<int>& arr, vector<pair<int,int>>& queries) {
    int n = arr.size(), q = queries.size();
    vector<tuple<int,int,int>> offlineQueries;

    for(int i = 0; i < q; i++) {
        offlineQueries.push_back({queries[i].second, queries[i].first, i}); // (Yi, Xi, original_index)
    }

    sort(arr.begin(), arr.end());                     // Sort arr
    sort(offlineQueries.begin(), offlineQueries.end()); // Sort queries by Yi

    Trie trie;
    vector<int> ans(q, -1);
    int j = 0;

    for(auto &[Yi, Xi, idx] : offlineQueries) {
        while(j < n && arr[j] <= Yi) {
            trie.insert(arr[j]);
            j++;
        }

        if(j > 0) { // Trie has elements
            ans[idx] = trie.getMax(Xi);
        } else {
            ans[idx] = -1;
        }
    }

    return ans;
}

// 5. Example Usage
// ----------------
int main() {
    vector<int> arr = {1, 2, 3, 5};
    vector<pair<int,int>> queries = {{4,1}, {1,5}, {3,4}};

    vector<int> results = maximizeXor(arr, queries);

    for(int res : results) {
        cout << res << " "; // Output: 5 4 2
    }
    cout << endl;

    return 0;
}
