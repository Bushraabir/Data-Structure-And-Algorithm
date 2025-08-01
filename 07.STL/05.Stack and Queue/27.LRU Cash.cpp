/*
 * Problem 8: Implement LRU Cache
 *
 * Problem Statement:
 * -------------------
 * Design and implement a Least Recently Used (LRU) Cache with the following operations:
 * - LRUCache(int capacity): Initialize the cache with a given capacity.
 * - int get(int key): Return the value of the key if it exists in the cache, otherwise return -1.
 *   Also marks the key as recently used.
 * - void put(int key, int value): Insert or update the value of the key.
 *   If the cache reaches its capacity, evict the least recently used item before inserting the new one.
 *   Also marks the key as recently used.
 *
 * Requirements:
 * - Both get and put operations must run in O(1) average time complexity.
 *
 * Example:
 * Cache Capacity: 4
 * put(2,6)       → Cache: (2,6)
 * put(4,7)       → Cache: (4,7), (2,6)
 * put(8,11)      → Cache: (8,11), (4,7), (2,6)
 * put(7,10)      → Cache: (7,10), (8,11), (4,7), (2,6)
 * get(2)         → Returns 6, Cache updated: (2,6), (7,10), (8,11), (4,7)
 * get(8)         → Returns 11, Cache updated: (8,11), (2,6), (7,10), (4,7)
 * put(5,6)       → Cache full, evicts (4,7), adds (5,6): (5,6), (8,11), (2,6), (7,10)
 * put(5,7)       → Updates (5,6) to (5,7), moves to front: (5,7), (8,11), (2,6), (7,10)
 *
 * Intuition:
 * ----------
 * - Use a Doubly Linked List to keep track of usage order (head = most recently used, tail = least recently used).
 * - Use a Hash Map to store key → node reference for O(1) access.
 * - When a key is accessed or updated, move its node to the front (MRU position).
 * - On cache overflow, remove the node at the tail (LRU).
 *
 * Time Complexity:
 * ----------------
 * - get and put: O(1)
 *
 * Space Complexity:
 * -----------------
 * - O(capacity) for the hashmap and doubly linked list nodes
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cacheMap;
    int capacity;
    Node* head; // Dummy head
    Node* tail; // Dummy tail

    // Remove node from DLL
    void delete_node(Node* node) {
        Node* prev_node = node->prev;
        Node* next_node = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    // Insert node right after head (most recently used)
    void insert_after_head(Node* node) {
        Node* first = head->next;
        head->next = node;
        node->prev = head;
        node->next = first;
        first->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1); // Dummy nodes
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        Node* node = cacheMap[key];
        int val = node->value;

        // Move accessed node to front (MRU)
        delete_node(node);
        insert_after_head(node);

        return val;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update existing node value and move to front
            Node* node = cacheMap[key];
            node->value = value;
            delete_node(node);
            insert_after_head(node);
        } else {
            if (cacheMap.size() == capacity) {
                // Evict LRU node (tail->prev)
                Node* lru = tail->prev;
                delete_node(lru);
                cacheMap.erase(lru->key);
                delete lru;
            }
            // Insert new node
            Node* new_node = new Node(key, value);
            insert_after_head(new_node);
            cacheMap[key] = new_node;
        }
    }

    ~LRUCache() {
        // Clean up nodes
        Node* curr = head;
        while (curr) {
            Node* next_node = curr->next;
            delete curr;
            curr = next_node;
        }
    }
};

// Example usage
int main() {
    LRUCache cache(4);

    cache.put(2, 6);
    cache.put(4, 7);
    cache.put(8, 11);
    cache.put(7, 10);

    cout << cache.get(2) << endl; // 6
    cout << cache.get(8) << endl; // 11

    cache.put(5, 6);  // Evicts (4,7)
    cache.put(5, 7);  // Updates (5,6) to (5,7)

    return 0;
}
