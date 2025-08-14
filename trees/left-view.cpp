#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector <int> leftView(Node *root){
    vector <int> ans;
    if(!root)  return ans;

    queue <Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();   // levelsize
        for(int i =0; i<n; i++){
            Node* node = q.front();
            q.pop();

         // First node at this level = left view
         if(i == 0) ans.push_back(node -> data);

         if(node -> left) q.push(node->left);
         if(node->right) q.push(node-> right);
        }
    }
    return ans;
}

// #LeftViewFunction → Main logic for computing left view.

// #LevelSize → Keeps track of how many nodes are at the current BFS level.

// Left View Rule → At each level, the first node visited in BFS is part of the left view

