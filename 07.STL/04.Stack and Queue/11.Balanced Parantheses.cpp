/*
===============================================================
1. Problem Statement: Balanced Parentheses
===============================================================

The problem involves checking if a given string, which contains only bracket characters, is a balanced parenthesis string.
The possible bracket characters are: ( ), { }, and [ ]

Conditions for a Balanced Parenthesis String:
--------------------------------------------
A string is considered balanced if:
• Every opening bracket has a corresponding closing bracket of the same type.
• Every closing bracket has a corresponding opening bracket of the same type.
• The brackets must follow the correct order (correct nesting and placement).

Examples of Balanced and Unbalanced Strings:
-------------------------------------------
• Balanced Example: ([{}])
    - All opening brackets have a matching closing bracket in the correct order.

• Unbalanced Example 1: {[)}
    - Brackets are not properly matched or ordered.

• Unbalanced Example 2: ((
    - Opening brackets are not closed.

• Unbalanced Example 3: ))
    - Closing brackets appear before any opening bracket.

================================================================
2. Why Use a Stack?
================================================================
• A Stack follows the LIFO (Last-In-First-Out) principle.
• When we find a closing bracket, we need to check if the last opening bracket matches.
• Therefore, we push all opening brackets into a stack, and for every closing bracket, we pop from the stack and compare.

================================================================
3. Algorithm (Dry Run using Stack)
================================================================
Steps:
-----
1. Initialize an empty stack.
2. Traverse the string character by character:
   - If it's an opening bracket, push it to the stack.
   - If it's a closing bracket:
     - If the stack is empty → return false (unbalanced).
     - Pop the top of the stack and check if it matches the current closing bracket.
     - If mismatch → return false.
3. After the loop:
   - If the stack is empty → return true (balanced).
   - Else → return false (unbalanced).

Dry Run Example: s = "([{}])"
----------------------------
Step 1: (  → push '('         → Stack: (
Step 2: [  → push '['         → Stack: ( [
Step 3: {  → push '{'         → Stack: ( [ {
Step 4: }  → matches '{'      → Stack: ( [
Step 5: ]  → matches '['      → Stack: (
Step 6: )  → matches '('      → Stack: empty
→ All matched → Balanced

Dry Run Example: s = "{[)}"
----------------------------
Step 1: {  → push '{'         → Stack: {
Step 2: [  → push '['         → Stack: { [
Step 3: )  → mismatch with '[' → return false
→ Unbalanced

================================================================
4. Code Implementation in C++
================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to check if a character is an opening bracket
bool isOpening(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// Function to check if two characters form a matching pair of brackets
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if the input string has balanced brackets
bool isBalancedParenthesis(const string& s) {
    stack<char> st;

    for (char ch : s) {
        // Case 1: If it's an opening bracket → Push onto stack
        if (isOpening(ch)) {
            st.push(ch);
        } 
        // Case 2: If it's a closing bracket
        else {
            // If stack is empty, there is no corresponding opening bracket
            if (st.empty()) return false;

            // Pop from stack and check if it matches
            char top = st.top();
            st.pop();

            if (!isMatchingPair(top, ch)) return false;
        }
    }

    // After loop, if stack is empty → all brackets were matched
    return st.empty();
}

/*
================================================================
5. Time and Space Complexity
================================================================

• Time Complexity: O(N)
    - N = length of the string.
    - We process each character once.
    - Stack operations (push, pop, top) are O(1) each.

• Space Complexity: O(N)
    - In the worst case (all characters are opening brackets), the stack stores N elements.

================================================================
6. Sample Main Function for Testing
================================================================
*/

int main() {
    string test1 = "([{}])";     // Balanced
    string test2 = "{[)}";       // Unbalanced
    string test3 = "((";         // Unbalanced
    string test4 = "))";         // Unbalanced

    cout << test1 << " -> " << (isBalancedParenthesis(test1) ? "Balanced" : "Unbalanced") << endl;
    cout << test2 << " -> " << (isBalancedParenthesis(test2) ? "Balanced" : "Unbalanced") << endl;
    cout << test3 << " -> " << (isBalancedParenthesis(test3) ? "Balanced" : "Unbalanced") << endl;
    cout << test4 << " -> " << (isBalancedParenthesis(test4) ? "Balanced" : "Unbalanced") << endl;

    return 0;
}
