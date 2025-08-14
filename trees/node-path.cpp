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

// DFS function : Recursively searches the target node while building the path.
bool path(Node* root, vector <int> &path, int target){
    if(!root) return false;     // "If there’s no tree here, I can’t find the target — stop searching in this direction."

    // add current node to branch
    path.push_back(root->data);

    // if current node is the target node
    if(root-> data == target)
        return true;

    // search in left/right subtree
    if((root->left && path(root->left, path, target)) || (root->right && path(root->right, path, target)))
        return true;

    // if not found, remove the current element from the branch 
    path.pop_back();
    return false;
}

vector <int> rootToNodePath(Node* root, int target){
    vector <int> path;
    path(root, path, target);
    return path;
}

//Backtracking → Removes a node from the path if that branch doesn’t lead to the target.