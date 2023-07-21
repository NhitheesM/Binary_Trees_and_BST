/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
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

***********************************************************/
#include<bits/stdc++.h>
bool isBSTUtil(BinaryTreeNode<int>* node, int minValue, int maxValue) {
    // Base case: an empty tree or leaf node is considered a BST
    if (node == nullptr)
        return true;

    // Check if the current node violates the BST property
    if (node->data < minValue || node->data > maxValue)
        return false;

    // Recursively check the left and right subtrees
    return isBSTUtil(node->left, minValue, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, maxValue);
}

bool isBST(BinaryTreeNode<int>* root) {
    // Call the helper function with initial minimum and maximum values
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

