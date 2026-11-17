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

void build(TreeNode* root,string &s){
    if(root==NULL){
        s+="#,";
        return ;
    }
    s+=to_string(root->val)+",";
    build(root->left,s);
    build(root->right,s);
}

string serialize(TreeNode* root){
    string s="";
    build(root,s);
    s.pop_back();
    return s;
}

TreeNode* make(vector<string>&tokens,int &idx){
    if(idx>=tokens.size()) return NULL;

    string cur=tokens[idx];
    idx++;

    if(cur=="#") return NULL;

    TreeNode* node=new TreeNode(stoi(cur));
    node->left=make(tokens,idx);
    node->right=make(tokens,idx);
    return node;
}

TreeNode* deserialize(string data){
    vector<string>tokens;
    stringstream ss(data);
    string item;

    while(getline(ss,item,',')){
        tokens.push_back(item);
    }

    int idx=0;
    return make(tokens,idx);
}

void print(TreeNode* root){
    if(root==NULL) return ;

    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

int main(){
    TreeNode* root=new TreeNode(1);
    TreeNode* l1=new TreeNode(2);
    TreeNode* r1=new TreeNode(3);
    root->left=l1;
    root->right=r1;
    TreeNode* l2=new TreeNode(4);
    TreeNode* r2=new TreeNode(5);
    r1->left=l2;
    r1->right=r2;

    string data=serialize(root);
    cout<<"serialized: "<<data<<"\n";

    TreeNode* newRoot=deserialize(data);
    cout<<"serialized again: "<<serialize(newRoot)<<"\n";
    cout<<"inorder of rebuilt tree: ";
    print(newRoot);

    cout<<"\nempty tree: "<<serialize(NULL);
}