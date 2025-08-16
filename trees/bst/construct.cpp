class Solution{
public:
    TreeNode* bst(vector <int>& A){
        int i = 0;
        return build(A,i,__INT_MAX__);
    }
    TreeNode* build(vector<int>& A, int& i, int bound){
        if(i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root -> left = build(A,i, root-> val);
        root -> right = build(A,i,bound);
        return root;
    }
};