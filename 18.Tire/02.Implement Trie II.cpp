// 1. Problem Introduction
// -----------------------
//
// Goal: Implement an **advanced Trie** to store words, count occurrences, 
//       count prefixes, and erase words.
//
// Trie Properties:
// - Tree-like structure for storing strings
// - Each node has:
//   * links array of size 26 (for lowercase 'a' to 'z')
//   * `endWith` to count how many words end at this node
//   * `countPrefix` to count how many words pass through this node
//
// Example:
// Inserted words: "apple", "apple", "apps"
// - countWordsEqualTo("apple") → 2
// - countWordsStartingWith("ap") → 3
// - After erase("apple"), countWordsEqualTo("apple") → 1
//
// Constraints:
// - Words contain only lowercase English letters
// - Length of word ≤ 1000
//
// Equivalent Problems:
// - Counting occurrences of words
// - Prefix matching with frequency

#include <bits/stdc++.h>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    TrieNode* links[26];
    int endWith;
    int countPrefix;

    TrieNode() {
        endWith = 0;
        countPrefix = 0;
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

    void increaseEnd() {
        endWith++;
    }

    void increasePrefix() {
        countPrefix++;
    }

    void deleteEnd() {
        endWith--;
    }

    void reducePrefix() {
        countPrefix--;
    }

    int getEnd() {
        return endWith;
    }

    int getPrefix() {
        return countPrefix;
    }
};

// 2. Trie Class Implementation
// ----------------------------
//
// Idea:
// - Use TrieNode as building blocks
// - Support insert, countWordsEqualTo, countWordsStartingWith, erase
//
// Time Complexity:
// - All operations → O(length of word/prefix)
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
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix) {
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    void erase(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return; // Word not present
            node = node->get(ch);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

// 3. Example Usage
// ----------------
int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("apps");

    cout << "Words equal to 'apple': " << trie.countWordsEqualTo("apple") << endl; // 2
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl; // 3

    trie.erase("apple");
    cout << "After erase, words equal to 'apple': " << trie.countWordsEqualTo("apple") << endl; // 1
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl; // 2

    return 0;
}
