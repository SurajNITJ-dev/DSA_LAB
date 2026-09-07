#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val,ListNode* next){
        this->next=next;
        this->val=val;
    }

    ListNode(int val){
        this->val=val;
        next=nullptr;
    }

    
};

ListNode* inpt(int n){
    int a;
    cout<<"Enter head node: ";
    cin>>a;
    ListNode* head=new ListNode(a);
    ListNode* mover=head;
    cout<<"Enter the rest of the nodes(value): ";
    for(int i=1;i<n;i++){
        cin>>a;
        ListNode* temp=new ListNode(a);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void crcularLL(ListNode* head){
    ListNode* temp=head;

    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head;
    
}

bool isCircular(ListNode* head){

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast->next!=nullptr && fast->next->next!=nullptr){

        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return true;
    }

    return false;
}

ListNode* insertionAtHead(ListNode* head,int val){

    ListNode* temp=head;
    ListNode* newHead=new ListNode(val);
    newHead->next=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=newHead;

    return newHead;
}

int main() {
    
    int n ;
    cout<<"Enter number of nodes: ";
    cin>>n;
    ListNode* head=inpt(n);
    crcularLL(head);
    int el;
    cout<<"Enter the number to insert: ";
    cin>>el;
    cout<<"Previous Head :"<<head->val<<endl;
    cout<<"New Head :"<<insertionAtHead(head,el)->val<<endl;
    ListNode* newHead=insertionAtHead(head,el);
    ListNode* temp=newHead;
    while(temp->next!=newHead){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return 0;
}