
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& a) {
    if (a.empty() || a[0] == -1) return NULL;

    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < a.size()) {
        Node* p = q.front();
        q.pop();

        if (a[i] != -1) {
            p->left = new Node(a[i]);
            q.push(p->left);
        }
        i++;

        if (i < a.size() && a[i] != -1) {
            p->right = new Node(a[i]);
            q.push(p->right);
        }
        i++;
    }

    return root;
}

void setParent(Node* root, Node* parent,
               unordered_map<Node*, Node*>& mp,
               unordered_map<int, Node*>& nodes) {
    if (!root) return;

    mp[root] = parent;
    nodes[root->val] = root;

    setParent(root->left, root, mp, nodes);
    setParent(root->right, root, mp, nodes);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s, k;
    cin >> s >> k;

    Node* root = buildTree(a);

    unordered_map<Node*, Node*> parent;
    unordered_map<int, Node*> nodes;

    setParent(root, NULL, parent, nodes);

    Node* target = nodes[s];

    queue<Node*> q;
    unordered_map<Node*, bool> visited;

    q.push(target);
    visited[target] = true;

    int level = 0;

    while (!q.empty()) {
        int size = q.size();

        if (level == k) {
            while (size--) {
                cout << q.front()->val << " ";
                q.pop();
            }
            break;
        }

        while (size--) {
            Node* p = q.front();
            q.pop();

            if (p->left && !visited[p->left]) {
                q.push(p->left);
                visited[p->left] = true;
            }

            if (p->right && !visited[p->right]) {
                q.push(p->right);
                visited[p->right] = true;
            }

            if (parent[p] && !visited[parent[p]]) {
                q.push(parent[p]);
                visited[parent[p]] = true;
            }
        }

        level++;
    }

    return 0;
}
