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

bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    if (left->val != right->val) return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool chekMirrorTree(TreeNode* root) {
    if (root == nullptr) return true;
    return isMirror(root->left, root->right);
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
    cout << (chekMirrorTree(root) ? "Mirror" : "Not a mirror") << endl;
    return 0;
}