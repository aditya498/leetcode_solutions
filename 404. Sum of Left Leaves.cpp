int helper(TreeNode* root,bool dir){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL && dir)
        return root->val;
    return helper(root->left,true)+helper(root->right, false);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }
};