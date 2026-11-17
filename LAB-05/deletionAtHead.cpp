#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val, ListNode* next) {
        this->val = val;
        this->next = next;
    }

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode* inpt(int n) {
    if (n <= 0) return nullptr;

    int a;
    cout << "Enter head node: ";
    cin >> a;
    ListNode* head = new ListNode(a);
    ListNode* mover = head;
    cout << "Enter the rest of the nodes(value): ";
    for (int i = 1; i < n; i++) {
        cin >> a;
        ListNode* temp = new ListNode(a);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void crcularLL(ListNode* head) {
    if (head == nullptr) return;

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

ListNode* deletionAtHead(ListNode* head) {
    if (head == nullptr) return nullptr;

    if (head->next == head) {
        delete head;
        return nullptr;
    }

    ListNode* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    ListNode* newHead = head->next;
    tail->next = newHead;
    delete head;
    return newHead;
}

void print(ListNode* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    ListNode* temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteList(ListNode* head) {
    if (head == nullptr) return;

    ListNode* temp = head->next;
    while (temp != head) {
        ListNode* next = temp->next;
        delete temp;
        temp = next;
    }
    delete head;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = inpt(n);
    crcularLL(head);

    head = deletionAtHead(head);
    cout << "List after deleting head: ";
    print(head);

    deleteList(head);
    return 0;
}
