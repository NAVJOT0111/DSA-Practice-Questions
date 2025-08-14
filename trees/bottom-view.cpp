vector <int> bottomView(Node *root){
    vector <int> ans;

    if(root == NULL) return ans;

    map <int, int> mpp;     // mpp maps horizontal distance (line) → node value.


    queue <pair<Node* , int>> q;    //BFS queue storing {Node pointer, horizontal distance}.
    q.push({root,0});       // Start BFS with root node at horizontal distance = 0.


    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;      // node pointer
        int line = it.second;       // horizontal distance
        mpp[line] = node->data;

// Because BFS is level-order, the last node encountered at a given HD will be the bottommost one.

        if(node -> left != NULL){
            // If a left child exists, push it to the queue with HD - 1.

            q.push({node -> left, line-1});
        }
        if(node -> right != NULL){
            q.push({node-> right, line+1});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}