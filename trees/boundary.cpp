#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node (int val){
        data = val;
        left = right = NULL;
    }
};

// left boundary
void leftBoundary(Node* root, vector <int> &res){
    Node* curr =  root -> left;         // Start from root's left child
    while(curr){
        if(curr -> left || curr -> right)       //exclude leaves ( Only adds nodes that have at least one child)
            res.push_back(curr -> data);
        if(curr -> left) curr = curr -> left;       // Prefer left child if it exists (maintains left boundary)
        else curr = curr -> right;
    }
}

// leafnodes
void leafNodes(Node* root, vector <int> &res){
    if(!root) return;
    if(!root -> left && !root -> right){        //!root->left && !root->right is true only for leaf nodes
        res.push_back(root -> data);
        return;
    }
    leafNodes(root -> left, res);  // Recurse left subtree first
    leafNodes(root -> right, res);
}

// right boundary
void rightBoundary(Node* root, vector <int> &res){
    vector <int> temp;
    Node* curr = root -> right;
    while(curr){
        if(curr->left || curr->right)        // exclude leaves
            temp.push_back(curr-> data);
        if(curr->right) curr = curr-> right;
        else curr = curr -> left;
    }
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

// BoundaryTraversal main function
vector <int> boundaryTraversal(Node* root){
    vector <int> res;
    if(!root) return res;

    res.push_back(root ->data);     // root is always part of boundary

    // Left boundary
    leftBoundary(root, res);

    // Leaf nodes
    leafNodes(root->left, res);   // Left subtree leaves
    leafNodes(root->right, res);  // Right subtree leaves
    // This maintains left-to-right leaf ordering across the entire tree

    // Right boundary
    rightBoundary(root, res);
      return res;
}

int main() {
    /* Sample Tree:
              1
            /   \
           2      3
          / \    / \
         4   5  6   7
            / \
           8   9
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> ans = boundaryTraversal(root);

    cout << "#BoundaryTraversal: ";
    for (int val : ans) cout << val << " ";
    cout << endl;
}