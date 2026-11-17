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

ListNode* revrSLL(ListNode* head){

    ListNode* temp=head;
    ListNode* prev=nullptr;
    ListNode* front=nullptr;

    while(temp!=NULL){
            
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

    return prev;
}

void print(ListNode* head){
    ListNode* temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main(){

    int n ;
    cout<<"Enter number of nodes: ";
    cin>>n;
    ListNode* head=inpt(n);
    head=revrSLL(head);
    print(head);
}