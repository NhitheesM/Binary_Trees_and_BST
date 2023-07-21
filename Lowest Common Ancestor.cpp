//efficient

TreeNode<int>* lca(TreeNode<int>* root, int node1, int node2) {
    if (root == NULL) {
        return NULL;
    }

    // check if root is any of the three nodes
    if (root->data == node1 || root->data == node2 ) {
        return root;
    }

    TreeNode<int>* left = lca(root->left, node1, node2);
    TreeNode<int>* right = lca(root->right, node1, node2);

    // If both subtree return not-Null value it means current node could be LCA
    if (left != NULL && right != NULL) {
        return root;
    }
    // If left subbtree return not-null value then for now return node is LCA
    else if (left != NULL) {

        return left;
    }
    // If right subbtree return not-null value then for now return node is LCA
    else {
        return right;
    }
}
int lowestCommonAncestor(TreeNode<int> *root, int node1, int node2)
{		
	TreeNode<int>* temp=lca(root,node1,node2);
	return temp->data;
}

// Path finding and checking common ancestor

bool getpath(vector<int> &arr,TreeNode<int> *node,int val){
	if(node==NULL){
		return false;
	}
	arr.push_back(node->data);
	if(node->data==val) return true;

	if(getpath(arr,node->left,val)||getpath(arr,node->right,val)) return true;
	arr.pop_back();
	return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{		
	vector<int> xpath;
	vector<int> ypath;
	getpath(xpath,root,x);
	getpath(ypath,root,y);
	int ans = -1; // Initialize ans to a default value indicating no common ancestor.

	for (int i=0; i< min(xpath.size(), ypath.size()); i++)
	{
    	if (xpath[i] != ypath[i])
    	{
        	break;
    	}
    	ans = xpath[i];
	}

	return ans;
}



