// 1. Problem Introduction
// -----------------------
//
// Goal: Find the **longest complete string** in an array of strings. 
//       A complete string is one where **every prefix** of the string also exists in the array.
//
// Trie Properties:
// - Tree-like structure for storing strings
// - Each node has:
//   * links array of size 26 (for lowercase 'a' to 'z')
//   * `isEnd` flag to mark the end of a word
//
// Example:
// Input: {"n", "ni", "nin", "ninj", "ninja"}
// - "ninja" is a complete string because all prefixes ("n", "ni", "nin", "ninj") exist
//
// Constraints:
// - Words contain only lowercase English letters
// - Length of word ≤ 1000
//
// Equivalent Problems:
// - Longest word with all prefixes
// - Prefix validation using Trie

#include <bits/stdc++.h>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
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

    void setEnd() {
        isEnd = true;
    }

    bool is_end() {
        return isEnd;
    }
};

// 2. Trie Class Implementation
// ----------------------------
//
// Idea:
// - Insert all words into the Trie
// - Check for complete strings by validating all prefixes
//
// Time Complexity:
// - Insertion → O(N * L)
// - Checking → O(N * L)
// Space Complexity:
// - O(total characters inserted)
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return false;
            node = node->get(ch);
            if(!node->is_end()) return false;
        }
        return true;
    }
};

// 3. Find Longest Complete String
// -------------------------------
string longestCompleteString(vector<string>& words) {
    Trie trie;
    for(string &word : words) trie.insert(word);

    string longest = "";
    for(string &word : words) {
        if(trie.checkIfPrefixExists(word)) {
            if(word.length() > longest.length()) {
                longest = word;
            } else if(word.length() == longest.length() && word < longest) {
                longest = word;
            }
        }
    }

    if(longest == "") return "none";
    return longest;
}

// 4. Example Usage
// ----------------
int main() {
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};

    string ans = longestCompleteString(words);
    cout << "Longest complete string: " << ans << endl; // Output: ninja

    return 0;
}
