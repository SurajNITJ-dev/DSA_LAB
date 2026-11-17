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

class Info{
public:
    bool isBST;
    int mn;
    int mx;
    int sum;

    Info(bool isBST,int mn,int mx,int sum){
        this->isBST=isBST;
        this->mn=mn;
        this->mx=mx;
        this->sum=sum;
    }
};

Info solve(TreeNode* root,int &ans){
    if(root==NULL) return Info(true,INT_MAX,INT_MIN,0);

    Info l=solve(root->left,ans);
    Info r=solve(root->right,ans);

    if(l.isBST && r.isBST && l.mx<root->val && root->val<r.mn){
        int total=l.sum+r.sum+root->val;
        ans=max(ans,total);
        return Info(true,min(l.mn,root->val),max(r.mx,root->val),total);
    }
    return Info(false,INT_MIN,INT_MAX,0);
}

int maxBSTSum(TreeNode* root){
    int ans=INT_MIN;
    solve(root,ans);
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(5);
    TreeNode* l1=new TreeNode(4);
    TreeNode* r1=new TreeNode(8);
    root->left=l1;
    root->right=r1;
    TreeNode* l2=new TreeNode(3);
    TreeNode* r2=new TreeNode(6);
    TreeNode* l3=new TreeNode(7);
    TreeNode* r3=new TreeNode(9);
    l1->left=l2;
    l1->right=r2;
    r1->left=l3;
    r1->right=r3;

    cout<<"Maximum BST subtree sum = "<<maxBSTSum(root);
}