// 1. Problem Introduction
// -----------------------
//
// Goal: Implement a **Trie (Prefix Tree)** to efficiently store and search words.
//
// Trie Properties:
// - Tree-like structure for storing strings
// - Each node has:
//   * links array of size 26 (for lowercase 'a' to 'z')
//   * boolean flag `isEnd` to mark the end of a word
//
// Example:
// Inserted words: "hello", "help"
// - Search "help" → true
// - Search "hel" → false
// - StartsWith "hel" → true
//
// Constraints:
// - Words contain only lowercase English letters
// - Length of word ≤ 1000
//
// Equivalent Problems:
// - Prefix matching
// - Auto-complete suggestions

#include <bits/stdc++.h>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    TrieNode* links[26]; // Pointers to children
    bool isEnd;          // True if word ends here

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
// - Use TrieNode as building blocks
// - Support insert, search, and prefix check
//
// Time Complexity:
// - Insert/Search/StartsWith → O(length of word)
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

    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->is_end();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix) {
            if(!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return true;
    }
};

// 3. Example Usage
// ----------------
int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("help");
    trie.insert("helium");

    cout << boolalpha;
    cout << "Search 'help': " << trie.search("help") << endl;       // true
    cout << "Search 'hel': " << trie.search("hel") << endl;         // false
    cout << "StartsWith 'hel': " << trie.startsWith("hel") << endl; // true
    cout << "StartsWith 'hez': " << trie.startsWith("hez") << endl; // false

    return 0;
}
