#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<pair<TreeNode<int> *, pair<int, int>>> que;
    map<int, map<int, vector<int>>> mp;  
    // Can use multiset instead of vector if no order is required
    								    
	que.emplace(root, make_pair(0, 0)); 
    //emplace is used as we directly constructed pairs inside.
                                   
    while (!que.empty())
    {
        auto p = que.front();
        que.pop();
        TreeNode<int> *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        mp[x][y].push_back(node->data);
        if (node->left)
        {
            que.emplace(node->left, make_pair(x - 1, y + 1));
        }
        if (node->right)
        {
            que.emplace(node->right, make_pair(x + 1, y + 1));
        }
    }
     for (auto i : mp)
    {
        for (auto j : i.second)
        {
            ans.insert(ans.end(), j.second.begin(), j.second.end());
        }
    }
    return ans;
}