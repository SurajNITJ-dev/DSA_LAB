
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

void smallest(Node* root, int k, int& count, int& ans) {
    if (root == NULL) return;

    smallest(root->left, k, count, ans);

    count++;

    if (count == k) {
        ans = root->data;
        return;
    }

    if (count < k)
        smallest(root->right, k, count, ans);
}

void largest(Node* root, int k, int& count, int& ans) {
    if (root == NULL) return;

    largest(root->right, k, count, ans);

    count++;

    if (count == k) {
        ans = root->data;
        return;
    }

    if (count < k)
        largest(root->left, k, count, ans);
}

int main() {
    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k;
    cin >> k;

    int count = 0, small = -1, large = -1;

    smallest(root, k, count, small);

    count = 0;

    largest(root, k, count, large);

    if (small == -1 || large == -1)
        cout << "Invalid K";
    else {
        cout << "Kth Smallest = " << small << endl;
        cout << "Kth Largest = " << large << endl;
    }

    return 0;
}
