// Optimal and easy
/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is number of nodes in binary tree.
*/

int height(BinaryTreeNode<int>* node){

    if(node==NULL) return 0;
    
    int lh=height(node->left);
    int rh=height(node->right);
    if (lh==-1 || rh==-1) return -1;
    if (abs(lh-rh)>1) return -1;
    
    return 1+max(lh,rh);
}

bool isBalancedBT(BinaryTreeNode<int>* root)
{
    return ( height(root) != -1 );
}


// Straight method
#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int height(BinaryTreeNode<int>* node){
    if(node==NULL) return 0;
    int l=height(node->left);
    int r=height(node->right);
    return 1+max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root==NULL) return true;
    int lh=height(root->left);
    int rh=height(root->right);
    
    if (isBalancedBT(root->left) == true  &&
        isBalancedBT(root->right) == true && 
        abs(lh - rh) <= 1) {     
        return true;
    }

    return false;
}