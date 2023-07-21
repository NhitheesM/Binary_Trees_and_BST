
// Level order traversal with changing direction.
vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int dir=0;
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        if(dir==1){
            reverse(level.begin(),level.end());
        }
        dir=1-dir;
        ans.insert(ans.end(),level.begin(),level.end());
    }

    return ans;
}

