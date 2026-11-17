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

ListNode* deletionAtK(ListNode* head, int k) {
    if (head == nullptr || k <= 0) {
        cout << "Invalid position" << endl;
        return head;
    }

    int n = 1;
    ListNode* tail = head;
    while (tail->next != head) {
        tail = tail->next;
        n++;
    }

    if (k > n) {
        cout << "Invalid position" << endl;
        return head;
    }

    if (k == 1) {
        if (head == tail) {
            delete head;
            return nullptr;
        }

        ListNode* newHead = head->next;
        tail->next = newHead;
        delete head;
        return newHead;
    }

    ListNode* previous = head;
    for (int i = 1; i < k - 1; i++) {
        previous = previous->next;
    }

    ListNode* nodeToDelete = previous->next;
    previous->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
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

    int k;
    cout << "Enter position to delete (1-based): ";
    cin >> k;

    head = deletionAtK(head, k);
    cout << "List after deletion: ";
    print(head);

    deleteList(head);
    return 0;
}
