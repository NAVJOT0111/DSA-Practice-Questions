#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct NodeValue {
    int minNode, maxNode, maxSize;
    bool isBST;

    NodeValue(int minNode, int maxNode, int maxSize, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        this->isBST = isBST;
    }
};

class Solution {
public:
    NodeValue solve(TreeNode* root) {
        if(!root) {
            // For null node → min=+∞, max=-∞, size=0, isBST=true
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        // If current subtree is BST
        if(left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            return NodeValue(
                min(root->val, left.minNode),   // min value in subtree
                max(root->val, right.maxNode), // max value in subtree
                left.maxSize + right.maxSize + 1, // size of this BST
                true
            );
        }

        // If not BST, return size of largest BST seen so far
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize), false);
    }

    int largestBSTSubtree(TreeNode* root) {
        return solve(root).maxSize;
    }
};
