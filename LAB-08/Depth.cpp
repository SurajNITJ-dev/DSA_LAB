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

int depth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    if (root->left == nullptr) {
        return 1 + depth(root->right);
    }

    if (root->right == nullptr) {
        return 1 + depth(root->left);
    }

    return 1 + min(depth(root->left), depth(root->right));
}

int main() {
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
    
    int mindepth = depth(root);
    cout << "Minimum depth: " << mindepth << endl;
    return 0;
}