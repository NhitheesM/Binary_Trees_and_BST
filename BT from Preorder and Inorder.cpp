
// working 

#include<bits/stdc++.h>
TreeNode<int>* treeBuilder(int inStart, int preStart, int inEnd, int preEnd,
                            vector<int>& inorder, vector<int>& preorder, unordered_map<int,int>& inmap) {

    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    TreeNode<int>* node = new TreeNode<int>(preorder[preStart]);
    int index = inmap[node->data];
    int numsLeft = index - inStart;

    node->left = treeBuilder(inStart, preStart + 1, index - 1, preStart + numsLeft, inorder, preorder, inmap);
    node->right = treeBuilder(index + 1, preStart + numsLeft + 1, inEnd, preEnd, inorder, preorder, inmap);

    return node;
}

TreeNode<int>* buildBinaryTree(vector<int>& inorder, vector<int>& preorder) {
    unordered_map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++) {
        inmap[inorder[i]] = i;
    }

    return treeBuilder(0, 0, inorder.size() - 1, preorder.size() - 1, inorder, preorder, inmap);
}
