#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int maxTraversal(TreeNode<int> *node){
    if(node==NULL) return 0;
    int lh=maxTraversal(node->left);
    int rh=maxTraversal(node->right);
    return 1+max(lh,rh);
}
int maxDepth(TreeNode<int> *root) {
    int height=maxTraversal(root)-1;
    return height;
}