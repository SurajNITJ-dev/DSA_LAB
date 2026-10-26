#include <iostream>
using namespace std;

class stack {
public:
    int st[10];
    int topIndex = -1; 

    void push(int a) {
        if (topIndex >= 9) { 
            cout << "Stack Overflow" << endl;
            return;
        }
        topIndex += 1;
        st[topIndex] = a;
    }

    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return st[topIndex--];
    }

    int top() {
        if (topIndex == -1) {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return st[topIndex]; 
    }

    int siz() {
        return topIndex + 1; 
    }
};

int main() {
    stack st;
    st.push(3);
    st.push(8);
    st.push(7);

    cout << "Top element: " << st.top() << endl;
    cout << "Current size: " << st.siz() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Top element after pop: " << st.top() << endl;
    cout << "size after pop: " << st.siz() << endl;
    return 0;
}