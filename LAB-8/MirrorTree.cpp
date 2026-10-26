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

struct Item {
    TreeNode* node;
    int row, lo, hi;
};

bool checkMirrorTree(TreeNode* root) {
    if (root == nullptr) return true;

    queue<pair<TreeNode*, TreeNode*> > q;
    q.push(make_pair(root->left, root->right));

    while (!q.empty()) {
        TreeNode* a = q.front().first;
        TreeNode* b = q.front().second;
        q.pop();

        if (a == nullptr && b == nullptr) continue;
        if (a == nullptr || b == nullptr) return false;
        if (a->val != b->val) return false;

        q.push(make_pair(a->left, b->right));
        q.push(make_pair(a->right, b->left));
    }
    return true;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "(empty tree)\n";
        return;
    }

    int h = 0;
    queue<TreeNode*> lq;
    lq.push(root);
    while (!lq.empty()) {
        int sz = lq.size();
        h++;
        while (sz--) {
            TreeNode* t = lq.front();
            lq.pop();
            if (t->left) lq.push(t->left);
            if (t->right) lq.push(t->right);
        }
    }

    int width = (1 << h) - 1;
    vector<vector<int> > grid(h, vector<int>(width, INT_MIN));

    queue<Item> q;
    Item start = {root, 0, 0, width - 1};
    q.push(start);

    while (!q.empty()) {
        Item cur = q.front();
        q.pop();

        int mid = (cur.lo + cur.hi) / 2;
        grid[cur.row][mid] = cur.node->val;

        if (cur.node->left) {
            Item l = {cur.node->left, cur.row + 1, cur.lo, mid - 1};
            q.push(l);
        }
        if (cur.node->right) {
            Item r = {cur.node->right, cur.row + 1, mid + 1, cur.hi};
            q.push(r);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == INT_MIN) cout << "   ";
            else cout << setw(3) << grid[i][j];
        }
        cout << "\n";
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

    cout << "Tree 1:\n\n";
    printTree(root);
    cout << "\nResult: " << (checkMirrorTree(root) ? "Mirror" : "Not a mirror") << "\n\n";

    TreeNode* root2 = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(2);
    root2->left = a;
    root2->right = b;
    a->left = new TreeNode(3);
    a->right = new TreeNode(4);
    b->left = new TreeNode(4);
    b->right = new TreeNode(3);

    cout << "Tree 2:\n\n";
    printTree(root2);
    cout << "\nResult: " << (checkMirrorTree(root2) ? "Mirror" : "Not a mirror") << "\n";

    return 0;
}