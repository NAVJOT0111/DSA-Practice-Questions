#include <iostream>
#include <stack>
using namespace std;

// Tree Node definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BST Iterator Class
class BSTIterator {
    stack<TreeNode*> st;
    bool forward; // true = next smallest, false = next largest

public:
    BSTIterator(TreeNode* root, bool isForward) {
        forward = isForward;
        pushAll(root);
    }

    // Get the next element depending on traversal direction
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(forward) pushAll(node->right); // inorder: go right after visiting
        else pushAll(node->left);         // reverse inorder: go left after visiting
        return node->val;
    }

    // Check if iterator still has elements
    bool hasNext() {
        return !st.empty();
    }

private:
    // Push all left (for inorder) or all right (for reverse inorder)
    void pushAll(TreeNode* node)  {
        while(node) {
            st.push(node);
            node = forward ? node->left : node->right;
        }
    }
};

// Main Solution Class
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, true);   // Iterator for next smallest
        BSTIterator r(root, false);  // Iterator for next largest

        int i = l.next();  
        int j = r.next();

        // Loop until both pointers meet
        while(i < j) {
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k) {
                if(l.hasNext()) i = l.next(); // move forward (smallest side)
                else break;
            }
            else {
                if(r.hasNext()) j = r.next(); // move backward (largest side)
                else break;
            }
        }
        return false;
    }
};
