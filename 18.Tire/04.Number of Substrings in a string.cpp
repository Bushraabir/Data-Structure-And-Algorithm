// 1. Problem Introduction
// -----------------------
//
// Goal: Count the **total number of distinct substrings** in a given string.
//
// Trie Properties:
// - Tree-like structure for storing substrings efficiently
// - Each node has:
//   * links array of size 26 (for lowercase 'a' to 'z')
//   * No `isEnd` required; uniqueness is determined by node creation
//
// Example:
// Input: "bab"
// Distinct substrings: "b", "a", "ba", "ab", "bab"
// Output: 5
//
// Constraints:
// - String contains only lowercase English letters
// - Length of string ≤ 1000
//
// Equivalent Problems:
// - Counting unique substrings using Trie or HashSet
// - Prefix-based substring storage

#include <bits/stdc++.h>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    TrieNode* links[26];

    TrieNode() {
        memset(links, 0, sizeof(links));
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }
};

// 2. Trie Class Implementation
// ----------------------------
//
// Idea:
// - Insert all possible substrings of the string into the Trie
// - Count new nodes created to determine distinct substrings
//
// Time Complexity:
// - O(N^2) for inserting all substrings (nested loops)
// Space Complexity:
// - O(total characters in distinct substrings)
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    int countDistinctSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            TrieNode* node = root;
            for(int j = i; j < n; j++) {
                char ch = s[j];
                if(!node->containsKey(ch)) {
                    node->put(ch, new TrieNode());
                    count++; // New substring found
                }
                node = node->get(ch);
            }
        }

        return count;
    }
};

// 3. Example Usage
// ----------------
int main() {
    string s = "bab";
    Trie trie;

    int distinctCount = trie.countDistinctSubstrings(s);
    cout << "Number of distinct substrings: " << distinctCount << endl; // Output: 5

    return 0;
}
