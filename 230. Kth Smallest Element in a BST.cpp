void helper(TreeNode* root,int &k,bool &found,int &ans){
    if(root==NULL)
        return;
    if(!found)
        helper(root->left,k,found,ans);
    if(k==1 && !found){
        found=true;
        ans=root->val;
        return;
    }
    k=k-1;
    if(!found)
        helper(root->right,k,found,ans);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int temp=k;
        bool found=false;
        int ans=0;
        helper(root,temp,found,ans);
        return ans;
    }
};