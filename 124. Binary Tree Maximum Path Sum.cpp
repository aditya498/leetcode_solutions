class Pair{
public:
    int diaSum;
    int heiSum;
};

Pair helper(TreeNode* root){
    if(root->left==NULL && root->right==NULL){
        Pair ans;
        ans.heiSum=root->val;
        ans.diaSum=root->val;
        return ans;
    }

    Pair left;
    if(root->left!=NULL)
        left=helper(root->left);
    Pair right;
    if(root->right!=NULL)
        right=helper(root->right);

    Pair ans;
    ans.diaSum=root->val;
    ans.heiSum=INT_MIN;
    if(root->left!=NULL && root->right!=NULL){
        ans.diaSum=max(ans.diaSum,root->val+left.heiSum+right.heiSum);
    }
    if(root->left!=NULL){
        ans.diaSum=max(ans.diaSum,max(left.diaSum,max(left.heiSum,root->val+left.heiSum)));
        if(left.heiSum>0)
            ans.heiSum=root->val+left.heiSum;
        else
            ans.heiSum=root->val;
    }
    if(root->right!=NULL){
        ans.diaSum=max(ans.diaSum,max(right.diaSum,max(right.heiSum,root->val+right.heiSum)));
        if(right.heiSum>0)
            ans.heiSum=max(ans.heiSum,root->val+right.heiSum);
        else
            ans.heiSum=max(ans.heiSum,root->val);
    }
    return ans;
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return helper(root).diaSum;
    }
};