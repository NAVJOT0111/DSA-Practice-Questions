#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *first, *second, *prev;    // declaring members
    
public:
    Solution() {
        first = second = prev = nullptr;
    }

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);

        // Detect swapped nodes
        if(prev && prev->val > root->val) {
            if(!first) first = prev;   // first violation
            second = root;             // second violation (or adjacent case)
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && second) {
            swap(first->val, second->val);
        }
    }
};
