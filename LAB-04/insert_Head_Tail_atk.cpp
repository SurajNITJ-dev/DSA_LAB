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

ListNode* InsertElement_head(ListNode* head, int el) {
    return new ListNode(el, head);
}

ListNode* InsertElement_Tail(ListNode* head, int el) {
    if (head == nullptr) {
        return new ListNode(el);
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new ListNode(el);
    return head;
}

ListNode* InsertElement_mid(ListNode* head, int el) {
    int k=0;
    ListNode* temp = head;
    while(temp!=NULL){
        k++;
        temp=temp->next;
    }

    temp = head;
    k=k/2;
    int count = 1;
    while (temp != nullptr && count < k ) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) return head;

    ListNode* newNode = new ListNode(el, temp->next);
    temp->next = newNode;

    return head;
}

ListNode* InsertElement_AtK(ListNode* head, int k, int el) {
    if (k <= 0) return head;

    if (k == 1) {
        return new ListNode(el, head);
    }

    ListNode* temp = head;
    int count = 1;

    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) return head;

    ListNode* newNode = new ListNode(el, temp->next);
    temp->next = newNode;

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
    cout<<"Original Array: ";
    print(head);
    cout<<"Insertion at Tail: ";
    // head = InsertElement_head(head,11);
    head = InsertElement_Tail(head, 12);
    // head = InsertElement_AtK(head, 3, 99);
    // head = InsertElement_mid(head, 99);

    print(head);

    return 0;
}