class Pair{
public:
    int minV;
    int maxV;
    bool isBST;
};

Pair helper(TreeNode* root) {
    if(root->left==NULL && root->right==NULL){
        Pair ans;
        ans.minV=root->val;
        ans.maxV=root->val;
        ans.isBST=true;
        return ans;
    }
    
    Pair ans;
    ans.isBST= true;
    ans.minV=INT_MAX;
    ans.maxV=INT_MIN;
    if(root->left!=NULL){
        Pair left=helper(root->left);
        if(left.maxV<root->val)
            ans.isBST=true;
        else
            ans.isBST=false;
        ans.isBST=ans.isBST && left.isBST;
        ans.minV=min(root->val,left.minV);
        ans.maxV=max(root->val,left.maxV);
    }
    
    if(root->right!=NULL){
        Pair right=helper(root->right);
        if(right.minV>root->val)
            ans.isBST=ans.isBST;
        else
            ans.isBST= false;
        ans.isBST=ans.isBST && right.isBST;
        ans.minV=min(ans.minV,min(root->val,right.minV));
        ans.maxV=max(ans.maxV,max(root->val,right.maxV));
    }
    return ans;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return helper(root).isBST;
    }
};