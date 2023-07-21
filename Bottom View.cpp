
#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL) return ans;

    map<int,int> mp;
    queue<pair<int,TreeNode<int>*>> q;
    q.push({0,root});
    
    while(!q.empty()){
        auto p= q.front();
        q.pop();
        TreeNode<int>* node=p.second;
        int x=p.first;
        mp[x]=node->val;
        
        if(node->left){
            q.push({x-1,node->left});
        }
        if(node->right){
            q.push({x+1,node->right});
        }
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }

}