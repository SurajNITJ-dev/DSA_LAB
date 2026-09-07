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

void insertionAtk(ListNode* head, int k,int val) {
    if (head == nullptr) return;

  
    int n = 1;
    ListNode* temp = head;
    while(n!=k && temp!=head){
        n++;
        temp=temp->next;
    }

    ListNode* newel = new ListNode(val);
   
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = inpt(n);
    crcularLL(head);
    int k;
    cin>>k;
    int el;
    cout << "Enter the number to insert: ";
    cin >> el;

    insertionAtk(head,k, el);

    
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