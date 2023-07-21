#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
/*
    Time Complexity: O(N)
    Space Complexity: O(N)
    
    Where 'N' denotes the number of nodes in the given BST
*/

// Function to store inorder traversal of BST in 'nums'.
void inorder(BinaryTreeNode<int> *root, vector<int> &nums)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root -> left, nums);

    nums.push_back(root -> data);

    inorder(root -> right, nums);
}


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Vector to store the inorder traversal of the BST.
    vector<int> nums;

    inorder(root, nums);

    // Iterating over the nums list using 2 - pointer.
    int i = 0, j = nums.size() - 1;

    // Iterate till 'i' is less than 'j'.
    while (i < j)
    {
        if (nums[i] + nums[j] == k)
        {
            return true;
        }

        // If the sum of elements at index 'i' and 'j' is less than target 'k'.  
        if (nums[i] + nums[j] < k)
        {

            // Increment the left pointer 'i'.
            i = i + 1;
        }

        // If the sum of elements at index 'i' and 'j' is greater than target 'k'. 
        else
        {

            // Decrement the right pointer 'j'.
            j = j - 1;
        }
    }

    return false;
}


