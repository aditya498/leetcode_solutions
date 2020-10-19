void helper(TreeNode* root,TreeNode* &prev,TreeNode* &fN,TreeNode* &sN){
    if(root==NULL)
        return;
    helper(root->left,prev,fN,sN);
    
    if(prev!=NULL && prev->val>root->val){
        if(fN==NULL)
            fN=prev;
        sN=root;
    }
    
    prev=root;
    
    helper(root->right,prev,fN,sN);
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* fN=NULL;
        TreeNode* sN=NULL;
        TreeNode*  prev=NULL;
        helper(root,prev,fN,sN);
        
        int temp=fN->val;
        fN->val=sN->val;
        sN->val=temp;

    }
};