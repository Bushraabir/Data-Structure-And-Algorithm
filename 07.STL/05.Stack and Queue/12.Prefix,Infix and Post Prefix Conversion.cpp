// 1. Introduction to Arithmetic Expressions
// ----------------------------------------

// Operator: Symbols that perform operations
// Examples: ^ (power), * (multiplication), / (division), + (addition), - (subtraction)

// Operand: The values or variables on which operations are performed
// Examples: A-Z, a-z, 0-9

// Priority of Operators:
// ^  -> Priority 3
// *, / -> Priority 2
// +, - -> Priority 1
// others (like brackets) -> Priority -1


// 2. Types of Arithmetic Expressions
// ----------------------------------

// Infix: Operator is between operands -> A + B
// Prefix: Operator is before operands -> +AB
// Postfix: Operator is after operands -> AB+


// 3. Conversions Using Stack
// ---------------------------
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int getPriority(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

// 3.1 Infix to Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string ans;

    for(char c : s) {
        if(isalnum(c)) {
            ans += c; // Operand: append to result
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top(); st.pop();
            }
            st.pop(); // remove '('
        }
        else {
            while(!st.empty() && getPriority(c) <= getPriority(st.top())) {
                ans += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        ans += st.top(); st.pop();
    }
    return ans;
}
// Time Complexity: O(N)
// Space Complexity: O(N)


// 3.2 Infix to Prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for(char &c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
// Time Complexity: O(N)
// Space Complexity: O(N)


// 3.3 Postfix to Infix
string postfixToInfix(string s) {
    stack<string> st;
    for(char c : s) {
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = "(" + op2 + c + op1 + ")";
            st.push(exp);
        }
    }
    return st.top();
}
// Time Complexity: O(N) ~ O(N^2) due to string concat
// Space Complexity: O(N)


// 3.4 Prefix to Infix
string prefixToInfix(string s) {
    stack<string> st;
    for(int i = s.size()-1; i >= 0; --i) {
        char c = s[i];
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}
// Time Complexity: O(N) ~ O(N^2)
// Space Complexity: O(N)


// 3.5 Postfix to Prefix
string postfixToPrefix(string s) {
    stack<string> st;
    for(char c : s) {
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = c + op2 + op1;
            st.push(exp);
        }
    }
    return st.top();
}
// Time Complexity: O(N) ~ O(N^2)
// Space Complexity: O(N)


// 3.6 Prefix to Postfix
string prefixToPostfix(string s) {
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; --i) {
        char c = s[i];
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = op1 + op2 + c;
            st.push(exp);
        }
    }
    return st.top();
}
// Time Complexity: O(N) ~ O(N^2)
// Space Complexity: O(N)


// 4. Conclusion
// ------------
// These expression conversions are essential for practicing stack logic and improving algorithmic understanding
// Though less common in interviews directly, they build strong foundational understanding


// Example usage (can be removed for competitive programming):
int main() {
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix to Postfix: " << infixToPostfix(infix) << endl;
    cout << "Infix to Prefix: " << infixToPrefix(infix) << endl;

    string postfix = "ABC*+DEFG^/*H*-";
    cout << "Postfix to Infix: " << postfixToInfix(postfix) << endl;
    cout << "Postfix to Prefix: " << postfixToPrefix(postfix) << endl;

    string prefix = "-+A*BC*/*DE^FGH";
    cout << "Prefix to Infix: " << prefixToInfix(prefix) << endl;
    cout << "Prefix to Postfix: " << prefixToPostfix(prefix) << endl;
    return 0;
}
