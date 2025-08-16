class BSTiterator{
private:   stack <TreeNode *> myStack;
public:
    BSTiterator(TreeNode *root){
        pushAll(root);
    }

    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode -> right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node){
        for( ; node != NULL; myStack.push(node), node = node-> left);
    }
};