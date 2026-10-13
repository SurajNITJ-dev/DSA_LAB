#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* leftChild, TreeNode* rightChild)
        : val(v), left(leftChild), right(rightChild) {}
};

void inorder(TreeNode* root,vector<int>& v){

    if(root==NULL) return ;

    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
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

    vector<int>v;
    inorder(root,v);

    int k;
    cout<<"Enter the k for kth large & kth small : ";
    cin>>k;
    
    if((k>v.size() || k<1) || (k>v.size())|| k<1){
        cout<<"ivalid request";
    }

    cout<<"kth largest no is:"<<v[v.size()-k]<<endl;
    cout<<"kth smallest no is:"<<v[v.size()+ k];


}

