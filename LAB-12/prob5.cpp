
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int x) {
        data = x;
        left = right = NULL;
        lthread = rthread = false;
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

void convert(Node* root, Node*& prev) {
    if (root == NULL) return;

    if (root->left)
        convert(root->left, prev);

    if (root->left == NULL) {
        root->left = prev;
        root->lthread = true;
    }

    if (prev != NULL && prev->right == NULL) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    if (root->right && !root->rthread)
        convert(root->right, prev);
}

Node* leftMost(Node* p) {
    while (p && !p->lthread)
        p = p->left;

    return p;
}

Node* rightMost(Node* p) {
    while (p && !p->rthread)
        p = p->right;

    return p;
}

Node* successor(Node* p) {
    if (p->rthread)
        return p->right;

    return leftMost(p->right);
}

Node* predecessor(Node* p) {
    if (p->lthread)
        return p->left;

    return rightMost(p->left);
}

Node* search(Node* root, int x) {
    Node* p = root;

    while (p != NULL) {
        if (p->data == x)
            return p;

        if (x < p->data) {
            if (p->lthread) return NULL;
            p = p->left;
        }
        else {
            if (p->rthread) return NULL;
            p = p->right;
        }
    }

    return NULL;
}

Node* lowerBound(Node* root, int x) {
    Node* p = root;
    Node* ans = NULL;

    while (p != NULL) {
        if (p->data >= x) {
            ans = p;

            if (p->lthread) break;

            p = p->left;
        }
        else {
            if (p->rthread) break;

            p = p->right;
        }
    }

    return ans;
}

void rangeQuery(Node* root, int l, int r) {
    Node* p = lowerBound(root, l);

    cout << "RANGE = [";

    bool first = true;

    while (p != NULL && p->data <= r) {
        if (!first) cout << ", ";

        cout << p->data;
        first = false;

        p = successor(p);
    }

    cout << "]" << endl;
}

void kthSmallest(Node* root, int k) {
    Node* p = leftMost(root);

    for (int i = 1; i < k && p != NULL; i++)
        p = successor(p);

    if (p == NULL || k <= 0)
        cout << "KTH = NULL" << endl;
    else
        cout << "KTH = " << p->data << endl;
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

    Node* prev = NULL;
    convert(root, prev);

    int q;
    cin >> q;

    while (q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "NEXT") {
            int x;
            cin >> x;

            Node* p = search(root, x);
            Node* ans = p ? successor(p) : NULL;

            if (ans)
                cout << "NEXT = " << ans->data << endl;
            else
                cout << "NEXT = NULL" << endl;
        }

        else if (cmd == "PREV") {
            int x;
            cin >> x;

            Node* p = search(root, x);
            Node* ans = p ? predecessor(p) : NULL;

            if (ans)
                cout << "PREV = " << ans->data << endl;
            else
                cout << "PREV = NULL" << endl;
        }

        else if (cmd == "RANGE") {
            int l, r;
            cin >> l >> r;

            rangeQuery(root, l, r);
        }

        else if (cmd == "KTH") {
            int k;
            cin >> k;

            kthSmallest(root, k);
        }
    }

    return 0;
}
