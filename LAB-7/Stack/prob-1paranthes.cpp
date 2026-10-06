#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void validParanthesiscount(const string& s) {
    stack<int> st;
    vector<bool> isValid(s.length(), false);

    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                isValid[st.top()] = true;
                isValid[i] = true;
                st.pop();
            }
        }
    }

    int maxLen = 0;
    int currentLen = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(' || s[i] == ')') {
            if (isValid[i]) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }
    }

    cout << "Longest Valid Parentheses Length: " << maxLen << endl;

    cout << "Invalid Parentheses Indices: ";
    bool foundInvalid = false;
    for (int i = 0; i < (int)s.length(); i++) {
        if ((s[i] == '(' || s[i] == ')') && !isValid[i]) {
            cout << i << " ";
            foundInvalid = true;
        }
    }
    if (!foundInvalid) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    string s;
    cin >> s;
    validParanthesiscount(s);
    return 0;
}