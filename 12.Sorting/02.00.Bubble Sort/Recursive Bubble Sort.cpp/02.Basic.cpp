/* 
Problem: Sort Product Prices Using Recursive Bubble Sort

You are given a list of product prices in a store represented as an array.  
Your task is to sort these prices in ascending order using the Recursive Bubble Sort algorithm.  
This problem will help you understand how recursion can be used to implement bubble sort and how  
the largest element bubbles to the end after each recursive call.

Working Principle:
- Compare adjacent elements and swap if they are in the wrong order.
- Recursively sort the remaining unsorted part of the array.
- Stop when the array size reduces to 1 or no swaps occur.

Time Complexity:
    - Best Case (Already Sorted): O(N)
    - Average Case: O(N^2)
    - Worst Case (Reversely Sorted): O(N^2)

Space Complexity:
    - O(N) due to recursion stack

Stable Sort: Yes
Adaptive: Yes
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Bubble Sort Function
void recursiveBubbleSort(vector<int>& arr, int n) {
    if (n == 1) return; // Base case

    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    if (!swapped) return; // Already sorted

    recursiveBubbleSort(arr, n - 1);
}

int main() {
    // Product prices in dollars
    vector<int> prices = {150, 99, 120, 75, 180, 110};

    cout << "Original product prices:\n";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << "\n\n";

    recursiveBubbleSort(prices, prices.size());

    cout << "Sorted product prices using Recursive Bubble Sort:\n";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}
