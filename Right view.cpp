// Just use a variable to store last integer in every level.

vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int level;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            level=node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}