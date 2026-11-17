
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    return (a->data == b->data &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isMirror(root, root))
        cout << "Symmetric";
    else
        cout << "Not Symmetric";

    return 0;
}
