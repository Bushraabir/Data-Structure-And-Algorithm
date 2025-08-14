//  Min Stack Problem
// Find the minimum element in a stack
// 
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// Approach 1: Using a Pair in the Stack
// Concept: Store (value, current_minimum) at every step
class MinStackWithPair {
private:
    stack<pair<int, int>> st; // pair<value, current_minimum>

public:
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            // Store current value and the minimum so far
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        if (!st.empty()) st.pop();
    }

    int top() {
        return st.top().first; // Return the actual top value
    }

    int getMin() {
        return st.top().second; // Return the minimum value so far
    }
};
// Time Complexity: O(1) for all operations
// Space Complexity: O(N) — two values stored per element (value + min)


// Approach 2: Optimized Space using Mathematical Encoding
// Concept: Store only one value per node and encode new minimums
// Warning: Using int may overflow if values are large (safe for small numbers)

class MinStackOptimizedInt {
private:
    stack<int> st;
    int minElement; // To track the minimum element

public:
    MinStackOptimizedInt() {
        minElement = INT_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            minElement = val;
            st.push(val);
        } else if (val >= minElement) {
            st.push(val);
        } else {
            // Encode the new minimum value
            // ****************  Formula: encoded = 2*val - minElement ****************
            // Warning: may overflow if val or minElement is large
            int encoded = 2 * val - minElement;
            st.push(encoded);
            minElement = val; // Update minElement
        }
    }

    void pop() {
        if (st.empty()) return;

        int topVal = st.top();
        st.pop();

        if (topVal < minElement) {
            // Decoding previous minimum
            // Formula: previousMin = 2*minElement - encoded
            minElement = 2 * minElement - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;

        int topVal = st.top();
        if (topVal >= minElement) {
            return topVal; // Normal value
        } else {
            // Encoded value, real top is minElement
            return minElement;
        }
    }

    int getMin() {
        return minElement;
    }
};
// Time Complexity: O(1) for all operations
// Space Complexity: O(N) — only one value per element is stored

// Summary of Mathematical Trick
// When pushing a new min:
//      push modified value = (2 * val - minElement)
//      update minElement = val
// When popping a modified value:
//      minElement = (2 * minElement - encoded_value)
// This allows recovery of the previous minimum without storing extra info
// Using int may overflow for large values; for safety, use long long

int main() {
    cout << "Approach 1: Using Pair in Stack\n";
    MinStackWithPair ms1;
    ms1.push(5);
    ms1.push(3);
    ms1.push(7);
    cout << "Top: " << ms1.top() << ", Min: " << ms1.getMin() << endl;
    ms1.pop();
    cout << "Top: " << ms1.top() << ", Min: " << ms1.getMin() << endl;

    cout << "\nApproach 2: Optimized Min Stack (int)\n";
    MinStackOptimizedInt ms2;
    ms2.push(5);
    ms2.push(3);
    ms2.push(7);
    cout << "Top: " << ms2.top() << ", Min: " << ms2.getMin() << endl;
    ms2.pop();
    cout << "Top: " << ms2.top() << ", Min: " << ms2.getMin() << endl;

    return 0;
}
