
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* root, vector<int>& a) {
    if (root == NULL) return;

    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}

int kthSmallest(vector<int>& a, int k) {
    if (k < 1 || k > a.size())
        return -1;

    return a[k - 1];
}

int main() {
    Node* root = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    vector<int> a;
    inorder(root, a);

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        cout << kthSmallest(a, k) << endl;
    }

    return 0;
}
