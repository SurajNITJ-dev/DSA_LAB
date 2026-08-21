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

ListNode* delete_head(ListNode* head) {
    if (head == nullptr) return nullptr;
    
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode* delete_Tail(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    ListNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

ListNode* delete_mid(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    int n = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int midIndex = n / 2;
    temp = head;
    
    for (int i = 0; i < midIndex - 1; i++) {
        temp = temp->next;
    }

    ListNode* mid = temp->next;
    temp->next = mid->next;
    delete mid;

    return head;
}

ListNode* convertArr2LL(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for (int i = 1; i < n; i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 6, 7, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = convertArr2LL(arr, n);
    cout << "Original list: ";
    print(head);

    // head = delete_head(head);
    // cout << "After delete_head: ";
    // print(head);

    head = delete_mid(head);
    cout << "After delete_mid: ";
    print(head);

    // head = delete_Tail(head);
    // cout << "After delete_Tail: ";
    // print(head);

    return 0;
}