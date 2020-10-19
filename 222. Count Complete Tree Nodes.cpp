int leftHeight(TreeNode* root){
    if(root==NULL)
        return 0;
    return 1+leftHeight(root->left);
}

int rightHeight(TreeNode* root){
    if(root==NULL)
        return 0;
    return 1+rightHeight(root->right);
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int l=leftHeight(root);
        int r=rightHeight(root);
        if(l==r)
            return pow(2,l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
