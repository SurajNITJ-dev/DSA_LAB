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

void inorder(TreeNode* root, vector<int>& v) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        v.push_back(curr->val);
        curr = curr->right;
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    TreeNode* l1 = new TreeNode(3);
    TreeNode* r1 = new TreeNode(7);
    root->left = l1;
    root->right = r1;
    l1->left = new TreeNode(2);
    l1->right = new TreeNode(4);
    r1->left = new TreeNode(6);
    r1->right = new TreeNode(8);

    vector<int> v;
    inorder(root, v);

    int k;
    cout << "Enter the k for kth large & kth small : ";
    cin >> k;

    if (k < 1 || k > (int)v.size()) {
        cout << "Invalid request\n";
        return 0;
    }

    cout << "kth largest no is: " << v[v.size() - k] << endl;
    cout << "kth smallest no is: " << v[k - 1] << endl;

    return 0;
}