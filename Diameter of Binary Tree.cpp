/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int>* node, int &dmeter){
    if(node==NULL) return 0;

    int lh=height(node->left,dmeter);
    int rh=height(node->right,dmeter);
    dmeter=max(dmeter,lh+rh);
    return 1+max(lh,rh);

}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter=0;
    height(root,diameter);
    return diameter;
}



