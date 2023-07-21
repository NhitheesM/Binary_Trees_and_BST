
// working 

#include<bits/stdc++.h>
TreeNode<int>* treeBuilder(int inStart,int inEnd,vector<int>& inorder,
               int postStart,int postEnd,vector<int>& postorder,unordered_map<int,int> &inmap){
     
     if(postStart>postEnd || inStart>inEnd) return NULL;
     TreeNode<int>* node=new TreeNode<int>(postorder[postEnd]);
     int index=inmap[node->data];
     int numb=index-inStart;
     node->left=treeBuilder(inStart,index-1,inorder,postStart,postStart+numb-1,postorder,inmap);
     node->right=treeBuilder(index+1,inEnd,inorder,postStart+numb,postEnd-1,postorder,inmap);
     return node;
     }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{    
     
	unordered_map<int,int> inmap;
     for(int i=0 ; i<inOrder.size();i++){
          inmap[inOrder[i]]=i;
     }
     return treeBuilder(0,inOrder.size()-1,inOrder,
                         0,postOrder.size()-1,postOrder,inmap);
}