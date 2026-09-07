#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val, ListNode* next) {
        this->next = next;
        this->val = val;
    }

    ListNode(int val) {
        this->val = val;
        next = nullptr;
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

bool isCircular(ListNode* head) {
    if (head == nullptr) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

void insertionAtend(ListNode* head, int val) {
    if (head == nullptr) return;

    ListNode* temp = head;
    ListNode* newtail = new ListNode(val, head);
    
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newtail;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    ListNode* head = inpt(n);
    crcularLL(head);

    int el;
    cout << "Enter the number to insert: ";
    cin >> el;
    
    insertionAtend(head, el);

    
    ListNode* temp = head;
    if (head != nullptr) {
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    return 0;
}