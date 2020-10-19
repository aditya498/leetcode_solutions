int helper(TreeNode* root){
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return 1+min(helper(root->left),helper(root->right));
}

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return helper(root);
    }
};