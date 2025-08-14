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

// top view function
vector <int> topView(Node * root){
    vector<int> res;
    if(!root) return res;

    // map: hd-> node value
    map <int, int> topNodes;
    queue <pair<Node* , int>> q;       // Node*, hd

    q.push({root,0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        // first occurance of hd is top view
        if(topNodes.find(hd) == topNodes.end())
            topNodes[hd] = node-> data;

        if(node->left)
            q.push({node->left, hd-1});
        
        if(node->right)
            q.push({node->right, hd+1});
    }
    for(auto &it : topNodes)
        res.push_back(it.second);
    return res;
}