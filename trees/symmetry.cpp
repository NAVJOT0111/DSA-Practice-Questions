bool symmetric(TreeNode* root){
    return root ==NULL || issymm(root->left, root->right);
}

bool issym(TreeNode* left, TreeNode* right){
    if(left == null || right == null)
        return left == right;

    if(left.val != right.val) return false;

    return issym(left.left, right.right) && issym(left.right, right.left);
}