/*
Greedy Algorithm – Fractional Knapsack to Maximize Total Value

Intuition & Logic:
- Given n items, each with a value and weight, and a knapsack capacity W.
- Goal: maximize total value in knapsack.
- Key feature: can take fractions of items.
- Approach:
    - Calculate value-per-weight ratio for each item.
    - Sort items in descending order of value-per-weight.
    - Iterate items:
        * Take whole item if it fits.
        * Otherwise, take fractional part that fits.
    - This greedy choice maximizes value for each weight added.

Problem Example:
Items: 
- A(100,20), B(60,10), C(100,50), D(200,50)
Sorted by value/weight: B(6), A(5), D(4), C(2)

Knapsack capacity: 90
Process:
- Take B fully (10 weight), remaining 80, total = 60
- Take A fully (20 weight), remaining 60, total = 160
- Take D fully (50 weight), remaining 10, total = 360
- Take 10/50 fraction of C, value = 2 * 10 = 20, total = 380

Algorithm:
- Sort items by value/weight descending.
- Initialize totalValue = 0.0, remainingWeight = W.
- For each item:
    - If item.weight <= remainingWeight:
        - totalValue += item.value
        - remainingWeight -= item.weight
    - Else:
        - fractionValue = (item.value / item.weight) * remainingWeight
        - totalValue += fractionValue
        - remainingWeight = 0
        - break
- Return totalValue

TIME & SPACE COMPLEXITY:
- Time: O(N log N) due to sorting.
- Space: O(1) if sorting in-place.

*/

/* -------------------- FRACTIONAL KNAPSACK IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items by value/weight ratio descending
bool cmp(const Item& a, const Item& b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item>& items, int W) {
    // Sort items by value per weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    int remainingWeight = W;

    for (auto& item : items) {
        if (item.weight <= remainingWeight) {
            // Take whole item
            totalValue += item.value;
            remainingWeight -= item.weight;
        } else {
            // Take fraction of item
            double fractionValue = ((double)item.value / item.weight) * remainingWeight;
            totalValue += fractionValue;
            remainingWeight = 0;
            break; // Knapsack full
        }
    }

    return totalValue;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<Item> items = {
        {100, 20},
        {60, 10},
        {100, 50},
        {200, 50}
    };
    int capacity = 90;

    cout << "Maximum value in knapsack = " << fixed << setprecision(2)
         << fractionalKnapsack(items, capacity) << "\n";  // 380.00

    return 0;
}
