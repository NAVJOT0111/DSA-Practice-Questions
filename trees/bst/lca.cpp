class Solution{
    public TreeNode lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL:
        int cur = root->val;
        if(cur < p->val && cur < q->val){
            return lca(root -> right, p, q);
        }
        if(cur > p->val && cur > q->val){
            return lca(root->left, p, q);
        }
        return root;
    }
};