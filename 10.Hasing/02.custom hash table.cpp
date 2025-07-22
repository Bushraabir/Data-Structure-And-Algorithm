// A simple hash table with separate chaining (linked‑list buckets).
// Supports insert, search, delete, and printing the table state.

#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Our HashTable class
class HashTable {
private:
    vector<list<int>> buckets;  // each bucket is a linked list (list<int>)
    int bucketCount;            // total number of buckets

    // Simple hash function: modulo the bucket count
    int hashFunc(int key) const {
        return key % bucketCount;
    }

public:
    // Constructor: create `n` empty buckets
    HashTable(int n) : bucketCount(n), buckets(n) { }

    // Insert key if not already present
    void insertKey(int key) {
        int idx = hashFunc(key);
        // Check if key exists in this bucket
        for (int x : buckets[idx]) {
            if (x == key) {
                cout << "Key " << key << " already exists in bucket " << idx << "\n";
                return;
            }
        }
        // Not found → insert at end of list
        buckets[idx].push_back(key);
        cout << "Inserted " << key << " into bucket " << idx << "\n";
    }

    // Remove key if present
    void removeKey(int key) {
        int idx = hashFunc(key);
        auto &chain = buckets[idx];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                cout << "Removed " << key << " from bucket " << idx << "\n";
                return;
            }
        }
        cout << "Key " << key << " not found in bucket " << idx << "\n";
    }

    // Check if key exists
    bool contains(int key) const {
        int idx = hashFunc(key);
        for (int x : buckets[idx]) {
            if (x == key) return true;
        }
        return false;
    }

    // Print all buckets and their contents
    void printTable() const {
        cout << "\nHash Table:\n";
        for (int i = 0; i < bucketCount; ++i) {
            cout << "Bucket " << i << ": ";
            for (int x : buckets[i]) {
                cout << x << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    // 1) Create a table with 5 buckets
    HashTable ht(5);

    // 2) Insert keys
    ht.insertKey(10);
    ht.insertKey(15);
    ht.insertKey(20);
    ht.insertKey(25);
    ht.insertKey(30);

    // 3) Print current table state
    ht.printTable();

    // 4) Search for some keys
    int toFind[] = {15, 99};
    for (int key : toFind) {
        if (ht.contains(key))
            cout << "Key " << key << " is in the table\n";
        else
            cout << "Key " << key << " is NOT in the table\n";
    }

    // 5) Remove a key and try removing one that doesn't exist
    ht.removeKey(20);
    ht.removeKey(99);

    // 6) Print table after removal
    ht.printTable();

    return 0;
}
