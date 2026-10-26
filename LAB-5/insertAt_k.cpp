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

ListNode* insertionAtk(ListNode* head, int k, int val) {
    if (k <= 0) {
        cout << "Invalid position" << endl;
        return head;
    }

    if (head == nullptr) {
        if (k != 1) {
            cout << "Invalid position" << endl;
            return nullptr;
        }

        ListNode* newHead = new ListNode(val);
        newHead->next = newHead;
        return newHead;
    }

    int n = 1;
    ListNode* tail = head;
    while (tail->next != head) {
        tail = tail->next;
        n++;
    }

    if (k > n + 1) {
        cout << "Invalid position" << endl;
        return head;
    }

    ListNode* newNode = new ListNode(val);
    if (k == 1) {
        newNode->next = head;
        tail->next = newNode;
        return newNode;
    }

    ListNode* previous = head;
    for (int i = 1; i < k - 1; i++) {
        previous = previous->next;
    }

    newNode->next = previous->next;
    previous->next = newNode;
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
    cout << "Enter position to insert (1-based): ";
    cin >> k;
    int el;
    cout << "Enter the number to insert: ";
    cin >> el;

    head = insertionAtk(head, k, el);

    cout << "List after insertion: ";
    print(head);

    deleteList(head);
    return 0;
}