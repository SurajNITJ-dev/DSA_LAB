
#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string ans;

    for (char ch : s) {
        unsigned char inputChar = static_cast<unsigned char>(ch);

        if (isspace(inputChar)) {
            continue;
        }
        else if (isalnum(inputChar)) {
            ans += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        if (st.top() != '(') {
            ans += st.top();
        }
        st.pop();
    }

    return ans;
}

int main() {
    string expression;
    cout<<"Enter the infix expression: ";
    getline(cin, expression);

    cout <<"Post fix Expression : "<< infixToPostfix(expression) << endl;
    return 0;
}