#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Step 1: Map each node to its parent
void markParents(Node* root, unordered_map<Node*, Node*>& parent) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* cur = q.front(); q.pop();
        if(cur->left) {
            parent[cur->left] = cur;
            q.push(cur->left);
        }
        if(cur->right) {
            parent[cur->right] = cur;
            q.push(cur->right);
        }
    }
}

// Step 2: BFS from target to find nodes at distance K
vector<int> distanceK(Node* root, Node* target, int K) {
    unordered_map<Node*, Node*> parent;
    markParents(root, parent);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int dist = 0;

    while(!q.empty()) {
        int size = q.size();
        if(dist == K) break;
        dist++;
        for(int i=0; i<size; i++) {
            Node* cur = q.front(); q.pop();

            // Go left
            if(cur->left && !visited[cur->left]) {
                q.push(cur->left);
                visited[cur->left] = true;
            }
            // Go right
            if(cur->right && !visited[cur->right]) {
                q.push(cur->right);
                visited[cur->right] = true;
            }
            // Go to parent
            if(parent[cur] && !visited[parent[cur]]) {
                q.push(parent[cur]);
                visited[parent[cur]] = true;
            }
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

// Example usage
int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    vector<int> result = distanceK(root, root->left, 2); // Target = 5, K=2
    for(int x : result) cout << x << " ";
}
