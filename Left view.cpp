// Just use a variable to store 1st integer in every level.

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int level=-1;
        for(int i=0;i<size;i++){
            TreeNode<int>* node=q.front();
            q.pop();
            if (level==-1) level=node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}