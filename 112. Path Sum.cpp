bool helper(TreeNode* root, int sum) {
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL)
        return sum-root->val==0;
    return helper(root->left,sum-root->val) || helper(root->right,sum-root->val);
}


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        return helper(root,sum);
    }
};
