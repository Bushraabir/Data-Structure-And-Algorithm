/*
 * Problem 9: Implement LFU Cache
 *
 * Problem Statement:
 * -------------------
 * Design and implement a Least Frequently Used (LFU) Cache with the following operations:
 * - LFUCache(int capacity): Initialize the cache with a given capacity.
 * - int get(int key): Return the value of the key if it exists, otherwise return -1.
 *   Accessing a key increases its frequency and updates its recency.
 * - void put(int key, int value): Insert or update the value of the key.
 *   If the cache is at capacity, evict the least frequently used item.
 *   If multiple items have the same minimum frequency, evict the least recently used among them.
 *   Inserted or updated keys start with frequency = 1 and are considered most recently used in that frequency.
 *
 * Requirements:
 * - Both get and put operations must run in O(1) average time complexity.
 *
 * Example:
 * Cache Capacity: 3
 * put(1, 10)          → Cache: {(1,10), freq=1}
 * put(2, 20)          → Cache: {(2,20), freq=1}, {(1,10), freq=1}
 * put(3, 30)          → Cache: {(3,30), freq=1}, {(2,20), freq=1}, {(1,10), freq=1}
 * get(1) = 10         → freq(1) = 2; Cache reordered accordingly
 * put(4, 40)          → Evicts key 2 (freq=1 and least recently used)
 *                      → Cache: {(4,40), freq=1}, {(3,30), freq=1}, {(1,10), freq=2}
 *
 * Intuition:
 * ----------
 * - Use a map<int, Node*> for key-node lookup in O(1).
 * - Use a map<int, list<Node*>> to group nodes by their frequencies.
 * - Each frequency group is a doubly linked list ordered by recency (MRU at front).
 * - Maintain min_frequency to know which frequency list to evict from.
 * - On get/put access:
 *     * Remove node from old frequency list.
 *     * Increase node frequency.
 *     * Add node to new frequency list at front (MRU).
 *     * Update min_frequency if old freq list becomes empty.
 *
 * Time Complexity:
 * ----------------
 * - get and put: O(1) average
 *
 * Space Complexity:
 * -----------------
 * - O(capacity) for maps and linked lists
 */

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

struct Node {
    int key, value, freq;
    Node(int k, int v) : key(k), value(v), freq(1) {}
};

class LFUCache {
private:
    int capacity;
    int current_size;
    int min_freq;
    unordered_map<int, list<Node>::iterator> key_node_iter_map; // key -> iterator to node in freq list
    unordered_map<int, list<Node>> freq_list_map;               // freq -> list of nodes (MRU front)
    
    void updateFrequency(int key) {
        // Get node iterator and current freq
        auto node_iter = key_node_iter_map[key];
        int freq = node_iter->freq;
        
        // Remove node from current freq list
        freq_list_map[freq].erase(node_iter);
        if (freq_list_map[freq].empty()) {
            freq_list_map.erase(freq);
            if (min_freq == freq) min_freq++;
        }
        
        // Insert node into freq+1 list at front
        freq++;
        freq_list_map[freq].push_front(Node(key, node_iter->value));
        freq_list_map[freq].front().freq = freq;
        key_node_iter_map[key] = freq_list_map[freq].begin();
    }
    
public:
    LFUCache(int cap) {
        capacity = cap;
        current_size = 0;
        min_freq = 0;
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        if (key_node_iter_map.find(key) == key_node_iter_map.end()) return -1;
        
        int val = key_node_iter_map[key]->value;
        updateFrequency(key);
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (key_node_iter_map.find(key) != key_node_iter_map.end()) {
            // Key exists: update value and frequency
            auto node_iter = key_node_iter_map[key];
            node_iter->value = value;
            updateFrequency(key);
        } else {
            // New key
            if (current_size == capacity) {
                // Evict least freq & LRU node from min_freq list (tail)
                auto& list_for_min_freq = freq_list_map[min_freq];
                auto node_to_evict = list_for_min_freq.back();
                int evict_key = node_to_evict.key;
                
                list_for_min_freq.pop_back();
                if (list_for_min_freq.empty()) {
                    freq_list_map.erase(min_freq);
                }
                key_node_iter_map.erase(evict_key);
                current_size--;
            }
            
            // Insert new node with freq=1 at front
            freq_list_map[1].push_front(Node(key, value));
            key_node_iter_map[key] = freq_list_map[1].begin();
            min_freq = 1;
            current_size++;
        }
    }
};

// Example Usage
int main() {
    LFUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    cout << cache.get(1) << endl;  // 10 (freq 1->2)
    cache.put(4, 40);               // evicts key 2 (freq=1, LRU)
    
    cout << cache.get(2) << endl;  // -1 (evicted)
    cout << cache.get(3) << endl;  // 30 (freq 1->2)
    cout << cache.get(4) << endl;  // 40 (freq 1->2)

    return 0;
}

/*
 * This code implements a Least Frequently Used (LFU) Cache using a combination of unordered maps and lists.
 * It efficiently handles get and put operations while maintaining the LFU eviction policy.
 */