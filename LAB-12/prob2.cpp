#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool leftThread, rightThread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        leftThread = rightThread = false;
    }
};

void convertToThreaded(Node* root, Node*& prev) {
    if (!root) return;

    convertToThreaded(root->left, prev);

    if (root->left == nullptr) {
        root->left = prev;
        root->leftThread = true;
    }

    if (prev != nullptr && prev->right == nullptr) {
        prev->right = root;
        prev->rightThread = true;
    }

    prev = root;

    if (!root->rightThread) {
        convertToThreaded(root->right, prev);
    }
}

void DoubleThreadedTree(Node* root) {
    Node* prev = nullptr;
    convertToThreaded(root, prev);
}

Node* leftMost(Node* node) {
    if (!node) return nullptr;
    while (node->left != nullptr && !node->leftThread) {
        node = node->left;
    }
    return node;
}

void inorderTraversal(Node* root) {
    Node* curr = leftMost(root);

    while (curr != nullptr) {
        cout << curr->data << " ";

        if (curr->rightThread) {
            curr = curr->right;
        } else {
            curr = leftMost(curr->right);
        }
    }
    cout << endl;
}

int main() {
    
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    DoubleThreadedTree(root);

    cout << "Inorder Traversal: ";
    inorderTraversal(root); 

    return 0;
}