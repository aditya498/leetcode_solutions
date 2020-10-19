int helper(TreeNode* root,int num){
    if(root->left==NULL && root->right==NULL){
        num=num*10+root->val;
        return num;
    }
    
    int ans=0;
    if(root->left!=NULL)
        ans+=helper(root->left,num*10+root->val);
    if(root->right!=NULL)
        ans+=helper(root->right,num*10+root->val);
    return ans;
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        return helper(root,0);
    }
};