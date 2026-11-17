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

TreeNode* insert(TreeNode* root,int val){
    if(root==NULL) return new TreeNode(val);

    TreeNode* curr=root;
    while(true){
        if(val<curr->val){
            if(curr->left==NULL){
                curr->left=new TreeNode(val);
                break;
            }
            curr=curr->left;
        }
        else{
            if(curr->right==NULL){
                curr->right=new TreeNode(val);
                break;
            }
            curr=curr->right;
        }
    }
    return root;
}

vector<int> kClosest(TreeNode* root,int x,int k){
    stack<TreeNode*>pred;
    stack<TreeNode*>succ;

    TreeNode* curr=root;
    while(curr!=NULL){
        if(curr->val<x){
            pred.push(curr);
            curr=curr->right;
        }
        else{
            succ.push(curr);
            curr=curr->left;
        }
    }

    vector<int>ans;

    while(k>0 && (!pred.empty() || !succ.empty())){
        bool takePred;

        if(pred.empty()) takePred=false;
        else if(succ.empty()) takePred=true;
        else takePred=((long long)x-pred.top()->val <= (long long)succ.top()->val-x);

        if(takePred){
            TreeNode* node=pred.top();
            pred.pop();
            ans.push_back(node->val);
            TreeNode* t=node->left;
            while(t!=NULL){
                pred.push(t);
                t=t->right;
            }
        }
        else{
            TreeNode* node=succ.top();
            succ.pop();
            ans.push_back(node->val);
            TreeNode* t=node->right;
            while(t!=NULL){
                succ.push(t);
                t=t->left;
            }
        }
        k--;
    }
    return ans;
}

int main(){
    int arr[]={10,5,15,2,7,12,20,6,8};
    TreeNode* root=NULL;
    for(int i=0;i<9;i++){
        root=insert(root,arr[i]);
    }

    int x=9;
    int k=4;

    vector<int> res=kClosest(root,x,k);

    for(auto it:res){
        cout<<it<<" ";
    }
}