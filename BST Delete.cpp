#include <bits/stdc++.h> 
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
BinaryTreeNode<int>* FindMin(BinaryTreeNode<int>* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

BinaryTreeNode<int>* bstDelete(BinaryTreeNode<int>* root, int data ) {
    if(root == NULL) return root; 
	else if(data < root->data) root->left = bstDelete(root->left,data);
	else if (data > root->data) root->right = bstDelete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			BinaryTreeNode<int>*temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			BinaryTreeNode<int>*temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			BinaryTreeNode<int>*temp = FindMin(root->right);
			root->data = temp->data;
			root->right = bstDelete(root->right,temp->data);
		}
	}
	return root;
}


