class Solution{
    public:
        int count(TreeNode* root){
            if(root == NULL) return 0;

            int lh = findHeightLeft(root);
            int rh = findHeightRight(root);

            if(lh == rh) return (l << lh) - 1;

            return 1 + count(root -> left) + count(root -> right);
        }

        int findHeightLeft(TreeNode* Node){
            int hght = 0;
            while(node){
                hght++;
                node = node->left;
            }
            return hght;
        }
        int findHeightRight(TreeNode* node){
            int hght = 0;
            while(node){
                hght++;
                node = node-> right;
            }
            return hght;
        }
};

// tc: O(log n)^2
// sc : O(logn)