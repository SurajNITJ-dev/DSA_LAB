
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left),
                   minDepth(root->right));
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    cout << "Minimum Depth = " << minDepth(root);

    return 0;
}
