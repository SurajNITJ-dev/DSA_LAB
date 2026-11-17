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

vector<int> topView(TreeNode* root){

    vector<int>ans;
    if(root==NULL) return ans;

    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    int minHd=0, maxHd=0;
    ans.push_back(root->val);

    while(!q.empty()){
        int n=q.size();

        for(int i=0;i<n;i++){
            TreeNode* node=q.front().first;
            int hd=q.front().second;
            q.pop();

            if(hd<minHd){
                ans.insert(ans.begin(),node->val);
                minHd=hd;
            }
            else if(hd>maxHd){
                ans.push_back(node->val);
                maxHd=hd;
            }

            if(node->left!=NULL) q.push({node->left,hd-1});
            if(node->right!=NULL) q.push({node->right,hd+1});
        }
    }
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(5);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r1=new TreeNode(7);
    root->left=l1;
    root->right=r1;
    TreeNode* l2=new TreeNode(2);
    TreeNode* r2=new TreeNode(4);
    TreeNode* l3=new TreeNode(6);
    TreeNode* r3=new TreeNode(8);
    l1->left=l2;
    l1->right=r2;
    r1->left=l3;
    r1->right=r3;

    vector<int> topvu;
    topvu=topView(root);

    for(auto it:topvu){
        cout<<it<<" ";
    }
}