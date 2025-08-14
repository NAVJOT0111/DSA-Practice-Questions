#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// vertical order traversal
vector<vector<int>> verticalTraversal(Node* root){
    // #Map: hd -> level -> minHeap
    // Horizontal Distance (hd): Distance from root's vertical line

    // Root starts at hd = 0
    // Left child: hd - 1, Right child: hd + 1
    map <int, map<int, multiset <int>>> nodes;

    queue<pair<Node*, pair <int, int >>> q;
    // Stores: {Node*, {horizontal_distance, level}}

    q.push({root, {0,0}});      // hd = 0, level = 0

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int hd = p.second.first;        // horizontal distance
        int lvl = p.second.second;      // vertical level

        nodes[hd][lvl].insert(node->data);

        if(node -> left)
            q.push({node -> left, {hd-1, lvl+1}});
        if(node -> right){
            q.push({node -> right, {hd+1, lvl+1}});
        }

        // #ResultCollection
        vector<vector<int>> ans;
        for(auto &hd_pair : nodes){
            vector <int> col;
            for( auto &lvl_pair : hd_pair.second){
                col.insert(col.end(), lvl_pair.second.begin(), lvl_pair.second.end());
            }
            ans.push_back(col);
        }
        // Outer loop: Iterate through horizontal distances (left to right)
        // Inner loop: For each hd, process levels top to bottom
        // Multiset extraction: Add all nodes at same (hd, level) in sorted order
        return ans;
    }
    
    int main() {
    /* Sample Tree:
              3
            /   \
           9     20
                /  \
               15   7
    */
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> ans = verticalTraversal(root);

    cout << "#VerticalOrderTraversal: " << endl;
    for (auto &col : ans) {
        for (int val : col) cout << val << " ";
        cout << endl;
    }
}