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

    if (n > 1) {
        cout << "Enter the rest of the nodes(value): ";
        for (int i = 1; i < n; i++) {
            cin >> a;
            ListNode* temp = new ListNode(a);
            mover->next = temp;
            mover = temp;
        }
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

ListNode* revrsCLL(ListNode* head) {
    if (head == nullptr || head->next == head) return head;

    ListNode* prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }

    ListNode* curr = head;
    ListNode* nextNode = nullptr;

    do {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    return prev;
}

void print(ListNode* head) {
    if (head == nullptr) {
        cout << "Empty List\n";
        return;
    }

    ListNode* temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes." << endl;
        return 0;
    }

    ListNode* head = inpt(n);
    crcularLL(head);

    cout << "Reversing Circular Linked List...\n";
    ListNode* newHead = revrsCLL(head);

    cout << "Reversed List: ";
    print(newHead);

    return 0;
}