void helper(TreeNode* root,string &ans){
    if(root==NULL)
        return;
    ans=ans+to_string(root->val);
    if(root->left!=NULL || (root->left==NULL && root->right!=NULL))
        ans=ans+"(";
    if(root->left!=NULL)
        helper(root->left,ans);
    if(root->left!=NULL || (root->left==NULL && root->right!=NULL))
        ans=ans+")";
    if(root->right!=NULL){
        ans=ans+"(";
        helper(root->right,ans);
        ans=ans+")";
    }
}

class Solution {
public:
    string tree2str(TreeNode* t) {
        string ans="";
        helper(t,ans);
        return ans;
    }
};