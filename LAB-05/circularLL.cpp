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

    while(fast!=nullptr && fast->next!=nullptr){

        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return true;
    }

    return false;
}


int main() {
    
    int n ;
    cout<<"Enter number of nodes: ";
    cin>>n;
    ListNode* head=inpt(n);
    cout<<isCircular(head)<<endl;
    crcularLL(head);
    cout<<isCircular(head);

    return 0;
}