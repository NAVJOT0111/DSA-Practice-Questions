// morris traversal iinorder

vector <int> getInorder(TreeNode* root){
    vector <int> inorder;
    TreeNode *cur = root;
    while(curr != NULL){
        if(cur -> left == NULL){        // case 1
            inorder.push_back(cur -> val);
            cur = cur-> right;
        }
        else{
            TreeNode* prev = cur -> left;
            while(prev -> right && prev -> right != cur){   // move to the rightmost element of the left node that doesn't points himself
                prev = prev -> right;       // create a thread
            }

            if(prev -> right == NULL){
                prev -> right = cur;
                cur = cur -> left;
            }
            else{
                prev -> right = NULL;
                inorder.push_back(cur.val);  // change only this line to make it preorder
                cur = cur -> right;
            }
        }
    }
    return inorder;
}