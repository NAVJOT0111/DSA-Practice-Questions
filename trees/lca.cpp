class Solution {
public:
    TreeNode* lca(TreeNode root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p|| root == q){
            return root;
    }
    TreeNode* left = lca(root->left, p,q);
    TreeNode* right = lca(root-> right, p,q);

    // result
    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root;
    }
    }
};