#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int val,TreeNode* left,TreeNode* right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};

void print(TreeNode* root){
    if(root==NULL) return ;

    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}
void inorder(TreeNode* root,vector<TreeNode*>&v){
    if(root==NULL) return ;

    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);

}
void validateTree(TreeNode* root){
    vector<TreeNode*>temp;
    inorder(root,temp);

    int n=temp.size();
    int i=0;
    int j=n-1;

    
    while(i+1<n && temp[i]->val<temp[i+1]->val) i++;


    if(i+1>=n) return;

   
    while(j>0 && temp[j-1]->val<temp[j]->val) j--;


    int t=temp[i]->val;
    temp[i]->val=temp[j]->val;
    temp[j]->val=t;
}


int main(){
    TreeNode* root=new TreeNode(6);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r1=new TreeNode(8);
    root->left=l1;
    root->right=r1;
    TreeNode* l2=new TreeNode(1);
    TreeNode* r2=new TreeNode(7);
    TreeNode* l3=new TreeNode(4);
    TreeNode* r3=new TreeNode(9);
    l1->left=l2;
    l1->right=r2;
    r1->left=l3;
    r1->right=r3;

    cout<<"given tree: ";
    print(root);
    validateTree(root);
    cout<<"\ncorrected tree: ";print(root);
}