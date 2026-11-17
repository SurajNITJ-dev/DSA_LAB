#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* curr = head;
    Node* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    return temp->prev;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original: ";
    print(head);

    head = reverseDLL(head);

    cout << "Reversed: ";
    print(head);

    return 0;
}