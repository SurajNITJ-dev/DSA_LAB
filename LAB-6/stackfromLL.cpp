#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class stack {
private:
    Node* head = nullptr;
    int currentSize = 0;

public:
    void push(int a) {
        Node* newNode = new Node(a);
        newNode->next = head;
        head = newNode;
        currentSize++;
    }

    int pop() {
        if (head == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        currentSize--;
        return val;
    }

    int top() {
        if (head == nullptr) {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return head->data;
    }

    int siz() {
        return currentSize;
    }

    ~stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    stack st;
    st.push(7);
    st.push(9);
    st.push(3);
    st.push(1);
    cout << "Top element: " << st.top() << endl;
    cout << "Current size: " << st.siz() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Top element after pop: " << st.top() << endl;
    cout<< "Size after pop: "<<st.siz();
    return 0;
}