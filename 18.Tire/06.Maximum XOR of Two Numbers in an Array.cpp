// 1. Problem Introduction
// -----------------------
//
// Goal: Find the **maximum XOR value** of two numbers, one from array1 and one from array2.
//
// Technique:
// - Use a Trie to store binary representations of numbers
// - Each Trie node has two links: 0 and 1
// - Insert numbers bit by bit from MSB to LSB
// - For a given number x, traverse Trie greedily to maximize XOR by choosing opposite bits first
//
// Example:
// array1 = {9, 8, 7, 5, 4}, array2 = {2, 6}
// Maximum XOR occurs for 9 ^ 6 = 15 (binary 1111)
//
// Constraints:
// - Non-negative integers
// - 32-bit integers for practical implementation
// - Arrays size ≤ 10^5

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

    // Insert number into Trie (bitwise, MSB to LSB)
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

    // Find maximum XOR of num with numbers in Trie
    int getMax(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            if(node->containsKey(oppositeBit)) {
                maxXor |= (1 << i); // Set this bit in result
                node = node->get(oppositeBit);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }
};

// 4. Maximum XOR of Two Arrays
// -----------------------------
int findMaximumXOR(vector<int>& array1, vector<int>& array2) {
    Trie trie;
    for(int num : array1) trie.insert(num);

    int maxOverallXor = 0;
    for(int num : array2) {
        maxOverallXor = max(maxOverallXor, trie.getMax(num));
    }

    return maxOverallXor;
}

// 5. Example Usage
// ----------------
int main() {
    vector<int> array1 = {9, 8, 7, 5, 4};
    vector<int> array2 = {2, 6};

    int maxXor = findMaximumXOR(array1, array2);
    cout << "Maximum XOR of two numbers: " << maxXor << endl; // Output: 15

    return 0;
}
